#include <stdio.h>
#include "../event.h"

int main (void)
{
	event_t event;
	int j, removed;

	EVNT_Init ();

	for (j=0 ; j<10 ; j++)
		EVNT_PushEvent (1, 0, 0);
	
	for (j=0 ; j<10 ; j++)
		EVNT_PushEvent (j, j+1, j+2);

	for (j=0 ; j<10 ; j++)
		EVNT_PushEvent (1, 0, 0);
	
	EVNT_PopEvent ();

	removed = EVNT_RemoveEvent (1);
	printf ("Removed %d events\n", removed);

	removed = EVNT_RemoveEvent (1);
	printf ("Removed %d events\n", removed);
	
	removed = EVNT_RemoveEvent (9);
	printf ("Removed %d events\n", removed);
	
	EVNT_PopEvent ();

	while (EVNT_GetNextEvent (&event) != -1)
		printf ("Event:\nType: %d\nArg1: %d\nArg2: %d\n\n", event.type, event.arg1, event.arg2);
	
	for (j=0 ; j<10 ; j++)
		EVNT_PushEvent (1, 0, 0);
	
	EVNT_Shutdown ();
	
	printf ("Events after shutdown:\n");
	printf ("----------------------\n\n");	
	while (EVNT_GetNextEvent (&event) != -1)
		printf ("Event:\nType: %d\nArg1: %d\nArg2: %d\n\n", event.type, event.arg1, event.arg2);
	
	return 0;
}
