#include <Windows.h>
#include <stdlib.h>
#include "draw.h"
#include "vid.h"
#include "wmanager.h"

//FIXME: for testing only
#include "typedefs.h"

HINSTANCE	hInstance;
int			nCmdShow;
HWND		hwnd;
MSG			msg;
WNDCLASSEX	wc;
const char	szClassName[] = "My Class";

LRESULT CALLBACK WndProc (HWND lHwnd, UINT lMsg, WPARAM wParam, LPARAM lParam)
{
	switch (lMsg)
	{
		case WM_KEYDOWN:
			{
				switch (wParam)
				{
					case 'q':
					case 'Q':
						WM_DestroyWindow ();
						break;
				}
			}
			break;

		case WM_CREATE:
			break;
		case WM_PAINT:
		{
			HDC hdc, hdcMem;
			HBITMAP hbmBuffer, hbmOld;
			PAINTSTRUCT ps;
			RECT	client, screen;
			
			hdc = BeginPaint (hwnd, &ps);

			hdcMem = CreateCompatibleDC (hdc);
			if (hdcMem == NULL)
			{
				MessageBox (NULL, "Unable to create compatible DC", "ERROR", MB_OK);
			}

			GetClientRect (lHwnd, &client);
			GetWindowRect (lHwnd, &screen);

			hbmBuffer = CreateBitmap (vid.width, vid.height, 1, vid.bpp, vid.buffer);
			if (hbmBuffer == NULL)
			{
				MessageBox (NULL, "Unable to create bitmap", "ERROR!", MB_OK);
			}

			hbmOld = (HBITMAP)SelectObject (hdcMem, hbmBuffer);
			if (hbmOld == HGDI_ERROR || hbmOld == NULL)
				MessageBox (NULL, "unable to select bitmap", "ERROR", MB_OK);

			if (BitBlt (hdc, 0, 0, vid.width, vid.height, hdcMem, 0, 0, SRCCOPY) == 0)
			{
				MessageBox (NULL, "Unable to render buffer", "ERROR!", MB_OK);
			}

			SelectObject (hdcMem, hbmOld);

			DeleteDC (hdcMem);
			DeleteObject (hbmBuffer);
			EndPaint (hwnd, &ps);
		}
		break;

		case WM_CLOSE:
			WM_DestroyWindow ();
		break;
		case WM_DESTROY:
			exit (0);
		break;
		default:
			return DefWindowProc (lHwnd, lMsg, wParam, lParam);
		break;
	}
}

int CALLBACK WinMain (HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int lnCmdShow)
{
	//FIXME: for testing only
	pixel32_t color;
	color.r = 23;
	color.g = 95;
	color.b = 231;
	color.alpha = 0;

	hInstance = hInst;
	nCmdShow = lnCmdShow;
	
	WM_Init ();
	D_Init ();


	//FIXME: for testing only
	D_DrawRect (-10, -10, 15, 15, &color);

	ShowWindow (hwnd, lnCmdShow);
	UpdateWindow (hwnd);

	while (1)
	{
		if (PeekMessage (&msg, hwnd, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage (&msg);
			DispatchMessage (&msg);
		}

		/*while (1)
		{
			if (fStartTime - baseTime >= refreshRate)
				break;	
		}
		*/
		UpdateWindow (hwnd);
	}

	return 0;
}