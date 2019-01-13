%{
#include <stdio.h>
#include <stdlib.h>
#include "FilePrintStream.h"
#include "BaseExpr.h"
#include "ParserStatus.h"
#define DEBUG 1
void yyerror(Document*,char* s);

static IPrintStream* get_dumper(){
   static IPrintStream* ret = NULL;
   if(ret == NULL){
       ret=iprintstream_from_file(stdout);
   }
   return ret;
}

#if defined(DEBUG) && DEBUG==1
#define DebugOut(x) x
#else
#define DebugOut(...) 
#endif
%}
%parse-param {Document* parserStatus}
%lex-param {Document* parserStatus}
%define api.pure full

%start program


%union{
   Document doc;
   YYParamTypeCtx Ctx;
}

%type<doc> program 
%type<Ctx> statements statement expr symbol digit 
%right<Ctx> OP_ASSIGN 
%left<Ctx> OP_ADD OP_MINUS
%left<Ctx> OP_MUL OP_DIV OP_MOD
%nonassoc<Ctx> U_MINUS U_PLUS
%token<Ctx> DIGIT SYMBOL NEWLINE

%%
program: statements { parserStatus->children=$1.expr; };

statements: statement { 
           vector_push_back( parserStatus->flattenStatements, $1.expr);
           parserStatus->children=$1.expr;
           $$.expr=$1.expr;
        }
	| statements statement {
           vector_push_back( parserStatus->flattenStatements, $2.expr);
           $$.expr=$1.expr;
        }
	| statements error newline{
           $$.expr=$1.expr;
        }

newline: NEWLINE
	| newline NEWLINE
	;

statement: expr { DebugOut(expr_print($1.expr,get_dumper())); DebugOut(iprintstream_write(get_dumper(),"\n",1)); }| statement newline;

expr :expr OP_ASSIGN expr
        {
          $$.expr = expr_new_with(EXPR_OP_ASSIGN,"=",2, $1.expr,$3.expr);
          $$.expr->Line = $1.line;
        }  
      |expr OP_ADD expr
      {
         $$.expr = expr_new_with(EXPR_OP_ADD,"+",2, $1.expr,$3.expr);
         $$.expr->Line = $1.expr->Line;
      }
      | expr OP_MINUS expr
       {
         $$.expr = expr_new_with(EXPR_OP_SUB,"-",2, $1.expr,$3.expr);
         $$.expr->Line = $1.expr->Line;
       }
      | expr OP_MUL expr
       {
         $$.expr = expr_new_with(EXPR_OP_MUL,"*",2, $1.expr,$3.expr);
         $$.expr->Line = $1.expr->Line;
       }
       | expr OP_DIV expr
        {
         $$.expr = expr_new_with(EXPR_OP_MUL,"*",2, $1.expr,$3.expr);
         $$.expr->Line = $1.expr->Line;
       }
	| OP_MINUS expr %prec U_MINUS
       {
         $$.expr = expr_new_with(EXPR_OP_NEGATIVE,"-",1, $2.expr);
         $$.expr->Line = $1.line;
       }
        | digit | symbol
	;

digit: DIGIT { 
         $$.expr = expr_new_digit($1.intVal);
         $$.expr->Line = $1.line;
         $$.expr->Col = $1.col;
     }
     | digit newline { $$.expr=$1.expr; }
     ;
symbol: SYMBOL { 
         $$.expr = expr_new_symbol($1.stringVal);
         $$.expr->Line = $1.line;
         $$.expr->Col = $1.col;
     }
     | symbol newline { $$.expr=$1.expr; }

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
