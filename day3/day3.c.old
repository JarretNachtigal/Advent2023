#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
	int acc = 0;
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
					num_e_idx = y;
					prev_was_num = true;
				}
			} else {
				// only look if num was found
				if (prev_was_num) {
					char* puncs = "/-$*=%#+@&";
					prev_was_num = false;
					// check adjacent
					// if i = 0 dont look above
					// if num_b_idx = 0 dont look left
					// if num_e_idx = x_len dont look right
					// if i = y_len dont look left
					
					// look left
					bool found = false;
					if (y < 0) {	
						char left = input_arr[i][num_b_idx-1];
						if (strchr(puncs,left)){
							found = true;
						}
					}
					// look right
					if (y < x_len - 1) {
						char right = input_arr[i][num_e_idx+1];
						if (strchr(puncs, right)){
							found = true;
						}
					}
					// look up
					int left_idx = num_b_idx;
					int right_idx = num_e_idx;
		
					if (i > 0) {
						char* above[num_e_idx+1];

						
						if (y != 0) {
							left_idx--;
						}
						if (y != x_len){
							right_idx++;
						}
						//TODO for loop copy
						int above_len = right_idx - left_idx;
						for (int g = 0; g < above_len; g++) {
							above[g] = &input_arr[i-1][left_idx+i];	
						}
						// strncpy(*above, input_arr[i-1][left_idx], right_idx);

						for (int j = 0; j < above_len; j++) {
							if (strchr(puncs, *above[j])) {
								found = true;
							}
						} 
					}
			

					// look below
                    if (i < y_len) {
                        char* below[num_e_idx+1];

                        if (y != 0) {
                            left_idx--;
                        }
                        if (y != x_len){
                            right_idx++;
                        }
						//TODO for loop copy
						int below_len = right_idx - left_idx;
						for (int g = 0; g < below_len; g++) {
							below[g] = &input_arr[i-1][left_idx+i];	
						}
                        // strncpy(below, input_arr[i+1][left_idx], right_idx);

                        for (int j = 0; j < below_len; j++) {
                            if (strchr(puncs, *below[j])) {
                                found = true;
                            }
                        }
                    }
					if (found) {
						char* num[10];
						// TODO for loop copy
						// need length of string to copy
						int len = num_e_idx - num_b_idx;
						for (int g = 0; g <= len; g++) {
							num[g] = &input_arr[i-1][left_idx+i];	
						}
						// strncpy(num, input_arr[i], num_b_idx, num_e_idx);
						//str to num
						// TODO why this broken?
						acc += atoi(*num);
					}
				}
			}
		}
	}
	printf("%d\n", acc);
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
