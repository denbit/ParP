#include <stdio.h>
extern "C"
{
	__declspec(dllexport) void DisplayHelloFromMyDLL()
	{
		printf("Hello DLL.\n");
	}
}