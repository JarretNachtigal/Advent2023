// work left to right with a substring
// four9one
// f
// fo
// fou
// four
// four9

// check for string with strstr()
// null termintor manually
//      might be worth copying (make sure that original string is unaffected)


// walk right to left, make sure to get order right
// e
// ne
// one
// 9one

// check for string with strstr()
// null termintor manually
//      might be worth copying (make sure that original string is unaffected)#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// https://adventofcode.com/2023/day/1

#define MAX_LINES 1000
#define MAX_LEN 100

struct fileContents {
    int len;
    char** contents;
};

typedef struct fileContents Struct;

struct fileContents readFile(char* filename);
int sumCalibrations(int len, char** fileContents);
int getValueFromString(char* str);
int strtonum(char* str);

int main() {
    struct fileContents filecontents = readFile("subset.txt");

}


// depends on MAX_LINES and MAX_LEN macros
struct fileContents readFile(char* filename) {
    // create memory for outer
    char ** fileContents = malloc(MAX_LINES * sizeof(char*));
    // create memory for inner
    for (int i = 0; i < MAX_LINES; i++) {
        fileContents[i] = malloc(MAX_LEN * sizeof(char));
    }

    FILE* fptr = fopen(filename, "r");

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
    // return in a struct
    struct fileContents contents;
    contents.contents = fileContents;
    contents.len = line;

    return contents;
}


int strtonum(char* str) {
    printf("inside strtonum %s\n", str);
    if (strcmp(str, "one") == 0) {
        return 1;
    }
    else if (strcmp(str, "two") == 0) {
        return 2;
    }
    else if (strcmp(str, "three") == 0) {
        return 3;
    }
    else if (strcmp(str, "four") == 0) {
        return 4;
    }
    else if (strcmp(str, "five") == 0) {
        return 5;
    }
    else if (strcmp(str, "six") == 0) {
        return 6;
    }
    else if (strcmp(str, "seven") == 0) {
        return 7;
    }
    else if (strcmp(str, "eight") == 0) {
        return 8;
    }
    else {
        return 9;
    }
}