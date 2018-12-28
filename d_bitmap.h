#ifndef __D_BITMAP_H__
#define __D_BITMAP_H__
#pragma once

#define BMPCOREHEADERSIZE		12
#define BMPINFOHEADERSIZE		40
#define BMPV4HEADERSIZE			108
#define BMPV5HEADERSIZE			124

#define BMCMP_RGB			0
#define BMCMP_RLE4			1
#define BMCMP_RLE8			2
#define BMCMP_BITFIELDS			3
#define BMCMP_JPEG			4
#define BMCMP_PNG			5

#define BMPERROR_FILEOPENFAIL		-1
#define BMPERROR_INVALIDFILEFORMAT	-2
#define BMPERROR_FRMTNOTSUPPORTED	-3
#define BMPERROR_INVALIDBITCOUNT	-4
#define BMPERROR_MEMALLOCFAIL		-5

#define BMPFMT_8BIT3R3G2B		1
#define BMPFMT_8BIT3R2G3B		2
#define BMPFMT_8BIT2R3G3B		3
#define BMPFMT_16BIT6R5G5B		4
#define BMPFMT_16BIT5R6G5B		5
#define BMPFMT_16BIT5R5G6B		6
#define BMPFMT_16BIT5R5G5B		7
#define BMPFMT_24BITRGBX		8
#define BMPFMT_24BITBGRX		9
#define BMPFMT_24BITXRGB		10
#define BMPFMT_24BITXBGR		11
#define BMPFMT_32BITRGBA		12
#define BMPFMT_32BITBGRA		13
#define BMPFMT_32BITARGB		14
#define BMPFMT_32BITABGR		15

#include <stdint.h>

#pragma pack (push, 1)
typedef struct bitmapfileheader_t
{
	uint16_t	bfType;
	uint32_t	bfSize;
	uint16_t	bfReserved1;
	uint16_t	bfReserved2;
	uint32_t	bfOffBits;
} bitmapfileheader_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct bitmapcoreheader_t
{
	uint32_t	bcSize;
	uint16_t	bcWidth;
	uint16_t	bcHeight;
	uint16_t	bcPlanes;
	uint16_t	bcBitCount;
} bitmapcoreheader_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct bitmapinfoheader_t
{
	uint32_t 	biSize;
	int32_t		biWidth;
	int32_t		biHeight;
	uint16_t	biPlanes;
	uint16_t	biBitCount;
	uint32_t	biCompression;
	uint32_t	biSizeImage;
	int32_t		biXPelsPerMeter;
	int32_t		biYPelsPerMeter;
	uint32_t	biClrUsed;
  	uint32_t	biClrImportant;
} bitmapinfoheader_t;
#pragma pack (pop)


#pragma pack (push, 1)
typedef struct ciexyz_t
{
	float	ciexyzX;
	float	ciexyzY;
	float	ciexyzZ;
} ciexyz_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct ciexyztriple_t
{
	ciexyz_t	ciexyzRed;
	ciexyz_t	ciexyzGreen;
	ciexyz_t	ciexyzBlue;
} ciexyztriple_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct bitmapv4header_t
{
	uint32_t        bV4Size;
	int32_t         bV4Width;
	int32_t         bV4Height;
	uint16_t	bV4Planes;
	uint16_t	bV4BitCount;
	uint32_t	bV4Compression;
	uint32_t        bV4SizeImage;
	int32_t         bV4XPelsPerMeter;
	int32_t         bV4YPelsPerMeter;
	uint32_t        bV4ClrUsed;
	uint32_t        bV4ClrImportant;
	uint32_t        bV4RedMask;
	uint32_t        bV4GreenMask;
	uint32_t        bV4BlueMask;
	uint32_t        bV4AlphaMask;
	uint32_t        bV4CSType;
	ciexyztriple_t	bV4Endpoints;
	uint32_t        bV4GammaRed;
	uint32_t        bV4GammaGreen;
	uint32_t        bV4GammaBlue;
} bitmapv4header_t;
#pragma pack (pop)

#pragma pack (push, 1)
typedef struct bitmapv5header_t
{
	uint32_t        bV5Size;
	int32_t         bV5Width;
	int32_t         bV5Height;
	uint16_t	bV5Planes;
	uint16_t	bV5BitCount;
	uint32_t	bV5Compression;
	uint32_t        bV5SizeImage;
	int32_t         bV5XPelsPerMeter;
	int32_t         bV5YPelsPerMeter;
	uint32_t        bV5ClrUsed;
	uint32_t        bV5ClrImportant;
	uint32_t        bV5RedMask;
	uint32_t        bV5GreenMask;
	uint32_t        bV5BlueMask;
	uint32_t        bV5AlphaMask;
	uint32_t        bV5CSType;
	ciexyztriple_t	bV5Endpoints;
	uint32_t        bV5GammaRed;
	uint32_t        bV5GammaGreen;
	uint32_t        bV5GammaBlue;
  	uint32_t        bV5Intent;
  	uint32_t        bV5ProfileData;
  	uint32_t        bV5ProfileSize;
  	uint32_t        bV5Reserved;
} bitmapv5header_t;
#pragma pack (pop)

typedef struct bitmap_t
{
	int			width, height;
	char		bpp;
	char		planes;
	void*		data;
	void*		mask;
	void*		background;
} bitmap_t;

extern int bmperror;

extern void (*D_DrawBitmap) (int x, int y, bitmap_t* bitmap);
//FIXME: instead of reading a pixel. Read three bytes. Also account for different bpp counts
void PrintBinary (uint32_t* data);
int MyLoadBitmap (bitmap_t* ret, const char* file);
void __DrawBitmap8 (int x, int y, bitmap_t* bitmap);
void __DrawBitmap16 (int x, int y, bitmap_t* bitmap);
void __DrawBitmap24 (int x, int y, bitmap_t* bitmap);
void __DrawBitmap32 (int x, int y, bitmap_t* bitmap);
int FreeBitmap (bitmap_t* bitmap);

#endif

