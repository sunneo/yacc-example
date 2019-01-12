#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include "vector.h"
#include "hashtable.h"

typedef struct EventArgs{
   void* Data;
}EventArgs;

typedef struct EventHandler{
	Vector* notifier;
	struct Hashtable* notifierMap;
}EventHandler;

typedef struct EventDelegator{
   void (*OnNotified)(struct EventDelegator* pthis,void* sender, EventArgs* args);
}EventDelegator;

EventHandler* eventhandler_new();
EventHandler* eventhandler_add(EventHandler* pthis, 
	const EventDelegator* delegator);
EventHandler* eventhandler_add_function(EventHandler* pthis, void(*fnc)(void* caller,EventArgs* args));
EventHandler* eventhandler_remove(EventHandler* pthis, void* ptr);
void eventhandler_notify(EventHandler* pthis, void* caller, EventArgs* arg);
void  eventhandler_destroy(EventHandler* eventHandler);
#endif
