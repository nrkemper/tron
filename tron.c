#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

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
			wmvaddch (des, y, x, src->_buff[x][y]);

	wrefresh (des);
}

void InitilizeCurses
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

int main (void)
{
	InitScreenBuffer ();
	getch ();
	DestroyScreen ();
	endwin();
	return 0;
}
