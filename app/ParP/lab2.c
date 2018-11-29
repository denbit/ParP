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