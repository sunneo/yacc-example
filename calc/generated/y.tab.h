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
extern YYSTYPE yylval;
