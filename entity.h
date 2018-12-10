#ifndef __ENTITY_H__
#define __ENTITY_H__

#pragma once

#define MAX_NAME_LENGTH	16

typedef struct vector_t
{
	int	xf, x0;
} vector_t;

typedef struct entity_t
{
	vector_t 		x;
       	vector_t		y; 
	int 			id;
	char			name[MAX_NAME_LENGTH + 1];
	char			icon;
	struct entity_t*	next;
} entity_t;

extern entity_t* 	entitylist;
extern entity_t*	self;
extern int		numEntities;

void ENTY_Init (void);
entity_t* ENTY_NewEntity (const char* name, vector_t x, vector_t y, char icon);
void ENTY_DrawEntity (entity_t* entity);
int ENTY_DeleteEntity (int id);
void ENTY_PrintEntities (void);
void ENTY_Shutdown (void);
#endif
