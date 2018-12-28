//FIXME: for testing only
#include <Windows.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "typedefs.h"
#include "d_bitmap.h"
#include "draw.h"
#include "vid.h"

void (*D_DrawBitmap) (int x, int y, bitmap_t* bitmap);

//FIXME: instead of reading a pixel. Read three bytes. Also account for different bpp counts
//FIXME: need to account if noColors > 0. Use the color table
//FIXME: loading bitmap upside down
int bmperror = 0;

//FIXME: find a place for this
void PrintBinary (uint32_t* data)
{
	uint32_t	x=0x01 << 31;

	while (x)
	{
		if (x & *data)
			printf ("1");
		else
			printf ("0");

		x = x>>1;
	}
	printf ("\n");
}

int IsValidBitmap (const char* file)
{
	int			ret = 1;
	uint16_t	type;
	FILE* fp	= fopen (file, "r");

	if (fp == NULL)
	{
		bmperror = BMPERROR_FILEOPENFAIL;
		return -1;
	}

	fread (&type, sizeof (uint16_t), 1, fp);
	if (type != 0x424d && type != 0x4d42)
	{
		bmperror = BMPERROR_INVALIDFILEFORMAT;
		fclose (fp);
		return -1;
	}
	fclose (fp);

	return ret;
}

int GetFileHeader (const char* file, bitmapfileheader_t* ret)
{
	FILE* fp = fopen (file, "r");

	if (fp==NULL)
	{
		bmperror = BMPERROR_FILEOPENFAIL;
		return -1;
	}

	if (fread (ret, sizeof (bitmapfileheader_t), 1, fp) != 1)
	{
		fclose (fp);
		return -1;
	}

	fclose (fp);
	return 0;
}

int GetInfoHeader (const char* file, bitmapv5header_t* ret)
{
	uint32_t	sInfoHeader = 0;
	FILE* fp = fopen (file, "r");

	memset (ret, 0, sizeof (bitmapv5header_t));

	if (fp == NULL)
	{
		bmperror = BMPERROR_FILEOPENFAIL;
		return -1;
	}
	fseek (fp, sizeof (bitmapfileheader_t), SEEK_SET);

	if (fread (&sInfoHeader, sizeof (uint32_t), 1, fp) != 1)
	{
		fclose (fp);
		return -1;
	}

	fseek (fp, sizeof (bitmapfileheader_t), SEEK_SET);

	switch (sInfoHeader)
	{
		case BMPCOREHEADERSIZE:
			{
				bitmapcoreheader_t bmch;

				fread (&bmch, sizeof (bitmapcoreheader_t), 1, fp);

				ret->bV5Size		= bmch.bcSize;
				ret->bV5Width		= bmch.bcWidth;
				ret->bV5Height		= bmch.bcHeight;
				ret->bV5Planes		= bmch.bcPlanes;
				ret->bV5BitCount	= bmch.bcBitCount;
			}
			break;

		case BMPINFOHEADERSIZE:
			{
				bitmapinfoheader_t	bmih;

				fread (&bmih, sizeof (bitmapinfoheader_t), 1, fp);
				
				ret->bV5Size			= bmih.biSize;
				ret->bV5Width 			= bmih.biWidth;
				ret->bV5Height			= bmih.biHeight;
				ret->bV5Planes			= bmih.biPlanes;
				ret->bV5BitCount		= bmih.biBitCount;
				ret->bV5Compression		= bmih.biCompression;
				ret->bV5SizeImage		= bmih.biSizeImage;
				ret->bV5XPelsPerMeter	= bmih.biXPelsPerMeter;
				ret->bV5YPelsPerMeter	= bmih.biYPelsPerMeter;
				ret->bV5ClrUsed			= bmih.biClrUsed;
				ret->bV5ClrImportant	= bmih.biClrImportant;
			}
			break;

		case BMPV4HEADERSIZE:
			{
				bitmapv4header_t bmv4h;

				fread (&bmv4h, sizeof (bitmapv4header_t), 1, fp);
				ret->bV5Size 				= bmv4h.bV4Size;
				ret->bV5Width 				= bmv4h.bV4Width;
				ret->bV5Height				= bmv4h.bV4Height;
				ret->bV5Planes				= bmv4h.bV4Planes;
				ret->bV5BitCount			= bmv4h.bV4BitCount;
				ret->bV5Compression			= bmv4h.bV4Compression;
				ret->bV5SizeImage			= bmv4h.bV4SizeImage;
				ret->bV5XPelsPerMeter		= bmv4h.bV4XPelsPerMeter;
				ret->bV5YPelsPerMeter		= bmv4h.bV4YPelsPerMeter;
				ret->bV5ClrUsed				= bmv4h.bV4ClrUsed;
				ret->bV5ClrImportant		= bmv4h.bV4ClrImportant;
				ret->bV5RedMask				= bmv4h.bV4RedMask;
				ret->bV5GreenMask			= bmv4h.bV4GreenMask;
				ret->bV5BlueMask			= bmv4h.bV4BlueMask;
				ret->bV5AlphaMask			= bmv4h.bV4AlphaMask;
				ret->bV5CSType				= bmv4h.bV4CSType;
				ret->bV5Endpoints.ciexyzRed.ciexyzX	= bmv4h.bV4Endpoints.ciexyzRed.ciexyzX;
				ret->bV5Endpoints.ciexyzRed.ciexyzY	= bmv4h.bV4Endpoints.ciexyzRed.ciexyzY;
				ret->bV5Endpoints.ciexyzRed.ciexyzZ	= bmv4h.bV4Endpoints.ciexyzRed.ciexyzZ;
				ret->bV5Endpoints.ciexyzGreen.ciexyzX	= bmv4h.bV4Endpoints.ciexyzGreen.ciexyzX;
				ret->bV5Endpoints.ciexyzGreen.ciexyzY	= bmv4h.bV4Endpoints.ciexyzGreen.ciexyzY;
				ret->bV5Endpoints.ciexyzGreen.ciexyzZ	= bmv4h.bV4Endpoints.ciexyzGreen.ciexyzZ;
				ret->bV5Endpoints.ciexyzBlue.ciexyzX	= bmv4h.bV4Endpoints.ciexyzBlue.ciexyzX;
				ret->bV5Endpoints.ciexyzBlue.ciexyzY	= bmv4h.bV4Endpoints.ciexyzBlue.ciexyzY;
				ret->bV5Endpoints.ciexyzBlue.ciexyzZ	= bmv4h.bV4Endpoints.ciexyzBlue.ciexyzZ;
				ret->bV5GammaRed			= bmv4h.bV4GammaRed;
				ret->bV5GammaGreen			= bmv4h.bV4GammaGreen;
				ret->bV5GammaBlue			= bmv4h.bV4GammaBlue;
			}
			break;

		case BMPV5HEADERSIZE:
			fread (ret, sizeof (bitmapv5header_t), 1, fp);
			break;
	}

	fclose (fp);
	return 0;
}

int GetColourTable (const char* file, bitmapv5header_t* bmpInfo)
{
	if (bmpInfo->bV5ClrUsed > 0)
	{
		//FIXME: implement a color table
		//Load the color table
		//not supporting it right now
		bmperror = BMPERROR_INVALIDFILEFORMAT;
		return -1;
	}

	return 0;
}

int DecompressBitmap (const char* file, bitmapv5header_t* bmpInfo)
{

}

int MyLoadBitmap (bitmap_t* ret, const char* file)
{
	FILE*				fp;
	bitmapfileheader_t	bmfh;
	bitmapv5header_t	bmih;
	int					sClrTable, sRow, sPadding;

	bmperror = 0;

	if (IsValidBitmap (file) == 0 || bmperror)
		return -1;

	if (GetFileHeader (file, &bmfh) == -1)
		return -1;

	if (GetInfoHeader (file, &bmih) == -1)
		return -1;

	fp = fopen (file, "r");
	if (fp == NULL)
		return -1;

	sRow = (bmih.bV5BitCount / 8) * bmih.bV5Width;
	sPadding = 0;

	if (sRow % 4 != 0)
	{
		sPadding = 4 - (sRow % 4);
		sRow += sPadding;
	}

	if (bmih.bV5Compression == BMCMP_RGB)
	{
		if (bmih.bV5BitCount == 32)
		{
			//uncompressed 32bit
			int 		i, j, cnt=0;
			uint8_t		r, g, b, alpha;
			pixel32_t*	p =0;

			ret->height = bmih.bV5Height;
			ret->width	= bmih.bV5Width;
			ret->bpp	= bmih.bV5BitCount;
			ret->planes	= bmih.bV5Planes;

			//FIXME: memory manager instead
			ret->data = malloc (bmih.bV5Height * bmih.bV5Width * sizeof (pixel32_t));
			p = (pixel32_t*)ret->data;

			if (ret->data == NULL)
			{
				bmperror = BMPERROR_MEMALLOCFAIL;
				return -1;
			}

			for (i=bmih.bV5Height - 1; i>=0 ; i--)
			{
				fseek (fp, bmfh.bfOffBits + (i * sRow), SEEK_SET);
				for (j=0 ; j<bmih.bV5Width ; j++)
				{
					fread (&b, sizeof (uint8_t), 1, fp);
					fread (&g, sizeof (uint8_t), 1, fp);
					fread (&r, sizeof (uint8_t), 1, fp);
					fread (&alpha, sizeof (uint8_t), 1, fp);
					p->r = b;
					p->g = g;
					p->b = r;
					p->alpha=alpha;

					p++;
					cnt++;	
				}

			}	
		}
		else if (bmih.bV5BitCount == 24)
		{
			//uncompressed 24bit
			int 			i, j, cnt=0;
			uint8_t			r, g, b;
			pixel24_t*		p =0;

			ret->height = bmih.bV5Height;
			ret->width	= bmih.bV5Width;
			ret->bpp	= bmih.bV5BitCount;
			ret->planes	= bmih.bV5Planes;
			//FIXME: memory manager instead
			ret->data = malloc (bmih.bV5Height * bmih.bV5Width * sizeof (pixel24_t));
			p = (pixel24_t*)ret->data;

			if (ret->data == NULL)
			{
				bmperror = BMPERROR_MEMALLOCFAIL;
				return -1;
			}

			for (i=bmih.bV5Height - 1; i>=0 ; i--)
			{
				fseek (fp, bmfh.bfOffBits + (i * sRow), SEEK_SET);
				for (j=0 ; j<bmih.bV5Width ; j++)
				{
					fread (&b, sizeof (uint8_t), 1, fp);
					fread (&g, sizeof (uint8_t), 1, fp);
					fread (&r, sizeof (uint8_t), 1, fp);
					p->r = b;
					p->g = g;
					p->b = r;
					p->padding=0;

					p++;
					cnt++;	
				}

			}	
		}
		else if (bmih.bV5BitCount == 16)
		{
			//uncompressed 16bit
		}
		else if (bmih.bV5BitCount == 8)
		{
			//uncompressed 8bit
		}
		else if (bmih.bV5BitCount == 4)
		{
			//uncompressed 4bit
		}
		else if (bmih.bV5BitCount == 1)
		{
			//uncompressed monochrome
		}
	}
	else if (bmih.bV5Compression == BMCMP_RLE4)
	{
		//4 bpp
		if (bmih.bV5BitCount == 4)
		{
			//Run length encoded 4bit
		}
		else
		{
			bmperror = BMPERROR_INVALIDBITCOUNT;
			return -1;
		}
	}
	else if (bmih.bV5Compression == BMCMP_RLE8)
	{
		//8bpp
		if (bmih.bV5BitCount == 8)
		{	//Run length encoded 8bit
		}	
		else
		{
			bmperror = BMPERROR_INVALIDBITCOUNT;
			return -1;
		}
	}
	else if (bmih.bV5Compression == BMCMP_BITFIELDS)
	{
		//16 and 32 bpp
		if (bmih.bV5BitCount == 32)
		{






		}		
		else if (bmih.bV5BitCount == 16)
		{
		}
		else
		{
			bmperror = BMPERROR_INVALIDBITCOUNT;
			return -1;
		}
	}
	else if (bmih.bV5Compression == BMCMP_JPEG)
	{
		bmperror = BMPERROR_FRMTNOTSUPPORTED;
		return -1;
	}
	else if (bmih.bV5Compression == BMCMP_PNG)
	{
		bmperror = BMPERROR_FRMTNOTSUPPORTED;
		return -1;
	}

	fclose (fp);
	return 0;
}

void __DrawBitmap8 (int x, int y, bitmap_t* bitmap)
{

}

void __DrawBitmap16 (int x, int y, bitmap_t* bitmap)
{

}

void __DrawBitmap24 (int x, int y, bitmap_t* bitmap)
{

}

//FIXME: optimize for 32 bit and 64 bit systems
void __DrawBitmap32 (int x, int y, bitmap_t* bitmap)
{
	int		i, j, cnt=0;
	pixel32_t* vidbufp = (pixel32_t*)vid.buffer;
	pixel32_t* bmpbufp = (pixel32_t*)bitmap->data;

	for ( i=0 ; i<bitmap->height; i++)
	{
		for ( j=0 ; j<bitmap->width ; j++, cnt++)
		{
			*(vidbufp + ((i + y) * vid.width) + x + j) = *(bmpbufp + (i * bitmap->width) + j);
		}
	}
}

int FreeBitmap (bitmap_t* bitmap)
{
	//FIXME: use memory manager
	free (bitmap->data);
	return 0;
}