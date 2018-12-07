#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

char* Sys_GetInput (void)
{
	static char text[256];
	fd_set	fd;
	struct timeval	tp;

	FD_ZERO (&fd);
	FD_SET (0, &fd);
	
	tp.tv_sec = 0;
	tp.tv_usec = 0;
	
	if (select (1, &fd, NULL, NULL, &tp) == -1 || !FD_ISSET (0, &fd))
	{
		//printf ("ERR: fd isn't set properly\n");
		return NULL;
	}

	read (0, text, sizeof(text));
	return text;
}

double Sys_GetTime (void)
{
	struct timeval		tv;
	struct timezone		tz;
	static double 		starttime;

	gettimeofday (&tv, &tz);

	if (starttime == 0)
	{
		starttime = tv.tv_sec; 
		return tv.tv_usec / 1000000.0;
	}

	return (tv.tv_sec - starttime) + (tv.tv_usec / 1000000.0);
}
int main (void)
{
	char*	text;

	while (Sys_GetTime () < 10)
	{
		text = Sys_GetInput ();

		if (text)
			printf( "Key pressed: %s", text);
	}
	return 0;
}
