#include "EventHandler.h"
#include <stdlib.h>
typedef struct TaggedEventDelegator{
   EventDelegator super;
   EventDelegator* Ref;
   unsigned int IsFunction;
}TaggedEventDelegator;

EventHandler* eventhandler_new()
{
   EventHandler* ret = NULL;
   ret->notifier = vector_create(0);
   ret->notifierMap = hashtbl_new(0,0);
   return ret;
}

static TaggedEventDelegator* tagged_new(const void* ptr,unsigned int IsFunction){
   TaggedEventDelegator* ret = NULL;
   ret= (TaggedEventDelegator*)malloc(sizeof(TaggedEventDelegator));
   if(IsFunction){
      ret->super.OnNotified = (void(*)(EventDelegator*,void*,EventArgs*))ptr;
      ret->Ref = NULL;
   }
   else{
      EventDelegator* delegator  = (EventDelegator*)ptr;
      ret->super.OnNotified = delegator->OnNotified;
      ret->Ref = delegator;;
   }
   ret->IsFunction=IsFunction;
   return ret;
}

static void eventhandler_add_pointer(EventHandler* pthis, const void* ptr, unsigned int isfun){
   if(!hashtbl_contains_key(pthis->notifierMap,ptr)){
      TaggedEventDelegator* tagged = tagged_new(ptr,isfun);
      hashtbl_put(pthis->notifierMap,ptr,tagged);
      vector_push_back(pthis->notifier,tagged);
   }
  
}

EventHandler* eventhandler_add(EventHandler* pthis, const EventDelegator* delegator){
   if(pthis==NULL) return pthis;
   eventhandler_add_pointer(pthis,delegator,0);
   return pthis;
}

EventHandler* eventhandler_add_function(EventHandler* pthis, void(*fnc)(void* caller,EventArgs* args)){
   if(pthis==NULL) return pthis;
   eventhandler_add_pointer(pthis,fnc,1);
   return pthis;
}
EventHandler* eventhandler_remove(EventHandler* pthis, void* ptr){
   if(pthis == NULL) return pthis;
   if(hashtbl_contains_key(pthis->notifierMap,ptr)){
      TaggedEventDelegator* tag = hashtbl_get(pthis->notifierMap,ptr);
      int i = 0;
      int size = vector_size(pthis->notifier);
      for(i=0; i<size; ++i){
         void* p = vector_at(pthis->notifier,i);
         if(p == ptr){
            vector_erase(pthis->notifier,i);
            break;
         }
      }
      hashtbl_remove(pthis->notifierMap,ptr);
      free(tag);
   }
   return pthis;
}
void  eventhandler_destroy(EventHandler* eventHandler){
   if(eventHandler==NULL) return;
   if(eventHandler->notifier !=NULL){
      vector_delete(eventHandler->notifier);
   }
   if(eventHandler->notifierMap != NULL){
      hashtbl_delete(eventHandler->notifierMap);
   }
   free(eventHandler);
}
void eventhandler_notify(EventHandler* pthis, void* caller, EventArgs* arg){
   int size = 0;
   int i=0;
   size =vector_size(pthis->notifier);
   for(i=0; i<size; ++i){
      TaggedEventDelegator* tag = (TaggedEventDelegator*)vector_at(pthis->notifier,i);
      if(!tag->IsFunction){
         if(tag->Ref){
             tag->Ref->OnNotified(tag->Ref,caller,arg);
         }
      }
      else{
         tag->super.OnNotified(NULL,caller,arg);
      }
   }
}
void eventhandler_notify_raw(EventHandler* pthis, void* caller, void* arg){
   EventArgs argv;
   argv.Data=arg;
   eventhandler_notify(pthis,caller,&argv);
}

