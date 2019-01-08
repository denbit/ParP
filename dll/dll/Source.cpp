#include <stdio.h>
#include<string.h>
#include<ctype.h>


__declspec(dllexport) int   calculateFromDLL(char *string) {
		
		//memset(strr, 0, sizeof(char) * COUNT);
		
		int amount = 0;
		for (unsigned len = 0; len < strlen(string); len++) {
			
			if (isalpha(string[len])) {
				if (isspace(string[len + 1]) || string[len + 1] == '\0') {
					amount++;
				}
			}
		}
		return amount;

	}
	
	
