#include "event.h"
#include "sys.h"
#include <stdlib.h>
#include <stdio.h>

event_t*	eventlist;

void EVNT_Init (void)
{
	eventlist = 0;
}

void EVNT_PushEvent (int type, int arg1, int arg2, entity_t* entity)
{
	//FIXME: replace with memory manager functions
	event_t* 	newevent = malloc (sizeof(event_t));
	
	newevent->type = type;
	newevent->arg1 = arg1;
	newevent->arg2 = arg2;
	newevent->entity = entity;
	newevent->next = eventlist;

	eventlist = newevent;
}

int EVNT_RemoveEvent(int type) //remove all instances of an event
{
	int cnt=0;
	if (eventlist)
	{
		event_t* cur;
		event_t* toDel = NULL;
		
		while (eventlist->type == type)
		{
			EVNT_PopEvent ();
			cnt++;
		}

		cur = eventlist;

		while (cur->next)
		{
			if (cur->next->type == type)
			{
				toDel = cur->next;
				cur->next = toDel->next;
				free (toDel);
				cnt++;
			}
			else
				cur = cur->next;
		}
	}
	return cnt;
}

void EVNT_PopEvent (void)
{
	event_t* toDel;

	if (eventlist)
	{
		toDel = eventlist;
		eventlist = toDel->next;
		free (toDel);
	}
}

//returns the event on top of the stack and deletes it
int EVNT_GetNextEvent (event_t* ret)
{
	event_t* toDel = eventlist;
	
	if (!eventlist)
		return -1;

	ret->type = eventlist->type;
	ret->arg1 = eventlist->arg1;
	ret->arg2 = eventlist->arg2;
	ret->entity = eventlist->entity;
	ret->next = NULL;
	
	eventlist = toDel->next;
	free (toDel);
	
	return 0;
}

void EVNT_ProcessEvent (event_t* event)
{
	switch (event->type)
	{
		case EVNT_KEYPRESS:
			
		break;
		
		case EVNT_JUMP:		break;
		case EVNT_FIRE:		break;
		
		case EVNT_MVUP:
			if (event->entity->updated == 0)
			{
				event->entity->x.pf = event->entity->x.p0;
				event->entity->y.pf = event->entity->y.p0 - event->entity->speed;
				event->entity->updated = 1;
			}
		break;

		case EVNT_MVDOWN:	
			if (event->entity->updated == 0)
			{
				event->entity->x.pf = event->entity->x.p0;
				event->entity->y.pf = event->entity->y.p0 + event->entity->speed;
				event->entity->updated = 1;
			}
		break;

		case EVNT_MVLEFT:	
			if (event->entity->updated == 0)
			{
				event->entity->x.pf = event->entity->x.p0 - event->entity->speed;
				event->entity->y.pf = event->entity->y.p0;
				event->entity->updated = 1;
			}
		break;
		
		case EVNT_MVRIGHT:
			if (event->entity->updated == 0)
			{
				event->entity->x.pf = event->entity->x.p0 + event->entity->speed;
				event->entity->y.pf = event->entity->y.p0;
				event->entity->updated = 1;
			}
		break;
	
		case EVNT_BOOST:	break;
		case EVNT_COLLISION:	break;
		case EVNT_QUIT:
			Sys_Shutdown ();
		break;
	}
}

void EVNT_ProcessEvents (void)
{
	event_t		event;

	while (EVNT_GetNextEvent (&event) == 0)
	{
		EVNT_ProcessEvent (&event);
	}
}

void EVNT_Shutdown (void)
{
	while (eventlist)
		EVNT_PopEvent ();
}
