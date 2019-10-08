#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>


//Declare a list of all vowels
const char* all_vowels = "aeiouAEIOU";


int is_vowel(char inp_char){

  int vowel_status = 0;
  int j=0;
  for(j=0;all_vowels[j] != '\0';j++){
    if (all_vowels[j] == inp_char){
      vowel_status = 1;
      break;
    }
  }
  return vowel_status;
}

char *disemvowel(char *str) {
  if(str==0x0){
   str = "";
  }
  char *disemvoweled_string;
  int i;
  int vowel_count = 0;
  int str_length = strlen(str);
    //in this loop, get a count of consonants
  for(i=0; str[i] != '\0';i++){
    if (is_vowel(str[i]) == 1){
      vowel_count++;
    }
  }

  //declare a newstring of consonant count +1 size
  int pos_in_disemvoweled=0;

  disemvoweled_string = (char*) calloc(str_length - vowel_count+1, sizeof(char));

  for(i=0; str[i] != '\0';i++){
    if (is_vowel(str[i]) == 0){
      disemvoweled_string[pos_in_disemvoweled]=str[i];
      pos_in_disemvoweled++;
    }
  }

  return (char*) disemvoweled_string;
}

int main(int argc, char *argv[]) {
  if(argc >= 2) {
    freopen(argv[1], "r", stdin);
    if(!stdin) {
      exit(EXIT_FAILURE);
    }
  }
  else if (argc == 3) {
    printf("Output to:");
    freopen(argv[2], "w", stdout);
  }

  char* str;
  int notDone = 1;
  char* buffer = calloc(1000, sizeof(char));
  int str_length = 0;
  while(notDone) {
     str = disemvowel(fgets(buffer,1000,stdin));
     str_length = strlen(str);
     fwrite((void*)str, sizeof(char), str_length, stdout);
     fflush(stdout);
     if(feof(stdin)) {
       notDone = 0;
     }
     if(ferror(stdin)){
     	notDone = 0;
     }
     free(input);
     free(str);
   }
  

  fclose(stdout);
  fclose(stdin);
}
