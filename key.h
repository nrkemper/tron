#ifndef __KEY_H__
#define __KEY_H__

#pragma once

#include <ncurses.h>
#include "event.h"

#define K_TAB		9
#define K_ENTER		10
#define K_ESCAPE	27
#define K_SPACE		32

#define K_BACKSPACE	127
#define K_INSERT	128
#define K_DELETE	129
#define K_HOME		130
#define K_END		131
#define K_PGUP		132
#define K_PGDOWN	133
#define K_UPARROW	134
#define K_DOWNARROW	135
#define K_LEFTARROW	136
#define K_RIGHTARROW	137

#define K_F1		138
#define K_F2		139
#define K_F3		140
#define K_F4		141
#define K_F5		142
#define K_F6		143
#define K_F7		144
#define K_F8		145
#define K_F9		146
#define K_F10		147
#define K_F11		148
#define K_F12		149

void K_Init (void);
int K_GetKey (void);
int K_ProcessKey (int key);
void K_GetUserInput (void);
void K_Shutdown (void);

#endif 
