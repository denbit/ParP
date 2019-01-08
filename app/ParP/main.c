#pragma warning(disable:4068)

#include<stdio.h>
#include "dll.h"
#include "lab1.h"
#include "lab2.h"
void perfrom_static_call(void);
void perform_dynamic_call(void);

int  main(int argc, char* argv[]) {
	/*perform_dynamic_call();
	perfrom_static_call();*/
	makecpy("test");
	char dll[] = "dll.dll";
	checkCRC(dll);
	if (argc < 2) {
char exePath[] = "C:\\Program Files\\WinRAR\\rar.exe";
runProcess(exePath);
	}
	
	else {
		runProcess(argv[1]);
	}
	
	getchar();
	return 0;
}

void perform_dynamic_call() {
	puts("staring DYNAMIC call");
	performDllCall();
}
void perfrom_static_call() {
	puts("staring STATIC call");
	int count;
	char sentence[COUNT];
	gets_s(sentence,COUNT);
	count=calculateFromDLL(sentence);
	printf(" it is %d words\n",count);
}