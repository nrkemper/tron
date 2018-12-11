#ifndef __VID_H__
#define __VID_H__

typedef struct vid_t
{
	int	width, height;
	char**	buffer;
}vid_t;

extern vid_t	vid;

int VID_Init (void);
int VID_CreateVGA (int width, int height);
void VID_DestroyVGA (void);
int VID_Resize (int width, int height);
void VID_Shutdown (void);
#endif
