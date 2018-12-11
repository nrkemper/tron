#include "draw.h"
#include "entity.h"
#include <ncurses.h>

//FIXME: need to make this better
void D_DrawEntity (entity_t* entity)
{
	mvaddch (entity->y.pf, entity->x.pf, entity->icon);
}

void D_DrawEntities (void)
{
	entity_t*	p = entitylist;

	while (p)
	{
		D_DrawEntity (p);
		p=p->next;
	}
}
void D_UpdateScreen (void)
{
	refresh ();
}
