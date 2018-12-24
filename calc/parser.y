%{
#include <stdio.h>
#include <stdlib.h>
#include "FilePrintStream.h"
#include "BaseExpr.h"
#include "ParserStatus.h"
static IPrintStream* get_dumper(){
   static IPrintStream* ret = NULL;
   if(ret == NULL){
       ret=iprintstream_from_file(stdout);
   }
   return ret;
}
#define YYPARSE_PARAM_TYPE Document*
#define YYPARSE_PARAM parserStatus
#if defined(DEBUG) && DEBUG==1
#define DebugOut(x) x
#else
#define DebugOut(...) 
#endif
%}

%start program
%union{
   YYParamTypeCtx Ctx;
}

%right OP_ASSIGN 
%left OP_ADD OP_MINUS
%left OP_MUL OP_DIV OP_MOD
%nonassoc U_MINUS U_PLUS
%token DIGIT SYMBOL NEWLINE

%%
program: statements { YYPARSE_PARAM->children=$1.Ctx.expr; };

statements: statement { 
           vector_push_back( YYPARSE_PARAM->flattenStatements, $1.Ctx.expr);
           YYPARSE_PARAM->children=$1.Ctx.expr;
           $$.Ctx.expr=$1.Ctx.expr;
        }
	| statements statement {
           expr_add_arguments($1.Ctx.expr,1,$2.Ctx.expr);
           vector_push_back( YYPARSE_PARAM->flattenStatements, $1.Ctx.expr);
           $$.Ctx.expr=$1.Ctx.expr;
        }
	| statements error newline{
           $$.Ctx.expr=$1.Ctx.expr;
        }

newline: NEWLINE
	| newline NEWLINE
	;

statement: expr { DebugOut(expr_print($1.Ctx.expr,get_dumper())); DebugOut(iprintstream_write(get_dumper(),"\n",1)); }| statement newline;

expr :expr OP_ASSIGN expr
        {
          $$.Ctx.expr = expr_new_with(EXPR_OP_ASSIGN,"=",2, $1.Ctx.expr,$3.Ctx.expr);
          $$.Ctx.expr->Line = $1.Ctx.line;
        }  
      |expr OP_ADD expr
      {
         $$.Ctx.expr = expr_new_with(EXPR_OP_ADD,"+",2, $1.Ctx.expr,$3.Ctx.expr);
         $$.Ctx.expr->Line = $1.Ctx.expr->Line;
      }
      | expr OP_MINUS expr
       {
         $$.Ctx.expr = expr_new_with(EXPR_OP_SUB,"-",2, $1.Ctx.expr,$3.Ctx.expr);
         $$.Ctx.expr->Line = $1.Ctx.expr->Line;
       }
      | expr OP_MUL expr
       {
         $$.Ctx.expr = expr_new_with(EXPR_OP_MUL,"*",2, $1.Ctx.expr,$3.Ctx.expr);
         $$.Ctx.expr->Line = $1.Ctx.expr->Line;
       }
       | expr OP_DIV expr
        {
         $$.Ctx.expr = expr_new_with(EXPR_OP_MUL,"*",2, $1.Ctx.expr,$3.Ctx.expr);
         $$.Ctx.expr->Line = $1.Ctx.expr->Line;
       }
	| OP_MINUS expr %prec U_MINUS
       {
         $$.Ctx.expr = expr_new_with(EXPR_OP_NEGATIVE,"-",1, $2.Ctx.expr);
         $$.Ctx.expr->Line = $1.Ctx.line;
       }
        | digit | symbol
	;

digit: DIGIT { 
         $$.Ctx.expr = expr_new_digit($1.Ctx.intVal);
         $$.Ctx.expr->Line = $1.Ctx.line;
         $$.Ctx.expr->Col = $1.Ctx.col;
     }
     | digit newline { $$.Ctx.expr=$1.Ctx.expr; }
     ;
symbol: SYMBOL { 
         $$.Ctx.expr = expr_new_symbol($1.Ctx.stringVal);
         $$.Ctx.expr->Line = $1.Ctx.line;
         $$.Ctx.expr->Col = $1.Ctx.col;
     }
     | symbol newline { $$.Ctx.expr=$1.Ctx.expr; }

     ;


%%
int main(int argc,char** argv){
   int ret = 0;
   int size = 0;
   int i;
   FILE* fp= NULL;
   Document doc;
   doc.children=NULL;
   doc.flattenStatements=vector_create(0);
   if(argc > 1){
      fp = fopen(argv[1],"rb");
      if(fp ) { 
         extern FILE* yyin;
         yyin=fp;
      }
   }
   ret =  yyparse(&doc);
   size = vector_size(doc.flattenStatements);
   for(int i=0; i<size; ++i){
      Expr* expr = (Expr*)vector_at(doc.flattenStatements,i);
      expr_print(expr,get_dumper());
   }
   expr_destroy(doc.children);
   return ret;
}
void yyerror(char* s){
   fprintf(stderr,"%s\n",s);
}
int yywrap(){
   return 1;
}
