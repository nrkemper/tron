#ifndef __WMANAGER_H__
#define __WMANAGER_H__
#pragma once

void WM_Init (void);
void WM_CreateWindow (int x, int y, int width, int height, const char* title, int lnCmdShow);
//void WM_QueryWindow (
void WM_DestroyWindow (void);
#endif