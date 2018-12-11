#ifndef __SYS_H__
#define __SYS_H__
#pragma once

/*
 *
 * 	System dependent functions
 *
 */

void Sys_Init ();
int Sys_GetKey (void);
int Sys_ProcessKey (int key);
void Sys_Shutdown (void);
#endif