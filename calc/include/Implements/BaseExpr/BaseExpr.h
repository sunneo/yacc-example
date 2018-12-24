#ifndef BASEEXPR_H_
#define BASEEXPR_H_
#include "IBaseObject.h"
#include "IPrintStream.h"
#include "vector.h"
typedef struct Expr
{
   IBaseObject super;
   char* expv;
   int Line;
   int MaxLine;
   int Col;
   int OP;
   Vector* children;
}Expr;
Expr* expr_new_digit(int val);
Expr* expr_new_symbol(const char* sym);
Expr* expr_new(int op,const char* expv);
Expr* expr_add_arguments(Expr* to,int cnt,...);
Expr* expr_new_with(int op,const char* expv,int cnt,...);
void  expr_destroy(Expr* expr);
void  expr_print(const Expr* expr, IPrintStream* stream);
#define EXPR_OP_DIGIT 1
#define EXPR_OP_SYMBOL 2
#define EXPR_OP_ADD 3
#define EXPR_OP_SUB 4
#define EXPR_OP_MUL 5
#define EXPR_OP_DIV 6
#define EXPR_OP_MOD 7
#define EXPR_OP_ASSIGN 8
#define EXPR_OP_NEGATIVE 9
#define EXPR_OP_POSSITIVE 10

#endif
