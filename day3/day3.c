#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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



int main() {
    struct fileContents contents = readFile("shortinput.txt"); 
    // loop through the matrix
	// upon reaching a number, determine how many digits
	// look to it left (unless [x][0])
	// look to its right (inless [x][len-1]
	// look below in [x-1][y-1,y,y+1 (based on length of number in digits)]
	// 		unless x=length-1
	// look above
    
	char ** input_arr = contents.contents;
	int y_len = contents.len;

	for (int i = 0; i < y_len; i++) {
		printf("%s", input_arr[i]);

		int x_len = sizeof(input_arr[i]) / sizeof(char);
		// keep track of beginning and end index for each number	
		int num_b_idx = 0;
		int num_e_idx = 0;
		bool prev_was_num = false;
		
		for (int y = 0; y < x_len; y++) {
			char current_char = input_arr[i][y];
			
		    if (isdigit(current_char)) {
				if (prev_was_num) {
					num_e_idx = y;
				} else {
					num_b_idx = y;
					prev_was_num = true;
				}
			} else {
				prev_was_num = false;
				// check adjacent
				// if i = 0 dont look above
				// if num_b_idx = 0 dont look left
				// if num_e_idx = x_len dont look right
				// if i = y_len dont look left
			}
		}
	}
	printf("\n");
    return 0;
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
