#include <poll.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

char* Sys_GetConsoleInput (void)
{
	static char 	text[256];
	struct pollfd	pfd[1];
	int		len;

	pfd[0].fd = STDIN_FILENO;
	pfd[0].events = POLLIN | POLLPRI;

	if (poll (pfd, 1, 0) >= 0)
	{
		len = read (STDIN_FILENO, text, sizeof(text));
		if (len < 1)
			return NULL;
	}
	else
		return NULL;

	text[len - 1] = 0;
	return text;
}

double Sys_GetTime (void)
{
	static int 		starttime;
	struct timeval 		tp;
	struct timezone 	tzp;

	gettimeofday (&tp, &tzp);

	if (starttime == 0)
	{
		starttime = tp.tv_sec;
		return tp.tv_usec / 1000000.0;
	}

	return (double)((tp.tv_sec - starttime) + (tp.tv_usec / 1000000.0));	
}

char Sys_GetKey (void)
{
	struct pollfd	pfd[1];
	
	pfd[0].fd = STDIN_FILENO;
	pfd[0].events = POLLIN;

	if (poll (pfd, 1, 0) > 0)
	{
		return getchar ();
	}

	return 0;
}
int main (void)
{
	char ch;

	fcntl (STDIN_FILENO, F_SETFL, O_NONBLOCK);

	
	while (Sys_GetTime () < 10)
	{
		ch = Sys_GetKey ();
		if (ch)
			printf ("'%c'\n", ch);
	}
	return 0;
}
