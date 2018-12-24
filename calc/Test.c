#include "BaseExpr.h"
#include "FilePrintStream.h"
int main(){
  IPrintStream* outStream=iprintstream_from_file(stdout);

  Expr* a = expr_new_symbol("A");
  Expr* y = expr_new_symbol("Y");
  Expr* x = expr_new_symbol("X");
  Expr* c = expr_new_digit(1);
  Expr* AMulX = expr_new_with(EXPR_OP_MUL,"*",2,a,x);
  expr_print(AMulX,outStream);
  iprintstream_write(outStream,"\n",1);
  Expr* AddC = expr_new_with(EXPR_OP_ADD,"+",2,AMulX,c);
  expr_print(AddC,outStream);
  iprintstream_write(outStream,"\n",1);

  Expr* assign = expr_new_with(EXPR_OP_ASSIGN,"=", 2, y, AddC);
  expr_print(assign,outStream);
  iprintstream_write(outStream,"\n",1);

  return 0;
}
