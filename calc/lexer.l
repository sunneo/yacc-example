%{
#include "BaseExpr.h"
#include "ParserStatus.h"
#include "y.tab.h"
#include <stdarg.h>
#include <stdio.h>
#define DEBUG 1

static int yyline=1;
static int yycol;
static void __debugOut(const char* fmt,...){
#if defined(DEBUG) && DEBUG==1
   va_list ap;
   va_start(ap,fmt);
   fprintf(stderr,"[%d:%d] ",yyline,yycol);
   vfprintf(stderr,fmt,ap);
   va_end(ap);
#endif
#define YY_USER_INIT \
	yyline=1;

#define YY_USER_ACTION \
	yycol+=yyleng;\
	if(yytext[yyleng-1]=='\n') { yycol=0; ++yyline; }
#define yylvalctx yylval->Ctx
}
#if defined(DEBUG) && DEBUG==1
#  define debugOut __debugOut
#else
#  define debugOut(...) 
#endif
%}
%option bison-bridge

%%
[ \t]	{          debugOut("SPACE '%s'\n",yytext); } 
"\n"|"\r\n" {        debugOut("NEWLINE\n",yytext);  return NEWLINE; }
[a-zA-Z\_][a-zA-Z0-9]* {
        yylvalctx.stringVal=yytext;
        yylvalctx.intVal=0;
        yylvalctx.line=yyline;
        yylvalctx.col = yycol;
        debugOut("SYMBOL %s\n",yytext);
        return SYMBOL;
     }
[1-9][0-9]* {
     yylvalctx.stringVal=yytext;
     sscanf(yytext,"%d",&yylvalctx.intVal);
     yylvalctx.line=yyline;
     yylvalctx.col = yycol;
     debugOut("DIGIT %s\n",yytext);
     return DIGIT;
     }
"+" {
        yylvalctx.stringVal=yytext;
        yylvalctx.intVal=0;
        yylvalctx.line=yyline;
        yylvalctx.col = yycol;
        debugOut("OP_ADD %s\n",yytext);

        return OP_ADD;
    }
"-" {
        yylvalctx.stringVal=yytext;
        yylvalctx.intVal=0;
        yylvalctx.line=yyline;
        yylvalctx.col = yycol;
        debugOut("OP_MINUS %s\n",yytext);

        return OP_MINUS;
    }
"*" {
        yylvalctx.stringVal=yytext;
        yylvalctx.intVal=0;
        yylvalctx.line=yyline;
        yylvalctx.col = yycol;
        debugOut("OP_MUL %s\n",yytext);

        return OP_MUL;
    }
"/" {
        yylvalctx.stringVal=yytext;
        yylvalctx.intVal=0;
        yylvalctx.line=yyline;
        yylvalctx.col = yycol;
        debugOut("OP_DIV %s\n",yytext);

        return OP_DIV;
    }
"%" {
        yylvalctx.stringVal=yytext;
        yylvalctx.intVal=0;
        yylvalctx.line=yyline;
        yylvalctx.col = yycol;
        debugOut("OP_MOD %s\n",yytext);

        return OP_MOD;
    }
"=" {
        yylvalctx.stringVal=yytext;
        yylvalctx.intVal=0;
        yylvalctx.line=yyline;
        yylvalctx.col = yycol;
        debugOut("OP_ASSIGN %s\n",yytext);
        return OP_ASSIGN;
    }
.   {         debugOut("unknown %s\n",yytext);
    }

