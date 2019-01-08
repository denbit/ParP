#define _CRT_SECURE_NO_WARNINGS
#include"lab1.h"
#include<Windows.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int calculate() {
	char  strr[COUNT];
	//memset(strr, 0, sizeof(char) * COUNT);
	get_string(strr);
	int amount=0;
	for (unsigned len = 0; len < strlen(strr); len++) {
		//printf("%d\n", strlen(strr));
		//printf("%c %d\n", strr[len], strr[len]);
		if (isalpha(strr[len])) {
			if (isspace(strr[len + 1])||strr[len+1]=='\0') {
				amount++;
			}
		}
	}
	return amount;

}

void get_string(char * str)
{
	char strs[COUNT];
	puts("You have entered: ");
	puts(gets_s(strs, COUNT));
	strcpy_s(str,COUNT, strs);
}



typedef int  DLLFUNC(char *);


 void performDllCall() {
	HINSTANCE dll;
	DLLFUNC * hello;
	char input[COUNT];	
	dll = LoadLibrary("dll.dll");
	if (dll != NULL) {
		hello = (DLLFUNC*)GetProcAddress(dll, "calculateFromDLL");
		
			get_string(input);
			printf(" word counts %d \n", hello(input));
				
	}
	else
	{
		puts("Lib wasn't found!\n");
	}
	FreeLibrary(dll);
}

 int checkCRC(char * dll)
 {
	 DWORD crc = 0;
	 DWORD high, low, data, real;
	 TCHAR FN[MAX_PATH] = "dll.crc";  //
	 HANDLE  hFile;
	
	 hFile = CreateFile(dll, GENERIC_READ , FILE_SHARE_READ, 0,		 OPEN_EXISTING, 0, 0);

	 if (hFile == INVALID_HANDLE_VALUE)
	 {
		 printf("File wasn't found!");
			 return 0;
	 }
	 low = GetFileSize(hFile, &high);

	 int count = low / 2;
	 int mem = low % 2;

	 for (int i = 0; i < count; i++)
	 {
		 ReadFile(hFile, &data, 2, &real, 0);
		 crc = (crc + data) % 0xffff;
	 }
	 data = 0;
	 ReadFile(hFile, &data, mem, &real, 0);
	 crc = (crc + data) % 0xffff; 
	 printf("%d\n", crc);
		HANDLE wrtFile = CreateFile(FN,  GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, 0, 0);
	 WriteFile(wrtFile, &crc, sizeof(crc), &real, 0);
	 CloseHandle(wrtFile);


	 return 0;
 }

