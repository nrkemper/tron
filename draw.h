#ifndef __DRAW_H__
#define __DRAW_H__
#pragma once

#include "entity.h"

//FIXME: get rid of these double functions somehow. Doesn't make sense to call a function that calls another function
void D_DrawEntity (entity_t* entity);
void D_DrawEntities (void);
void D_UpdateScreen (void);
#endif
