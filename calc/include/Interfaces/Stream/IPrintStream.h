#ifndef IPRINTSTREAM_H_
#define IPRINTSTREAM_H_

typedef struct IPrintStream
{
   int (*write)(struct IPrintStream* pthis,const void* src, int len);
   void (*flush)(struct IPrintStream* pthis);
   void (*close)(struct IPrintStream* pthis);
}IPrintStream;

void          iprintstream_close(IPrintStream* stream);
int           iprintstream_write(IPrintStream* stream,const void* src,int len);
void          iprintstream_flush(IPrintStream* stream);

#endif
