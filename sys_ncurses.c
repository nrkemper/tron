#include "sys.h"
#include "key.h"
#include "entity.h"
#include "event.h"
#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>
/*
 *
 * 	System dependent functions
 *
 */

void Sys_Init ()
{
	initscr ();
	K_Init ();
	EVNT_Init ();
	ENTY_Init ();
}

int Sys_GetKey (void)
{
	return getch ();
}

int Sys_ProcessKey (int key)
{
	switch (key)
	{
		case 9:			return K_TAB;		break;
		
		case KEY_ENTER:
		case 10:		return K_ENTER;		break;
		
		case KEY_EXIT:
		case 27:		return K_ESCAPE;	break;
		
		case 32:		return K_SPACE;		break;
		
		case KEY_BACKSPACE:	
		case 127:		return K_BACKSPACE;	break;
		
		case KEY_IC:		return K_INSERT;	break;
		case KEY_DC:		return K_DELETE;	break;
		case KEY_HOME:		return K_HOME;		break;
		case KEY_END:		return K_END;		break;
		case KEY_PPAGE:		return K_PGUP;		break;
		case KEY_NPAGE:		return K_PGDOWN;	break;
		case KEY_UP:		return K_UPARROW; 	break;
		case KEY_DOWN:		return K_DOWNARROW;	break;
		case KEY_LEFT:		return K_LEFTARROW;	break;
		case KEY_RIGHT:		return K_RIGHTARROW;	break;
		
		case KEY_F(1):		return K_F1;		break;
		case KEY_F(2):		return K_F2;		break;
		case KEY_F(3):		return K_F3;		break;
		case KEY_F(4):		return K_F4;		break;
		case KEY_F(5):		return K_F5;		break;
		case KEY_F(6):		return K_F6;		break;
		case KEY_F(7):		return K_F7;		break;
		case KEY_F(8):		return K_F8;		break;
		case KEY_F(9):		return K_F9;		break;
		case KEY_F(10):		return K_F10;		break;
		case KEY_F(11):		return K_F11;		break;
		case KEY_F(12):		return K_F12;		break;
				
		default:
		{	
			if (key >= 'a' && key <= 'z')
				return key;

			if (key >= 'A' && key <= 'Z')
				return key + 32;
		}
		break;
	}
	return -1;
}

double Sys_GetTime (void)
{
	static int 	secbase;
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday (&tv, &tz);

	if (!secbase)
	{
		secbase = tv.tv_sec;
		return tv.tv_usec / 1000000.0;
	}

	return tv.tv_sec - secbase + (tv.tv_usec / 1000000.0);
}

void Sys_Shutdown (void)
{
	endwin ();
	EVNT_Shutdown ();
	ENTY_Shutdown ();
	K_Shutdown ();
	exit (0);
}
