/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 1

#line 2 "parser.y"
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
#line 24 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
   YYParamTypeCtx Ctx;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 52 "generated/y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# ifdef YYLEX_PARAM_TYPE
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, YYLEX_PARAM_TYPE YYLEX_PARAM)
# else
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, void * YYLEX_PARAM)
# endif
# define YYLEX yylex(&yylval, YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(YYSTYPE *yylval)
# define YYLEX yylex(&yylval)
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define OP_ASSIGN 257
#define OP_ADD 258
#define OP_MINUS 259
#define OP_MUL 260
#define OP_DIV 261
#define OP_MOD 262
#define U_MINUS 263
#define U_PLUS 264
#define DIGIT 265
#define SYMBOL 266
#define NEWLINE 267
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    3,    3,    2,    2,    4,    4,
    4,    4,    4,    4,    4,    4,    5,    5,    6,    6,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    3,    1,    2,    1,    2,    3,    3,
    3,    3,    3,    2,    1,    1,    1,    2,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,   17,   19,    0,    0,    0,    0,    0,    0,   14,
    0,    0,    5,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    6,    0,    0,    0,   12,   13,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,   14,    7,    8,    9,
};
static const YYINT yysindex[] = {                      -255,
 -255,    0,    0,    0, -237, -261, -227, -261, -261,    0,
 -261, -261,    0, -260, -255, -255, -255, -255, -255, -260,
 -260, -260,    0, -227, -258, -258,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    8,   66,    9,   25,   36,    0,
    0,   70,    0,   74,    0,    0,    0,    0,    0,   47,
   58,   78,    0,   13,    1,    5,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    7,   12,   -1,    0,    0,
};
#define YYTABLESIZE 344
static const YYINT yytable[] = {                         10,
   10,   18,   19,    1,   11,   13,   23,    1,    7,    2,
    3,   12,    9,   24,   25,   26,   27,   28,   11,   20,
   21,    1,   22,    0,   15,    0,    0,    2,    3,   15,
   16,   17,   18,   19,    0,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    3,
    0,    0,    0,    8,    0,    0,    0,    4,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   10,   10,   10,   10,
   11,   11,   11,   11,    7,   10,   10,   10,    9,   11,
   11,   11,    0,    7,    7,    7,    0,    9,    9,    9,
   15,   15,   15,   15,   15,   15,    0,    0,    0,   15,
   15,   16,   16,   16,   16,   16,   16,    0,    0,    0,
   16,   16,   18,   18,   18,   18,   18,   18,    0,    0,
    0,   18,   18,   20,   20,   20,   20,   20,   20,    0,
    0,    2,   20,   20,    2,    3,    0,    0,    3,    8,
    2,    2,    8,    4,    3,    3,    4,    0,    8,    8,
    0,    0,    4,    4,
};
static const YYINT yycheck[] = {                          1,
    0,  260,  261,  259,    0,  267,  267,    0,    0,  265,
  266,    5,    0,   15,   16,   17,   18,   19,  256,    8,
    9,  259,   11,   -1,    0,   -1,   -1,  265,  266,  257,
  258,  259,  260,  261,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,    0,
   -1,   -1,   -1,    0,   -1,   -1,   -1,    0,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,
  256,  257,  258,  259,  256,  265,  266,  267,  256,  265,
  266,  267,   -1,  265,  266,  267,   -1,  265,  266,  267,
  256,  257,  258,  259,  260,  261,   -1,   -1,   -1,  265,
  266,  256,  257,  258,  259,  260,  261,   -1,   -1,   -1,
  265,  266,  256,  257,  258,  259,  260,  261,   -1,   -1,
   -1,  265,  266,  256,  257,  258,  259,  260,  261,   -1,
   -1,  256,  265,  266,  259,  256,   -1,   -1,  259,  256,
  265,  266,  259,  256,  265,  266,  259,   -1,  265,  266,
   -1,   -1,  265,  266,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#define YYUNDFTOKEN 276
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"OP_ASSIGN","OP_ADD","OP_MINUS",
"OP_MUL","OP_DIV","OP_MOD","U_MINUS","U_PLUS","DIGIT","SYMBOL","NEWLINE",0,0,0,
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : statements",
"statements : statement",
"statements : statements statement",
"statements : statements error newline",
"newline : NEWLINE",
"newline : newline NEWLINE",
"statement : expr",
"statement : statement newline",
"expr : expr OP_ASSIGN expr",
"expr : expr OP_ADD expr",
"expr : expr OP_MINUS expr",
"expr : expr OP_MUL expr",
"expr : expr OP_DIV expr",
"expr : OP_MINUS expr",
"expr : digit",
"expr : symbol",
"digit : DIGIT",
"digit : digit newline",
"symbol : SYMBOL",
"symbol : symbol newline",

};
#endif

int      yydebug;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
#line 108 "parser.y"
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
#line 309 "generated/y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int      yyerrflag;
    int      yychar;
    YYSTYPE  yyval;
    YYSTYPE  yylval;

    /* variables for the parser stack */
    YYSTACKDATA yystack;
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 35 "parser.y"
	{ YYPARSE_PARAM->children=yystack.l_mark[0].Ctx.expr; }
break;
case 2:
#line 37 "parser.y"
	{ 
           vector_push_back( YYPARSE_PARAM->flattenStatements, yystack.l_mark[0].Ctx.expr);
           YYPARSE_PARAM->children=yystack.l_mark[0].Ctx.expr;
           yyval.Ctx.expr=yystack.l_mark[0].Ctx.expr;
        }
break;
case 3:
#line 42 "parser.y"
	{
           expr_add_arguments(yystack.l_mark[-1].Ctx.expr,1,yystack.l_mark[0].Ctx.expr);
           vector_push_back( YYPARSE_PARAM->flattenStatements, yystack.l_mark[-1].Ctx.expr);
           yyval.Ctx.expr=yystack.l_mark[-1].Ctx.expr;
        }
break;
case 4:
#line 47 "parser.y"
	{
           yyval.Ctx.expr=yystack.l_mark[-2].Ctx.expr;
        }
break;
case 7:
#line 55 "parser.y"
	{ DebugOut(expr_print(yystack.l_mark[0].Ctx.expr,get_dumper())); DebugOut(iprintstream_write(get_dumper(),"\n",1)); }
break;
case 9:
#line 58 "parser.y"
	{
          yyval.Ctx.expr = expr_new_with(EXPR_OP_ASSIGN,"=",2, yystack.l_mark[-2].Ctx.expr,yystack.l_mark[0].Ctx.expr);
          yyval.Ctx.expr->Line = yystack.l_mark[-2].Ctx.line;
        }
break;
case 10:
#line 63 "parser.y"
	{
         yyval.Ctx.expr = expr_new_with(EXPR_OP_ADD,"+",2, yystack.l_mark[-2].Ctx.expr,yystack.l_mark[0].Ctx.expr);
         yyval.Ctx.expr->Line = yystack.l_mark[-2].Ctx.expr->Line;
      }
break;
case 11:
#line 68 "parser.y"
	{
         yyval.Ctx.expr = expr_new_with(EXPR_OP_SUB,"-",2, yystack.l_mark[-2].Ctx.expr,yystack.l_mark[0].Ctx.expr);
         yyval.Ctx.expr->Line = yystack.l_mark[-2].Ctx.expr->Line;
       }
break;
case 12:
#line 73 "parser.y"
	{
         yyval.Ctx.expr = expr_new_with(EXPR_OP_MUL,"*",2, yystack.l_mark[-2].Ctx.expr,yystack.l_mark[0].Ctx.expr);
         yyval.Ctx.expr->Line = yystack.l_mark[-2].Ctx.expr->Line;
       }
break;
case 13:
#line 78 "parser.y"
	{
         yyval.Ctx.expr = expr_new_with(EXPR_OP_MUL,"*",2, yystack.l_mark[-2].Ctx.expr,yystack.l_mark[0].Ctx.expr);
         yyval.Ctx.expr->Line = yystack.l_mark[-2].Ctx.expr->Line;
       }
break;
case 14:
#line 83 "parser.y"
	{
         yyval.Ctx.expr = expr_new_with(EXPR_OP_NEGATIVE,"-",1, yystack.l_mark[0].Ctx.expr);
         yyval.Ctx.expr->Line = yystack.l_mark[-1].Ctx.line;
       }
break;
case 17:
#line 90 "parser.y"
	{ 
         yyval.Ctx.expr = expr_new_digit(yystack.l_mark[0].Ctx.intVal);
         yyval.Ctx.expr->Line = yystack.l_mark[0].Ctx.line;
         yyval.Ctx.expr->Col = yystack.l_mark[0].Ctx.col;
     }
break;
case 18:
#line 95 "parser.y"
	{ yyval.Ctx.expr=yystack.l_mark[-1].Ctx.expr; }
break;
case 19:
#line 97 "parser.y"
	{ 
         yyval.Ctx.expr = expr_new_symbol(yystack.l_mark[0].Ctx.stringVal);
         yyval.Ctx.expr->Line = yystack.l_mark[0].Ctx.line;
         yyval.Ctx.expr->Col = yystack.l_mark[0].Ctx.col;
     }
break;
case 20:
#line 102 "parser.y"
	{ yyval.Ctx.expr=yystack.l_mark[-1].Ctx.expr; }
break;
#line 614 "generated/y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
