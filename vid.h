#ifndef __VID_H__
#define __VID_H__
#pragma once

#include <stdint.h>
#include <stdlib.h>

#define byte	uint8_t

typedef struct vid_t
{
	unsigned int	width;
	unsigned int	height;
	unsigned char	bpp;
	void*			buffer;
} vid_t;

extern vid_t	vid;

void VID_Init (void);
void VID_CreateBuffer (void);
int VID_DumpBuffer (const char* destFile);
void VID_QueryScreen (void);
void VID_Shutdown (void);

#endif