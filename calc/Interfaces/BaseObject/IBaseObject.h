#ifndef IBASEOBJECT_H_
#define IBASEOBJECT_H_
#include "IPrintStream.h"
typedef struct IBaseObject{
   void (*dump)(const struct IBaseObject* pthis, IPrintStream* stream);
}IBaseObject;

void baseobject_dump(const IBaseObject* pthis, IPrintStream* stream);
#endif
