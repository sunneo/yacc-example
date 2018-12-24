#include "IBaseObject.h"
#include <stddef.h>
void baseobject_dump(const IBaseObject* pthis, IPrintStream* stream){
   if(pthis==NULL||stream==NULL) return;
   pthis->dump(pthis,stream);
}

