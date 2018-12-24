#include "IPrintStream.h"
#include <stddef.h>
#include <stdlib.h>
void iprintstream_close(IPrintStream* stream){
  if(stream == NULL)  return;
  stream->close(stream);
  free(stream);
}
int iprintstream_write(IPrintStream* stream,const void* src,int len){
   if(stream == NULL)  return -1;
   return stream->write(stream,src,len);
}
void iprintstream_flush(IPrintStream* stream){
   if(stream == NULL)  return;
   stream->flush(stream);
}


