/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_GENERATED_Y_TAB_H_INCLUDED
# define YY_YY_GENERATED_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OP_ASSIGN = 258,
    OP_ADD = 259,
    OP_MINUS = 260,
    OP_MUL = 261,
    OP_DIV = 262,
    OP_MOD = 263,
    U_MINUS = 264,
    U_PLUS = 265,
    DIGIT = 266,
    SYMBOL = 267,
    NEWLINE = 268
  };
#endif
/* Tokens.  */
#define OP_ASSIGN 258
#define OP_ADD 259
#define OP_MINUS 260
#define OP_MUL 261
#define OP_DIV 262
#define OP_MOD 263
#define U_MINUS 264
#define U_PLUS 265
#define DIGIT 266
#define SYMBOL 267
#define NEWLINE 268

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:1909  */

   Document doc;
   YYParamTypeCtx Ctx;

#line 85 "generated/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (Document* parserStatus);

#endif /* !YY_YY_GENERATED_Y_TAB_H_INCLUDED  */
