#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>


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

int main(int argc, char *argv[]) {
  if(argc >= 2) {
    freopen(argv[1], "r", stdin);
    if(!stdin) {
      exit(EXIT_FAILURE);
    }
  }
  else if (argc == 3) {
    freopen(argv[2], "w", stdout);
  }
  char* str;
  int notDone = 1;
  char* buffer = calloc(1000, sizeof(char));
  int str_length = 0;
  while(notDone) {
     str = disemvowel(fgets(buffer, 1000, stdin));
     str_length = strlen(str);
     fwrite((void*)str, sizeof(char), str_length, stdout);
     fflush(stdout);
     if(feof(stdin)) {
       notDone = 0;
     }
     free(str);
   }

  fclose(stdout);
  fclose(stdin);
}
