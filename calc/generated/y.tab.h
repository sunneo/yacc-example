/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_D_DOWNLOADS_SRC_YACCEXAMPLE_YACC_EXAMPLE_MSVC_YACCEXAM_CALC_GENERATED_Y_TAB_H_INCLUDED
# define YY_YY_D_DOWNLOADS_SRC_YACCEXAMPLE_YACC_EXAMPLE_MSVC_YACCEXAM_CALC_GENERATED_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OP_ASSIGN = 258,
     OP_MINUS = 259,
     OP_ADD = 260,
     OP_MOD = 261,
     OP_DIV = 262,
     OP_MUL = 263,
     U_PLUS = 264,
     U_MINUS = 265,
     DIGIT = 266,
     SYMBOL = 267,
     NEWLINE = 268
   };
#endif
/* Tokens.  */
#define OP_ASSIGN 258
#define OP_MINUS 259
#define OP_ADD 260
#define OP_MOD 261
#define OP_DIV 262
#define OP_MUL 263
#define U_PLUS 264
#define U_MINUS 265
#define DIGIT 266
#define SYMBOL 267
#define NEWLINE 268



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 31 "D:\\Downloads\\SRC\\YaccExample\\yacc-example\\msvc\\yaccExam\\..\\..\\calc\\parser.y"

   Document doc;
   YYParamTypeCtx Ctx;


/* Line 2058 of yacc.c  */
#line 89 "D:\\Downloads\\SRC\\YaccExample\\yacc-example\\msvc\\yaccExam\\..\\..\\calc\\generated\\y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (Document* parserStatus);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_D_DOWNLOADS_SRC_YACCEXAMPLE_YACC_EXAMPLE_MSVC_YACCEXAM_CALC_GENERATED_Y_TAB_H_INCLUDED  */
