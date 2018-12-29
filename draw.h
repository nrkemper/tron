#ifndef __DRAW_H__
#define __DRAW_H__
#pragma once
#include "d_bitmap.h"
#include "d_line.h"

void D_Init (void);
extern void (*D_DrawBitmap) (int x, int y, bitmap_t* bitmap);
extern void (*D_DrawLine) (int x0, int y0, int x1, int y1, void* color);
#endif