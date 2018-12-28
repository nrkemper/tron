#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vid.h"
#include "typedefs.h"


vid_t	vid;

void VID_Init (void)
{
	vid.buffer	= 0;
	vid.width	= 0;
	vid.height	= 0;
	vid.bpp		= 0;
}

//FIXME: valid only for 24bpp
void VID_CreateBuffer (void)
{
	//FIXME: use memory manager here
	switch (vid.bpp)
	{
		case 32:
			vid.buffer = malloc (vid.height * vid.width * sizeof (pixel32_t));
			memset (vid.buffer, 0, vid.width * vid.height * sizeof (pixel32_t));
			break;

		case 24:
			vid.buffer = malloc (vid.height * vid.width * sizeof (pixel24_t));
			memset (vid.buffer, 0, vid.width * vid.height * sizeof (pixel24_t));
			break;

		case 16:
			vid.buffer = malloc (vid.height * vid.width * sizeof (pixel16_t));
			memset (vid.buffer, 0, vid.width * vid.height * sizeof (pixel16_t));
			break;

		case 8:
			vid.buffer = malloc (vid.height * vid.width * sizeof (pixel8_t));
			memset (vid.buffer, 0, vid.width * vid.height * sizeof (pixel8_t));
			break;
	}
}


//FIXME: write the size of a WORD
int VID_DumpBuffer (const char* destFile)
{
	FILE* fp = fopen (destFile, "w");
	//FIXME: need to account for different BPP
	int numBytes = vid.width * vid.height * sizeof (pixel32_t);
	int cnt = 0;
	//FIXME: need to write the actual pixels and need to account for different pixel types
	char* vidbufp = (char*)vid.buffer;
	if (fp == NULL)
	{
		return -1;
	}

	fprintf (fp, "Data Begin:'");
	while (cnt < numBytes)
	{
		fprintf (fp, "%c", vidbufp[cnt]);
		cnt++;
	}
	fprintf (fp, "':End\n");
	return 0;
}

//FIXME: Should be Sys_QueryScreen () ????
void VID_QueryScreen (void)
{

}


//FIXME: use memory manager here
void VID_Shutdown (void)
{
	free (vid.buffer);
}