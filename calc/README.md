Yacc-Example
==
A Basic Project which is ready to construct a parser with bison yacc & lex

About This Project
==
For convenience, this project has prepared basic struct which is aimed to parse file/strings into AST.

the structure of this project is alike:
 * Interfaces/
   * BaseObject/
     * [IBaseObject.h][IBaseObject.h]
       * baseobject_dump([pthis][IBaseObject.h], [IPrintstream][IPrintStream.h])
   * Events/
     * [EventHandler.h] [EventHandler.h]
       * eventhandler_new
       * eventhandler_add([pthis][EventHandler.h], delegator)
       * eventhandler_add_function([pthis][EventHandler.h], function)
       * eventhandler_remove([pthis][EventHandler.h],dummy) <- dummy can be delegator or function
       * eventhandler_notify([pthis][EventHandler.h], caller, arg) <- invoke an event
       * eventhandler_destroy
   * Stream/
     * [IPrintStream.h][IPrintStream.h]
       * iprintstream_write
       * iprintstream_flush
       * iprintstream_close
 * Implements
   * BaseExpr/
     * [BaseExpr.h][BaseExpr.h] (implements [IBaseObject][IBaseObject.h])
       * expr_new_digit(int val);
       * expr_new_symbol(const char* sym);
       * expr_new(int op,const char* expv);
       * expr_add_arguments([pthis][BaseExpr.h],int cnt,...);
       * expr_new_with(int op,const char* expv,int cnt,...);
       * expr_destroy([pthis][BaseExpr.h]);
       * expr_print([pthis][BaseExpr.h], [stream][IPrintStream.h]);
   * Stream/
     * [FilePrintStream.h][FilePrintStream.h] (provides a wrapper for convert FILE to IPrintStream)
       * iprintstream_from_file 
     
   [IBaseObject.h]: https://github.com/sunneo/yacc-example/blob/master/calc/include/Interfaces/BaseObject/IBaseObject.h
   [IPrintStream.h]: https://github.com/sunneo/yacc-example/blob/master/calc/include/Interfaces/Stream/IPrintStream.h
   [EventHandler.h]: https://github.com/sunneo/yacc-example/blob/master/calc/include/Interfaces/Events/EventHandler.h
   [BaseExpr.h]: https://github.com/sunneo/yacc-example/blob/master/calc/include/Implements/BaseExpr/BaseExpr.h
   [FilePrintStream.h]: https://github.com/sunneo/yacc-example/blob/master/calc/include/Implements/Stream/FilePrintStream.h
