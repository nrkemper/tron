#include "key.h"
#include "event.h"
#include "entity.h"
#include "sys.h"
#include <ncurses.h>
/*
 *
 *
#define K_TAB		9
#define K_ENTER		10
#define K_ESCAPE	27
#define K_SPACE		32

#define K_BACKSPACE	127
#define K_INSERT	128
#define K_DELETE	129
#define K_HOME		130
#define K_END		131
#define K_PGUP		132
#define K_PGDOWN	133
#define K_UPARROW	134
#define K_DOWNARROW	135
#define K_LEFTARROW	136
#define K_RIGHTARROW	137

#define K_F1		138
#define K_F2		139
#define K_F3		140
#define K_F4		141
#define K_F5		142
#define K_F6		143
#define K_F7		144
#define K_F8		145
#define K_F9		146
#define K_F10		147
#define K_F11		148
#define K_F12		149

 *
 * */
void K_Init (void)
{
	noecho ();
	keypad (stdscr, TRUE);
	cbreak ();
	nodelay (stdscr, TRUE);
}

//FIXME: needs to be updated for key bindings
int K_CreateKeyEvent (int key)
{
	int ret=0;
	switch (key)
	{
		case K_UPARROW:
			EVNT_PushEvent (EVNT_MVUP, 0, 0, self);	
		break;

		case K_DOWNARROW:
			EVNT_PushEvent (EVNT_MVDOWN, 0, 0, self);
		break;

		case K_LEFTARROW:
			EVNT_PushEvent (EVNT_MVLEFT, 0, 0, self);
		break;

		case K_RIGHTARROW:
			EVNT_PushEvent (EVNT_MVRIGHT, 0, 0, self);
		break;

		case 'q':
		case 'Q':
		case K_ESCAPE:
			EVNT_PushEvent (EVNT_QUIT, 0, 0, 0);
		break;

		default:
			ret = -1;
		break;
	}
	return ret;
}

void K_GetUserInput (void)
{
	int ch;
	
	while (1)
	{
		ch = Sys_GetKey ();

		if (ch == ERR)
			return;
	
		ch = Sys_ProcessKey (ch);
		ch = K_CreateKeyEvent (ch);
	}
}

void K_Shutdown (void)
{
	
}
