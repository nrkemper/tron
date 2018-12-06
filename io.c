#include "io.h"

event_t*	ioevntlst;
screen_t	screen;	//global screen

void io_Init()
{
	int	x, y;
	
	initscr();
	keypad (stdscr, TRUE);
	noecho ();
	curs_set (0);
	//nodelay (stdscr, TRUE); //so getch doesn't block

	//FIXME: make Sys_GetMaxYX (int* width, int* height); function
	getmaxyx (stdscr, screen._height, screen._width);
	
	if (screen._buffer)
		io_DestroyScreen();

	screen._buffer = (pixel_t**)malloc (screen._width * sizeof (pixel_t*));

	for (x=0 ; x<screen._width ; x++)
		screen._buffer[x] = (pixel_t*)malloc (sizeof(pixel_t) * screen._height);

	for (y=0 ; y<screen._height ; y++)
		for (x=0 ; x<screen._width ; x++)
			screen._buffer[x][y] = 0;
}

void io_ProcessKey(int key)
{
	switch (key)
	{
	//	case
	}
}
void io_RenderBuffer()
{
	int	x, y;

	for (y=0 ; y<screen._height ; y++)
		for (x=0 ; x<screen._width ; x++)
			mvaddch (y, x, screen._buffer[x][y]);

	wrefresh (stdscr);
}

void io_DestroyScreen()
{
	if (screen._buffer)
	{
		for (int cnt=0 ; cnt<screen._width ; cnt++)
			free (screen._buffer[cnt]);
	}

	free (screen._buffer);
}

void io_Shutdown ()
{
	io_DestroyScreen();
	endwin();
}
