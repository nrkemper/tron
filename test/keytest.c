#include "../key.h"
#include <stdio.h>
#include <string.h>

int main (void)
{
	int ch;
	char buffer[256];
	
	initscr ();
	K_Init ();
	while (1) 
	{
		clear ();
		mvaddstr (0, 0, "Press any key: ");
		refresh ();
		
		ch = K_GetKey ();
		ch = K_ProcessKey (ch);
		
		clear ();
		strcpy (buffer, "Key pressed: ");
		mvaddstr (0, 0, buffer);

		switch (ch)
		{
			case K_TAB:		strcpy (buffer, "TAB");		break;
			case K_ENTER:		strcpy (buffer, "ENTER");	break;
			case K_ESCAPE:		strcpy (buffer, "ESCAPE");	break;
			case K_SPACE:		strcpy (buffer, "SPACE");	break;
				
			case K_BACKSPACE:	strcpy (buffer, "BACKSPACE");	break;
			case K_INSERT:		strcpy (buffer, "INSERT");	break;
			case K_DELETE:		strcpy (buffer, "DELETE");	break;
			case K_HOME:		strcpy (buffer, "HOME");	break;
			case K_END:		strcpy (buffer, "END");		break;
			case K_PGUP:		strcpy (buffer, "PAGE UP");	break;
			case K_PGDOWN:		strcpy (buffer, "PAGE DOWN");	break;
			case K_UPARROW:		strcpy (buffer, "UP ARROW");	break;
			case K_DOWNARROW:	strcpy (buffer, "DOWN ARROW");	break;
			case K_LEFTARROW:	strcpy (buffer, "LEFT ARROW");	break;
			case K_RIGHTARROW:	strcpy (buffer, "RIGHT ARROW");	break;

			case K_F1:		strcpy (buffer, "F1");		break;
			case K_F2:		strcpy (buffer, "F2");		break;
			case K_F3:		strcpy (buffer, "F3");		break;
			case K_F4:		strcpy (buffer, "F4");		break;
			case K_F5:		strcpy (buffer, "F5");		break;
			case K_F6:		strcpy (buffer, "F6");		break;
			case K_F7:		strcpy (buffer, "F7");		break;
			case K_F8:		strcpy (buffer, "F8");		break;
			case K_F9:		strcpy (buffer, "F9");		break;
			case K_F10:		strcpy (buffer, "F10");		break;
			case K_F11:		strcpy (buffer, "F11");		break;
			case K_F12:		strcpy (buffer, "F12");		break;

			default:
			{
				if (ch >= 'a' && ch <= 'z')
					sprintf (buffer, "'%c'", ch);
				else
					strcpy (buffer, "N/A");
			}
		}
		addstr (buffer);

		mvaddstr (3, 0, "Press any key to continue or 'q' to exit.");
		refresh ();
		getch ();
	}
	K_Shutdown ();	
	endwin ();
	return 0;
}
