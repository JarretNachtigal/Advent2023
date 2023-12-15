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
int getCalibration(char* str);
int strtonum(char* str);


int main() {
    struct fileContents contents = readFile("subset.txt");
    // int ans = sumCalibrations(fileContents);
    int len = contents.len;
    char** filecon = contents.contents;
    // printf("%d\n", len);
    int ans = sumCalibrations(len, filecon);
    printf("answer = %d\n", ans);
    // free(contents);
    // free(ans);
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
    // return in a struct
    struct fileContents contents;
    contents.contents = fileContents;
    contents.len = line;
    printf("lines number = %d\n",  line);
    return contents;
}


int sumCalibrations(int len, char ** fileContents){
    int acc = 0;
    int ans = 0;
    for (int i = 0; i <= len -1; i++) {
        ans = getCalibration(fileContents[i]);
        acc += ans;
        printf("%d\n", acc);
    }
    return acc;
}


int getCalibration(char* str) {
    int len = strlen(str);
    int first;
    int last;
    int current = 0;
    char* numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };


    while(!isdigit(str[current]) && current <= len -1) {
        current++;
    }
    first = str[current];

    // check for first number as string
    if (current != 1) {
        char substr[len];
        strncpy(substr, str, current);
        printf("substring = %s\n", substr);
        // check substr for 'one', 'two'...
        for (int i  = 0; i < 9; i++){
            // index of first letter of found substring
            char* strptr = &str[i];
            int indexofnum = strptr - strstr(str, substr);
            printf("index mid eval %d\n", indexofnum);
            // if string exists and is before any other
            if (indexofnum <= current) {
                current = indexofnum;
                printf("current index = %d\n", current);
                // set first
                first = strtonum(numbers[i]);
            }
        }
    }

    current = len - 1;
        while(!isdigit(str[current]) && current >= 0) {
        current--;
    }
    last = str[current];

    // check for last number as string


    
    char res[] = {first, last};
    printf("str %s first %c, last, %c, res %s\n", str, first, last, res);

    return atoi(res);
}


int strtonum(char* str) {

}