#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 1024

//Declare a list of all vowels
const char* all_vowels = "aeiouAEIOU";


bool is_vowel(char inp_char) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
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


int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
	int consonant_count = 0;
	for (int i = 0; i < num_chars; i++){
		if (!is_vowel(in_buf[i])){
			out_buf[consonant_count] = in_buf[i];
			consonant_count++;
		}
	}
	return consonant_count;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
	//New buffers
 	char* in_buffer = calloc(BUF_SIZE,sizeof(char));
	char* out_buffer = calloc(BUF_SIZE,sizeof(char));
	//Boolean for our loop to exit
	bool cont = true;
	while(cont){
		// an int to count in how many items we read in
		int read_count = 0;
		// do the actual reading now
		read_count=fread(in_buffer,sizeof(char),BUF_SIZE, inputFile);
		int consonant_count = 0;
		consonant_count=copy_non_vowels(read_count,in_buffer,out_buffer);
		//we now have the disemvoweled string in out_buffer
		fwrite(out_buffer,sizeof(char),consonant_count,outputFile);
		//We have no more things to do with the buffers, so free their contents
		free(in_buffer);
		free(out_buffer);
		//Exit the loop if we reahc the end of the input. (or encounter an error)
		if(read_count != BUF_SIZE){
			cont=false;
		}
	}

}

int main(int argc, char *argv[]) {
    	// You should set these to `stdin` and `stdout` by default
    	// and then set them to user specified files when the user
    	// provides files names as command line arguments.
    	FILE *inputFile = stdin;
    	FILE *outputFile = stdout;
	//if we have more than two args, then we at least have input file
	if(argc >= 2){
		inputFile = fopen(argv[1], "r");
	}
	//if we have three args, then we have output file
	if (argc ==3){
		outputFile = fopen(argv[2],"w");
	}
    	// Code that processes the command line arguments
    	// and sets up inputFile and outputFile.

    	disemvowel(inputFile, outputFile);
	fclose(outputFile);
	fclose(inputFile);
    	return 0;
}
