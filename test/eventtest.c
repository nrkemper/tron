#include "../event.h"
#include <stdio.h>

int main (void)
{
	event_t		event;
	EVNT_Init ();
	ENTY_Init ();
	EVNT_PushEvent (EVNT_QUIT, 0, 0, 0);
	
	if (EVNT_GetNextEvent (&event) == 0)
	{
		printf ("SUCCESS: got next event\n");
		printf ("Event: <type: %d> <arg1: %d> <arg2: %d> <ENTITY: name: %s>\n", event.type, event.arg1, event.arg2, event.entity->name);
	}
	else
		printf ("ERROR: didn't grab event\n");
	EVNT_ProcessEvents ();
	EVNT_Shutdown ();
	return 0;
}
