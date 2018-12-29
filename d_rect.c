#include "d_rect.h"
#include "vid.h"
#include "typedefs.h"
void (*D_DrawRect) (int x, int y, int width, int height, void* bgColour);

void __DrawRect32 (int x, int y, int width, int height, void* bgColour)
{
	int		i, j, endX, endY;
	pixel32_t* p, *colour = (pixel32_t*)bgColour;

	p = (pixel32_t*)vid.buffer;

	if (x > (int)vid.width)
		return;

	if (y > (int)vid.height)
		return;

	if (x < 0)
	{
		if (width + x > 0)
		{
			width += x;
			x=0;
		}
		else
			return;
	}

	if (y < 0)
	{
		if (y + height > 0)
		{
			height += y;
			y=0;
		}
		else
			return;
	}

	if (x + width > vid.width)
		width = x + width - vid.width;

	if (y + height > vid.height)
		height = y + height - vid.height;

	endX = x + width;
	endY = y + height;

	for (i=0 ; i<endY; i++)
	{
		for (j=0 ; j<endX ; j++)
		{
			*(p + (i * vid.width) + j) = *colour;
		}
	}
}

void __DrawRect24 (int x, int y, int width, int height, void* bgColour)
{

}

void __DrawRect16 (int x, int y, int width, int height, void* bgColour)
{

}

void __DrawRect8 (int x, int y, int width, int height, void* bgColour)
{

}