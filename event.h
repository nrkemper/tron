#ifndef __EVENT_H__
#define __EVENT_H__

#pragma once

// event.h -- event queue handling

#include <stdlib.h>

#define EVNT_KEYPRESS	1

typedef struct event_t
{
	int			type;
	int			arg1;
	int 			arg2;
	struct event_t* 	next;
} event_t;

extern event_t*	eventlist;

void EVNT_Init (void);
void EVNT_PushEvent (int type, int arg1, int arg2);
int EVNT_RemoveEvent(int type);//remove all instances of an event
void EVNT_PopEvent (void);
int EVNT_GetNextEvent (event_t* ret); //returns the event and deletes it from the qu
void EVNT_ProcessEvent (event_t event);
void EVNT_Shutdown (void);
#endif
