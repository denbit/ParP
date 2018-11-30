#include<Windows.h>
#include"lab2.h"
typedef UINT(CALLBACK* DLLFUNC)(void);


void load() {
	HINSTANCE dll;
	DLLFUNC hello;
	dll=LoadLibrary("dll.dll");
	if (dll != NULL) {
		hello = (DLLFUNC)GetProcAddress(dll, "DisplayHelloFromMyDLL");
		hello();
	}

}
#include <Windows.h>
int makecpy(char * ch) {
HANDLE fl=	CreateFile("test", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
if (fl == INVALID_HANDLE_VALUE) return 1;
DWORD count,temp;
ReadFile(fl, &count, sizeof(count), &temp, NULL);
if (sizeof(count) != temp) {
	CloseHandle(fl);
	return 1;
}
CloseHandle(fl);
return count;
}