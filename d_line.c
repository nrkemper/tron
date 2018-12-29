#include "d_line.h"
#include "typedefs.h"
#include "vid.h"


#include <Windows.h>

void (*D_DrawLine) (int x0, int y0, int x1, int y1, void* color);

void __DrawLine32 (int x0, int y0, int x1, int y1, void* aColor)
{
	pixel32_t*	pixel, *p;
	int	x, y, xi, yi, dx, dy, D;

	p = (pixel32_t*)vid.buffer;

	if (x0 < 0)
		x0 = 0;

	if (x0 > vid.width - 1)
		x0 = vid.width - 1;

	if (y0 < 0)
		y0 = 0;

	if (y0 > vid.width - 1)
		y0 = vid.width - 1;

	if (x1 < 0)
		x1 = 0;

	if (x1 > vid.width - 1)
		x1 = vid.width - 1;

	if (y1 < 0)
		y1 = 0;

	if (y1 > vid.width - 1)
		y1 = vid.width - 1;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;

	if (dy < 0)
		yi = -1;

}

void __DrawLine24 (int x0, int y0, int x1, int y1, void* color)
{

}

void __DrawLine16 (int x0, int y0, int x1, int y1, void* color)
{

}

void __DrawLine8 (int x0, int y0, int x1, int y1, void* color)
{

}

void __DrawLine4 (int x0, int y0, int x1, int y1, void* color)
{

}

void __DrawLine1 (int x0, int y0, int x1, int y1, void* color)
{

}