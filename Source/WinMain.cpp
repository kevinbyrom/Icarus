#include <windows.h>
#include "WinMain.h"
#include "Globals.h"


#define WINDOW_CLASS_NAME		"ICARUS_CLASS"
#define WINDOW_NAME				"ICARUS"


HWND MainWnd;
HINSTANCE MainInst;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
	{
	WNDCLASSEX wndclass;
	MSG msg;

	MainInst = hInstance;


	// Create the main window //

	memset(&wndclass, 0, sizeof(WNDCLASSEX));

	wndclass.cbSize			= sizeof(WNDCLASSEX);
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground	= NULL;
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= WINDOW_CLASS_NAME;
	

	if (!RegisterClassEx(&wndclass))
		return 0;


	MainWnd = CreateWindowEx(WS_EX_TOPMOST, WINDOW_CLASS_NAME, WINDOW_NAME, WS_POPUP | WS_VISIBLE, 
							 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							 NULL, NULL, hInstance, NULL);


	if (!MainWnd)
		return 0;


	// Initialize the game //

	if (!Game.Init())
		return 0;


	while(TRUE)
		{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
			}
		else
			{
			Game.DoLogic();
			}
		}


	// Shut down the game //

	Game.ShutDown();


	return (msg.wParam);
	}




LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
	switch(msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}


	return DefWindowProc(hWnd, msg, wParam, lParam);
	}
