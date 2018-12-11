#include "sys.h"
#include "event.h"
#include "entity.h"
#include "key.h"
#include "draw.h"

const double frame_rate = 1.0 / 24.0; //frame rate in seconds

int main (int argc, char* argv[])
{
	double 	frmstime, frmntime;
	Sys_Init ();
	
	while (1)
	{
		frmstime = Sys_GetTime ();

		K_GetUserInput ();
		EVNT_ProcessEvents ();
		ENTY_UpdateEntities ();
		D_DrawEntities ();
		
		while (1)//
		{
			frmntime = Sys_GetTime ();
			if (frmntime - frmstime >= frame_rate)
				break;
		}
		
		D_UpdateScreen ();
		//detect collisions
		//draw frame
	}
	return 0;
}
