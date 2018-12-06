#ifndef __IO_H__
#define __IO_H__

#pragma once

#include <ncurses.h>
#include <stdlib.h>

#define pixel_t		int

typedef struct event_t
{
	int			_type;
	struct event_t*		_next;
} event_t;

extern event_t*		ioevntlst;

typedef struct screen_t
{
	unsigned	_width;
	unsigned	_height;
	pixel_t**	_buffer;
} screen_t;

extern screen_t		screen;	//global screen

void io_Init();
void io_ProcessKey(int key);
void io_RenderBuffer();
void io_DestroyScreen();
void io_Shutdown();

#endif
