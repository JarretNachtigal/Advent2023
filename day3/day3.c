#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// for file reading
#define MAX_LINES 140
#define MAX_LEN 100

struct fileContents {
    int len;
    char** contents;
};

typedef struct fileContents Struct;

//function definitions
struct fileContents readFile(char* filename);
int getPartValues (char* above_arr, char* below_arr, char* current_arr);


int main() {
    struct fileContents contents = readFile("shortinput.txt"); 

	int acc = 0;
	for (int i = 0; i <= contents.len; i++){
		char* above_arr;
		char* below_arr;
		char* current_arr = contents.contents[i];
		// TODO init arrays

		acc = getPartValues(above_arr, below_arr, current_arr);
		
	}
}


int getPartValues (char* above_arr, char* below_arr, char* current_arr) {
	// get current_arr len
	// loop through current_arr
	int len = sizeof(current_arr) / size_of(char);
}








struct fileContents readFile(char* filename) {
    // create memory for outer
    char ** fileContents = malloc(MAX_LINES * sizeof(char*));
    // create memory for inner
    for (int i = 0; i < MAX_LINES; i++) {
        fileContents[i] = malloc(MAX_LEN * sizeof(char));
    }

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("file machine broke");
        // return 1;
    }

    int line = 0;

    while(!feof(fptr) && !ferror(fptr)) {
        if (fgets(fileContents[line], MAX_LEN, fptr) != NULL) {
            line++;
        }
    }

    fclose(fptr);
    // return 
    struct fileContents contents;
    contents.contents = fileContents;
    contents.len = line;
    printf("lines number = %d\n",  line);
    return contents;
}
