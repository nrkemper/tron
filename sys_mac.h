#ifndef __SYSMAC_H__
#define __SYSMAC_H__

#pragma once

#include <ncurses.h>

int Sys_GetKey (void)
{
	return getch ();
}

#endif
