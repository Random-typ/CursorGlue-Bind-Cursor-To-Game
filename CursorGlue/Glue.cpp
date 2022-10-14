#include "Glue.h"
void Glue::LockCursor(HWND _window) {
	RECT rect;
	GetClientRect(_window, &rect);

	POINT TL = { rect.left, rect.top },
		BR = { rect.right, rect.bottom };

	MapWindowPoints(_window, nullptr, &TL, 1);
	MapWindowPoints(_window, nullptr, &BR, 1);

	rect = { TL.x, TL.y, BR.x, BR.y };

	ClipCursor(&rect);
}

void Glue::UnlockCursor() {
	ClipCursor(NULL);
}

void Glue::GlueWindow()
{
	QUERY_USER_NOTIFICATION_STATE query;
	if (SHQueryUserNotificationState(&query) != S_OK)
	{
		// error handling
		return;
	}

	// check if fullscreen 3D application is running
	if (query != QUNS_RUNNING_D3D_FULL_SCREEN)
	{
		return;
	}

	// get foreground window
	HWND hwnd = GetForegroundWindow();

	// lock window
	LockCursor(hwnd);

	// wait until foregournd window is not in foreground anymore
	for (; hwnd == GetForegroundWindow(); Sleep(50));// sleep makes the app less resource hungry

	// Unlock Cursor
	UnlockCursor();
}