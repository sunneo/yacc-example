CC=gcc
LEXER=flex
PARSER=bison
CCFLAGS=-I include/Interfaces/Stream \
        -I include/Interfaces/BaseObject \
        -I include/Implements/Stream \
        -I include/Implements/BaseExpr \
        -I ../libs/Vector/include \
	-I ../libs/Hashtable.2/include \
        -I generated \
        -I ./ \
	-ggdb -Wno-pointer-to-int-cast -Wno-implicit-function-declaration
SRC= src/Interfaces/Stream/IPrintStream.c \
     src/Interfaces/BaseObject/IBaseObject.c \
     src/Implements/Stream/FilePrintStream.c \
     src/Implements/BaseExpr/BaseExpr.c \
     ../libs/Hashtable.2/src/hashtable.c \
     ../libs/Vector/src/vector.c ../libs/Vector/src/vector_iter.c
     
all: Main
clean:
	rm -f Main generated/* 

GEN_PARSER=generated/y.tab.c
GEN_LEXER=generated/lex.yy.c

$(GEN_PARSER): parser.y
	$(PARSER) -y -d parser.y 
	mv y.tab.* generated

$(GEN_LEXER): lexer.l
	$(LEXER) --bison-bridge -o $(GEN_LEXER) lexer.l

Main: $(SRC) $(GEN_PARSER) $(GEN_LEXER)
	$(CC) -o Main $(SRC) $(CCFLAGS) $(GEN_PARSER) $(GEN_LEXER)
test: 
	./Main input.txt
