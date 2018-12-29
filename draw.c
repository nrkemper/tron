#include "draw.h"
#include "vid.h"
#include "d_bitmap.h"
#include "d_line.h"
#include "d_rect.h"

void D_Init (void)
{
	switch (vid.bpp)
	{
		case 32:
			D_DrawBitmap	= __DrawBitmap32;
			D_DrawLine		= __DrawLine32;
			D_DrawRect		= __DrawRect32;
			break;

		case 24:
			D_DrawBitmap	= __DrawBitmap24;
			D_DrawLine		= __DrawLine24;
			D_DrawRect		= __DrawRect24;
			break;

		case 16:
			D_DrawBitmap	= __DrawBitmap16;
			D_DrawLine		= __DrawLine16;
			D_DrawRect		= __DrawRect16;
			break;

		case 8:
			D_DrawBitmap	= __DrawBitmap8;
			D_DrawLine		= __DrawLine8;
			D_DrawRect		= __DrawRect8;
			break;
	}
}