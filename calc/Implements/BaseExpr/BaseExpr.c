#include "BaseExpr.h"
#include "FilePrintStream.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
static const char* OP_STR[]={
"",
"EXPR_OP_DIGIT",
"EXPR_OP_SYMBOL",
"EXPR_OP_ADD",
"EXPR_OP_SUB",
"EXPR_OP_MUL",
"EXPR_OP_DIV",
"EXPR_OP_MOD",
"EXPR_OP_ASSIGN",
"EXPR_OP_NEGATIVE",
"EXPR_OP_POSSITIVE"
};
static IPrintStream* get_dumper(){
   static IPrintStream* ret = NULL;
   if(ret == NULL){
       ret=iprintstream_from_file(stdout);
   }
   return ret;
}
static void impl_dump(const IBaseObject* pthis, IPrintStream* stream){
   char* buf = (char*)malloc(4096);
   Expr* expr = (Expr*)pthis;
   snprintf(buf,4096,"%s \"%s\"",OP_STR[expr->OP],expr->expv);
   iprintstream_write(stream, buf, strlen(buf));
   free(buf);
   if(expr->children != NULL){
      Expr* child = NULL;
      int i;
      int size = vector_size(expr->children);
      iprintstream_write(stream, "(", 1);
      for(i=0; i<size; ++i){
         impl_dump((IBaseObject*)vector_at(expr->children,i),stream);
         iprintstream_write(stream," ",1);
      }
      iprintstream_write(stream, ")", 1);
   }
}
static void init_ibaseobject(IBaseObject* obj){
   obj->dump=impl_dump;
}
Expr* expr_new_digit(int val){
   Expr* ret=NULL;
   char digit[12]="";
   snprintf(digit,12,"%d",val);
   ret=expr_new(EXPR_OP_DIGIT,digit);
   return ret;
}
Expr* expr_new_symbol(const char* sym){
   Expr* ret = NULL;
   ret = expr_new(EXPR_OP_SYMBOL,sym);
   return ret;
}
Expr* expr_new(int op,const char* expv){
   Expr* ret = NULL;
   ret = (Expr*)malloc(sizeof(Expr));
   memset(ret,0,sizeof(Expr));
   init_ibaseobject((IBaseObject*)ret);
   ret->OP = op;
   if(expv!=NULL) ret->expv = strdup(expv);
   return ret;
}
static Expr* expr_add_argumentsV(Expr* to,int cnt,va_list ap){
   int i;
   if(to->children == NULL){
      to->children = vector_create(0);
   }
   for(i=0; i<cnt; ++i)
   {
      vector_push_back(to->children, va_arg(ap,Expr*));
   }
   return to;
}
Expr* expr_add_arguments(Expr* to,int cnt,...){
   va_list ap;
   va_start(ap,cnt);
   expr_add_argumentsV(to,cnt,ap);
   va_end(ap);
   return to;
}
Expr* expr_new_with(int op,const char* expv,int cnt,...){
   Expr* ret = expr_new(op,expv);
   va_list ap;
   va_start(ap,cnt);
   expr_add_argumentsV(ret,cnt,ap);
   va_end(ap);
   return ret;
}
void  expr_destroy(Expr* expr){
   if(expr == NULL) return;
   if(expr->expv)
   {
      free(expr->expv);
      expr->expv = NULL;
   }
   if(expr->children != NULL)
   {
      Expr* child;
      int i;
      int size = vector_size(expr->children);
      for(i=0; i<size; ++i)
      {
         Expr* child = (Expr*)vector_at(expr->children,i);
         expr_destroy(child);
      }
      vector_delete(expr->children);
      expr->children = NULL;
   }
   free(expr);
}
void  expr_print(const Expr* expr, IPrintStream* stream)
{
   baseobject_dump((IBaseObject*)expr,stream);  
   iprintstream_write(stream,"\n",1);
}

