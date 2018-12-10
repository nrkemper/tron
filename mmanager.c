#include "mmanager.h"

memblock_t*	mem;
int		memsize;

void MMGR_Init (void* buf, int size)
{
	mem = buf;
	memsize = size;
	mem->size = size;
	mem->next = 0;
}

void* MMGR_Alloc (int size)
{
	return (void*)mem;
}
