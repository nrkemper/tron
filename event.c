#include "event.h"

event_t*	eventlist;

void EVNT_Init (void)
{
	eventlist = 0;
}

void EVNT_PushEvent (int type, int arg1, int arg2)
{
	event_t* 	newevent = malloc (sizeof(event_t));
	
	newevent->type = type;
	newevent->arg1 = arg1;
	newevent->arg2 = arg2;
	newevent->next = NULL;
	
	if (eventlist)
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
	ret->next = NULL;
	
	eventlist = toDel->next;
	free (toDel);
	
	return 1;
}

void EVNT_ProcessEvent (event_t event)
{
	switch (event.type)
	{

	}
}

void EVNT_Shutdown (void)
{
	while (eventlist)
		EVNT_PopEvent ();
}
