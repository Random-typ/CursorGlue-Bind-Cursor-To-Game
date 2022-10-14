#pragma once
#include <Windows.h>
class Glue
{
public:
	static void LockCursor(HWND _window);

	static void UnlockCursor();

	static void GlueWindow();
};

