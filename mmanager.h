#ifndef __MMANAGER_H__
#define __MMANAGER_H__
#pragma once

void MMGR_Init (void* buf, int size);
void* MMGR_Alloc (int size);

typedef struct memblock_t
{
	int			size;
	int			pad;
	struct memblock_t*	next;
} memblock_t;

extern memblock_t*	mem;
extern int		memsize;
#endif
