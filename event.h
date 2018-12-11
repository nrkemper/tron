#ifndef __EVENT_H__
#define __EVENT_H__

#pragma once

// event.h -- event queue handling

#include "entity.h"

#define EVNT_KEYPRESS	0
#define EVNT_JUMP	1
#define EVNT_FIRE	2
#define EVNT_MVUP	3
#define EVNT_MVDOWN	4
#define EVNT_MVLEFT	5
#define EVNT_MVRIGHT	6
#define EVNT_BOOST	7
#define EVNT_COLLISION	8
#define EVNT_QUIT	9

typedef struct event_t
{
	int			type;
	int			arg1;
	int 			arg2;
	entity_t*		entity;
	struct event_t* 	next;
} event_t;

extern event_t*	eventlist;

void EVNT_Init (void);
void EVNT_PushEvent (int type, int arg1, int arg2, entity_t* entity);
int EVNT_RemoveEvent(int type);//remove all instances of an event
void EVNT_PopEvent (void);
int EVNT_GetNextEvent (event_t* ret); //returns the event and deletes it from the qu
void EVNT_ProcessEvent (event_t* event);
void EVNT_ProcessEvents (void);
void EVNT_Shutdown (void);
#endif
