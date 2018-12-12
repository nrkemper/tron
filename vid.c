/*
typedef struct vid_t
{
	int	width, height;
	char**	buffer;
}vid_t;
*/
#include "sys.h"
#include "vid.h"
#include <stdlib.h>

vid_t		vid;

int VID_Init (void)
{
	int	x, y;

	Sys_GetMaxXY (&x, &y);
	return VID_CreateVGA (x, y);
}

int VID_CreateVGA (int width, int height)
{
	int	j;

	vid.width = width;
	vid.height = height;

	//FIXME: use memory manager instead of malloc
	vid.buffer = (char**)malloc (width * sizeof (char*));
	if (vid.buffer == NULL)
		return -1;

	for (j=0 ; j<width ; j++)
	{
		vid.buffer[j] = (char*)malloc (height * sizeof (char));
		if (vid.buffer[j] == NULL)
		{
			vid.height = j + 1;
			VID_DestroyVGA ();
			return -1;
		}
	}
	return 0;
}

//FIXME: use mmanager for free function
void VID_DestroyVGA (void)
{
	int	j;

	for (j=0 ; j<vid.width ; j++)
		free (vid.buffer[j]);

	free (vid.buffer);

	vid.width = 0;
	vid.height = 0;
}

int VID_Resize (int width, int height)
{
	VID_DestroyVGA ();
	return VID_CreateVGA (width, height);
}

void VID_Shutdown (void)
{
	VID_DestroyVGA();
}
