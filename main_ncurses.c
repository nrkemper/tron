#include "sys.h"
#include "event.h"
#include "entity.h"
#include "key.h"

int main (int argc, char* argv[])
{
	Sys_Init ();
	
	while (1)
	{
		ENTY_UpdateEntities ();
		K_GetUserInput ();
		EVNT_ProcessEvents ();
		//detect collisions
		//draw frame
	}
	return 0;
}
