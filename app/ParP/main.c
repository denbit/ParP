#pragma warning(disable:4068)

#include<stdio.h>
#include "dll.h"
#include "lab1.h"

int main(int argc, char* argv[]) {
	/*printf(" count is %d \n", argc);
	for (int i = 0; i < argc; i++) {
		puts(argv + i);
	}
	gets();*/
	
	DisplayHelloFromMyDLL();
	printf(" it is %d words",calculate());
	getchar();
	return 0;
}