#ifndef __D_RECT_H__
#define __D_RECT_H__
#pragma once

typedef struct rect_t
{
	int		x, y;
	int		width, height;
} rect_t;

void __DrawRect32 (int x, int y, int width, int height, void* bgColour);
void __DrawRect24 (int x, int y, int width, int height, void* bgColour);
void __DrawRect16 (int x, int y, int width, int height, void* bgColour);
void __DrawRect8 (int x, int y, int width, int height, void* bgColour);
#endif