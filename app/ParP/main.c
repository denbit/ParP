#pragma warning(disable:4068)

#include<stdio.h>
#include "dll.h"
#include "lab1.h"
#include "lab2.h"

int main(int argc, char* argv[]) {
	/*printf(" count is %d \n", argc);
	for (int i = 0; i < argc; i++) {
		puts(argv + i);
	}
	gets();*/
	
	//DisplayHelloFromMyDLL();
	load();
	printf(" it is %d words",calculate());
	load();
	load();
	load();
	getchar();
	return 0;
}