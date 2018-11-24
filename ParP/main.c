#pragma warnings(disable)

#include<stdio.h>
#include <windows.h>
#include "Header.h"

int main(int argc, char* argv[]) {
	/*printf(" count is %d \n", argc);
	for (int i = 0; i < argc; i++) {
		puts(argv + i);
	}
	gets();*/
	
	DisplayHelloFromMyDLL();
	gets();

	return 0;
}