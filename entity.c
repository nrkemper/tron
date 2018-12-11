#include <stdlib.h>
#include <stdio.h>
#include "entity.h"
#include "tstdlib.h"

entity_t* 	entitylist;
entity_t*	self;
int		numEntities;

//FIXME: update starting positions to the screen size
void ENTY_Init (void)
{
	entitylist = 0;

	vector_t x1 = { 5, 4 };
	vector_t y1 = { 10, 10 };

	vector_t x2 = { 20, 19 };
	vector_t y2 = { 10, 10 };
	
	self = ENTY_NewEntity ("SELF", x1, y1, ENTY_MOVE_SPEED, '^');
	ENTY_NewEntity ("Jorge", x2, y2, ENTY_MOVE_SPEED, '^');
}

//creates a new entity and returns a pointer to the new entity
entity_t* ENTY_NewEntity (const char* name, vector_t x, vector_t y, int speed, char icon)
{
	entity_t* newEnt = malloc (sizeof (entity_t));

	newEnt->x = x;
	newEnt->y = y;
	newEnt->id = numEntities++;
	newEnt->speed = speed;
	newEnt->icon = icon;

	T_memset (newEnt->name, 0, MAX_NAME_LENGTH + 1);
	T_strncpy (newEnt->name, name, MAX_NAME_LENGTH);

	newEnt->next = entitylist;
	entitylist = newEnt;

	return newEnt;
}

void ENTY_UpdateEntity (entity_t* entity)
{
	if (entity->x.pf == entity->x.p0)
	{
		//travelling vertically
		if (entity->y.pf > entity->y.p0)
		{
			//travelling down
			entity->y.p0 = entity->y.pf;
			entity->y.pf += entity->speed;
		}
		else
		{
			//travelling up
			entity->y.p0 = entity->y.pf;
			entity->y.pf -= entity->speed;
		}
	}
	else
	{
		//travelling horizontally
		if (entity->x.pf > entity->x.p0)
		{
			//travelling right
			entity->x.p0 = entity->x.pf;
			entity->x.pf += entity->speed;
		}
		else
		{
			//travelling left
			entity->x.p0 = entity->x.pf;
			entity->x.pf -= entity->speed;
		}
	}
}

void ENTY_UpdateEntities (void)
{
	entity_t*	p = entitylist;

	while(p)
	{
		ENTY_UpdateEntity (p);
		p=p->next;
	}
}

void ENTY_DrawEntity (entity_t* entity)
{
	//draw the entity to the buffer
}

int ENTY_DeleteEntity (int id)
{
	FILE* fp = fopen ("log.txt", "a+");
	
	if (fp == NULL)
		printf ("ERROR: failed to open log file in entity.c\n");

	entity_t* p = entitylist;
	entity_t* toDel;

	if (entitylist)
	{
		if (entitylist->id == id)
		{
			toDel = entitylist;
			entitylist = toDel->next;
		}
		else
		{
			while (p->next && p->next->id != id)
				p = p->next;

			if (p->next->id != id)
			{
				//FIXME: need log files here
				if (fp)
					fprintf (fp, "ERROR: could not delete entity <%d>\n", id);
				return -1;
			}
	
			toDel = p->next;
			p->next = toDel->next;
		}

		if (fp)
			fprintf (fp, "Deleted entity: <ID: %d> <Name: %s>\n", toDel->id, toDel->name);

		free (toDel);
		numEntities--;
	}

	return 0;
}

void ENTY_PrintEntities (void)
{
	entity_t* p;
	p = entitylist;

	while (p)
	{	
		printf ("<ID: %d> <Name: %s>\n", p->id, p->name);
		p = p->next;
	}
}
void ENTY_Shutdown (void)
{
	entity_t* toDel;
	//destroy the list of entities
	while (entitylist)
	{
		toDel = entitylist;
		entitylist = toDel->next;
		free (toDel);
	}
}
