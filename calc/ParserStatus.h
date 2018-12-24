#ifndef PARSER_TYPE_H
#define PARSER_TYPE_H
#include "BaseExpr.h"
#include "vector.h"
#include "hashtable.h"
typedef struct YYParamTypeCtx{
      Expr* expr;
      int intVal;
      char* stringVal;
      int line;
      int col;
}YYParamTypeCtx;

typedef union YYParamType{
   YYParamTypeCtx Ctx;
}YYParamType;

typedef struct Document{
   Expr* children;
   Vector* flattenStatements;
}Document;


#endif
