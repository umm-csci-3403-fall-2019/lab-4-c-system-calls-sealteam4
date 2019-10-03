#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
    int i;
    int numVowel = 0;
    for (i=0; i<strlen(str); i++){
        switch(tolower(str[i])){
	    case 'a':
            case 'e':
            case 'i':
	    case 'o':
            case 'u':
                numVowel = numVowel + 1;
		break;
	}
    }
    char *newstr = (char*) calloc(strlen(str) - numVowel + 1, sizeof(char));
    int j=0;
    for (i=0; i<strlen(str); i++){
        switch(tolower(str[i])){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
		newstr[j] = str[i];
		j = j + 1;
		break;
	}
    }
  return newstr;
}
