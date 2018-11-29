#include"C:\Users\Den\source\repos\ParP\app\ParP\lab1.h"

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int calculate() {
	char  strr[COUNT];
	get_string(strr);
	int amount=0;
	for (unsigned len = 0; len < strlen(strr); len++) {
		printf("%d\n", strlen(strr));
		printf("%c %d\n", strr[len], strr[len]);
		/*if (isalpha(strr[len])) {
			if (isspace(strr[len + 1])) {
				amount++;
			}

		}*/
	}
	return amount;

}

void get_string(char * str)
{
	char strs[COUNT];
	puts("You have entered: ");
	puts(gets_s(strs, COUNT));
	str = strs;
}

