#ifndef __D_LINE_H__
#define __D_LINE_H__
#pragma once

void __DrawLine32 (int x0, int y0, int x1, int x2, void* color);
void __DrawLine24 (int x0, int y0, int x1, int x2, void* color);
void __DrawLine16 (int x0, int y0, int x1, int x2, void* color);
void __DrawLine8 (int x0, int y0, int x1, int x2, void* color);
void __DrawLine4 (int x0, int y0, int x1, int x2, void* color);
void __DrawLine1 (int x0, int y0, int x1, int x2, void* color);
#endif