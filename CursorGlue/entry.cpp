#include "Glue.h"

#ifdef _Console
int main()
#else
int  WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
#endif // _Console
{
	for (;; Sleep(100))// sleep makes the app less resource hungry
	{
		Glue::GlueWindow();
	}
	return 0;
}