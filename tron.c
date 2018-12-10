#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

#include "key.h"
/*
typedef struct screen_t
{	
	int	_width, _height;
	char**	_buff;
} screen_t;

extern screen_t		screen;	//global screen

void DestroyScreen ();

void InitScreenBuffer ()
{
	int	x, y;

	if (screen._buff)
		DestroyScreen();

	getmaxyx (stdscr, screen._height, screen._width);

	screen._buff = (char**)malloc (screen._width * sizeof (char*));

	for (x=0 ; x<screen._width ; x++)
		screen._buff[x] = malloc ((char)sizeof(char) * screen._height);

	for (y=0 ; y<screen._height ; y++)
		for (x=0 ; x<screen._width ; x++)
			screen._buff[x][y] = 0;
}

void R_RenderBuffer (WINDOW* des, screen_t* src)
{
	int	x, y;

	for (y=0 ; y<src->_height ; y++)
		for (x=0 ; x<src->_width ; x++)
		{
			wmove (des, y, x);
			waddch (des, src->_buff[x][y]);
		}
	wrefresh (des);
}

void InitilizeCurses (void)
{
	initscr();
	keypad (stdscr, TRUE);
	noecho ();
	//nodelay (stdscr, TRUE); //so getch doesn't block
	
}

void DestroyScreen ()
{
	if (screen._buff)
	{
		for (int cnt=0 ; cnt<screen._width ; cnt++)
			free (screen._buff[cnt]);
	}

	free (screen._buff);
}
*/
int main (void)
{
	FILE* fp = fopen ("../log/log.txt", "w");
	event_t event;
	int cnt = 0;

	if (fp == NULL)
	{
		printf ("ERROR: could not open log file\n");
		exit (-1);
	}

	initscr ();
	K_Init ();
	EVNT_Init ();

	while (1)
	{
		K_GetUserInput ();
		
		if (EVNT_GetNextEvent (&event) == 1)
		{
			fprintf (fp, "Event %d\n", cnt);
			fprintf (fp, "----------\n");
			fprintf (fp, "Type: %d\n", event.type);
			fprintf (fp, "Arg 1: %d\n", event.arg1);
			fprintf (fp, "Arg 2: %d\n", event.arg2);
			fprintf (fp, "----------\n\n");

			cnt++;
		}
	}

	fclose (fp);
	K_Shutdown ();
	EVNT_Shutdown ();
	endwin ();
	return 0;
}
