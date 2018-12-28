#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__
#pragma once

#include <stdint.h>

#pragma pack (push, 1)
typedef struct pixel8_t
{
	uint8_t		rgb;
} pixel8_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct pixel16_t
{
	uint16_t	rgb;
} pixel16_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct pixel24_t
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		padding;
} pixel24_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct pixel32_t
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		alpha; 
} pixel32_t;
#pragma pack (pop)

#endif