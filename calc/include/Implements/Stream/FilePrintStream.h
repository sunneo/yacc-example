#ifndef FILEPRINTSTREAM_H_
#define FILEPRINTSTREAM_H_
#include <stdio.h>
#include "IPrintStream.h"
IPrintStream* iprintstream_from_file(FILE* fp);

#endif
