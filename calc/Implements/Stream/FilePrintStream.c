#include "FilePrintStream.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct FileStreamImpl{
   IPrintStream super;
   FILE* handle;
}FileStreamImpl;

static int impl_write(IPrintStream* pthis, const void* src,int len){
   FileStreamImpl* me = (FileStreamImpl*)pthis;
   if(me->handle==NULL) return -1;
   return fwrite(src, len, 1, me->handle);
}
static void impl_flush(IPrintStream* pthis){
   FileStreamImpl* me = (FileStreamImpl*)pthis;
   if(me->handle==NULL) return;
   fflush(me->handle);
}
static void impl_close(IPrintStream* pthis){
   FileStreamImpl* me = (FileStreamImpl*)pthis;
   if(me->handle==NULL) return;
   fclose(me->handle);
   me->handle=NULL;
}

static void init(IPrintStream* stream){
   stream->write = impl_write;
   stream->flush = impl_flush;
   stream->close = impl_close;  
}

IPrintStream* iprintstream_from_file(FILE* fp){
   FileStreamImpl* impl = NULL;
   IPrintStream* ret = NULL;
   ret = (IPrintStream*)malloc(sizeof(FileStreamImpl));
   impl = (FileStreamImpl*) ret;
   impl->handle=fp;
   init(ret);
   return ret;
}

