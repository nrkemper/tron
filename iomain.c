#include "io.h"
#include <stdio.h>
#include <sys/time.h>
double Sys_GetTime ()
{
	struct timeval		tv;
	struct timezone		tz;
	static double 		stimesec;

	if(!stimesec)
	{
		gettimeofday (&tv, &tz);
		stimesec = tv.tv_sec + (tv.tv_usec/1000000.0);
		return stimesec;
	}

	
}
int main ()
{
	io_Init ();
	screen._buffer[0][0] = 5;
	io_RenderBuffer();
	getch ();
	io_Shutdown ();

	struct timeval		tv;
	struct timezone 	tz;
	
	double	starttime, curtime;

	gettimeofday (&tv, &tz);

	starttime = (double)tv.tv_sec + (tv.tv_usec/1000000.0);

	printf ("Start time: %f", starttime);
	/*while (x++ < 5)
	{
		gettimeofday (&tv, &tz);
		printf ("time: %lds, %dus\n", tv.tv_sec, tv.tv_usec);
	}*/
	return 0;
}
