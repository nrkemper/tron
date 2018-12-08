#include "key.h"

void K_Init (void)
{
	noecho ();
	keypad (stdscr, TRUE);
	cbreak ();
	nodelay (stdscr, TRUE);
}

int K_GetKey (void)
{
	return wgetch (stdscr);
}

int K_ProcessKey (int key)
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

void K_GetUserInput (void)
{
	int ch;
	
	while (1)
	{
		ch = K_GetKey ();

		if (ch == ERR)
			return;
	
		ch = K_ProcessKey (ch);
		
		EVNT_PushEvent (EVNT_KEYPRESS, ch, 0);
	}
}

void K_Shutdown (void)
{
	
}
