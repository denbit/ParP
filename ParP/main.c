#pragma warnings(disable)

#include<stdio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	printf(" count is %d \n", argc);
	for (int i = 0; i < argc; i++) {
		puts(argv + i);
	}
	gets();
	

	return 0;
}