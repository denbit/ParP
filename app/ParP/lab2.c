#include<Windows.h>
#include"lab2.h"
#include<stdio.h>
#include<tchar.h>
#include<string.h>
#define BUFSIZE 1024

char * getFullPath(const char * ch, char *ret) {
	char NPath[MAX_PATH];
	memset(NPath, 0, MAX_PATH);
	GetCurrentDirectory(MAX_PATH, NPath);
	//	puts(NPath);
	TCHAR slesh[] = "\\";
	_tcscat_s(NPath, strlen(NPath) + strlen(slesh) + 1, slesh);
	strcat_s(NPath, strlen(NPath) + strlen(ch) + 1, ch);
	puts(NPath);
	strcpy_s(ret, MAX_PATH, NPath);
	return ret;
}

int makecpy(const char * ch) {
	char NPath[MAX_PATH];
	printf("%s", getFullPath(ch, NPath));
	//ch = "C:\\Users\\Den\\source\\repos\\ParP\\app\\Debug\\test";
	HANDLE fl = CreateFile(NPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fl == INVALID_HANDLE_VALUE) {
		puts("Error deraing");
		return 1;
	}
	char count[BUFSIZE];
	memset(count, 0, sizeof(char)*BUFSIZE);
	DWORD dwBytesRead = 0;
	DWORD BytesWrittens = 0;
	int dest_sz = strlen(ch) + strlen("_original") + 1;
	char *c;
	c = (char*)malloc(dest_sz);
	memset(c, 0, dest_sz);
	strcpy_s(c, strlen(ch) + 1, ch);
	strcat_s(c, dest_sz, "_original\0");
	HANDLE cpyfl = CreateFile(c, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	puts(c);
	if (cpyfl == INVALID_HANDLE_VALUE)

	{
		free(c);
		puts("Error creating file!");
		return 1;
	}
	do
	{
		if (ReadFile(fl, &count, BUFSIZE, &dwBytesRead, NULL))
		{

			WriteFile(cpyfl, &count, BUFSIZE, &BytesWrittens, 0);
			printf("%s \n", count);
			CloseHandle(cpyfl);
		}
		else
		{
			free(c);			
			puts("Error deraing");
			return (6);
		}

	} while (dwBytesRead == BUFSIZE);

	CloseHandle(fl);
	char ext[MAX_PATH];
	strcpy_s(ext, strlen(NPath) + 1, NPath);
	strcat_s(ext, strlen(ext) + 10, ".txt");
	renameFile(NPath, ext);
	free(c);
	return 0;
}

int renameFile(const char * source, const char *dest) {
	puts(source);
	return MoveFile(source, dest);

}


void runProcess(char *exePath) {

	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	TCHAR EditorName[] = _T("notepad.exe test.txt");
	int status = CreateProcess(0, EditorName, 0, 0, false, 0, 0, 0, &si, &pi);
	if (!status) {
		printf("Error\n");
		return;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	char fl[MAX_PATH];

	WIN32_FIND_DATA findfiledata;
	HANDLE h = FindFirstFile("*.txt", &findfiledata);
	if (h == INVALID_HANDLE_VALUE)
	{
		printf("file not found");
		return;
	}
	char * basestring;
	basestring = (char*)malloc(sizeof(char) * 100);
	strcpy_s(basestring, strlen(exePath) + 1, exePath);
	char args[] = " a test.rar ";
	strcat_s(basestring, strlen(args) + strlen(basestring) + 1, args);
	while (1) {

#ifdef unicode
		WideCharToMultiByte(cp_oemcp, 0, findfiledata.cfilename, -1, fl, sizeof(fl), 0, 0);
#else
		CharToOem(findfiledata.cFileName, fl);
#endif 
		int full_lnth = strlen(fl) + strlen(basestring) + 1;

		strcat_s(basestring, full_lnth, fl);

		status = FindNextFile(h, &findfiledata);
		if (!status)
			break;

	}
	FindClose(h);
	puts(basestring);


	status = CreateProcess(0, basestring, 0, 0, false, 0, 0, 0, &si, &pi); 
	if (!status) {
		printf("Error\n");
		return;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	printf("Press any key…\n");

	return;
}








