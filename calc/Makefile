CC=gcc
LEXER=flex
PARSER=byacc
CCFLAGS=-I Interfaces/Stream \
        -I Interfaces/BaseObject \
        -I Implements/Stream \
        -I Implements/BaseExpr \
        -I ../libs/Vector/include \
        -I generated \
        -I ./ \
	-ggdb
SRC= Interfaces/Stream/IPrintStream.c \
     Interfaces/BaseObject/IBaseObject.c \
     Implements/Stream/FilePrintStream.c \
     Implements/BaseExpr/BaseExpr.c \
     ../libs/Vector/src/vector.c ../libs/Vector/src/vector_iter.c
     
all: Main
clean:
	rm -f Main generated/* 

GEN_PARSER=generated/y.tab.c
GEN_LEXER=generated/lex.yy.c

$(GEN_PARSER): parser.y
	$(PARSER) -P -d -o $(GEN_PARSER)  parser.y 

$(GEN_LEXER): lexer.l
	$(LEXER) --bison-bridge -o $(GEN_LEXER) lexer.l

Main: $(SRC) $(GEN_PARSER) $(GEN_LEXER)
	$(CC) -o Main $(SRC) $(CCFLAGS) $(GEN_PARSER) $(GEN_LEXER)
test: 
	./Main input.txt
