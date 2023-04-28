#pragma once
#include <Windows.h>

class LineEditHandler
{
	HWND hWndRed;
	HWND hWndGreen;
	HWND hWndBlue;
public:
	enum {
		ID_RED = 201,
		ID_GREEN,
		ID_BLUE
	};
	void init(HWND hWndParent, HINSTANCE hInst, int x, int y);
	int execute(int idCommand);
};