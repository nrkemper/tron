#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "wmanager.h"
#include "vid.h"

extern HINSTANCE	hInstance;
extern int			nCmdShow;
extern HWND			hwnd;
extern MSG			msg;
extern WNDCLASSEX	wc;
extern const char	szClassName[];

LRESULT CALLBACK WndProc (HWND lHwnd, UINT lMsg, WPARAM wParam, LPARAM lParam);

void WM_Init (void)
{
	wc.cbSize			= sizeof (WNDCLASSEX);
	wc.style			= 0;
	wc.lpfnWndProc		= WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= LoadIcon (NULL, IDI_APPLICATION);
	wc.hCursor			= LoadCursor (NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= szClassName;
	wc.hIconSm			= LoadIcon (NULL, IDI_APPLICATION);


	//FIXME: console printf
	if (RegisterClassEx (&wc) == 0)
	{
		printf ("ERROR: unable to register class. Exiting.\n");
		exit (-1);
	}

	WM_CreateWindow (100, 100, 500, 300, "Title of My Window", nCmdShow);
}

void WM_CreateWindow (int x, int y, int width, int height, const char* title, int lnCmdShow)
{
	hwnd = CreateWindowEx (
		0,
		szClassName,
		title,
		WS_POPUP,
		x, y,
		width, height,
		NULL, 
		NULL,
		hInstance,
		NULL);

	//FIXME: console printf
	if (hwnd == NULL)
	{
		printf ("ERROR: Unable to create window. Exiting.\n");
		exit (-1);
	}

	vid.width = width;
	vid.height = height;

	//FIXME: not sure how to do this
	vid.bpp = 32;
	vid.buffer = 0;
	VID_CreateBuffer ();
}

void WM_DestroyWindow (void)
{
	DestroyWindow (hwnd);
	VID_Shutdown ();
}