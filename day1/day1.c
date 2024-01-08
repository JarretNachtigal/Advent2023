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
    const int len = strlen(str); // length of the input string
    int first; // index of first number
    int last;   // index of last number
    int current = 0; // current iterator
    const char* numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    // find first numeric digit
    while(!isdigit(str[current]) && current <= len -1) {
        current++;
        printf("%d", current);
    }
    first = str[current];

    // check for first number as string
    // if the number is not the first character
    if (current != 0) {
        // substring beginning to number index
        char substr[current+1];
        strncpy(substr, str, current);
        substr[current] = '\0'; // must add null terminator
        printf("substring = %s %ld\n", substr, strlen(substr));

        // check substr for 'one', 'two'...
        for (int i = 0; i < 9; i++){
            // index of first letter of found substring
            char* strptr = &str[i];
            int indexofnum = strptr - strstr(str, substr); // pointer math 1 2 3...
            char* strstrresult = strstr(str, substr); // 
            printf("index mid eval %d\n", indexofnum);
            printf("index mid eval %s\n", strstrresult);

            // save string for passing into strtonum
            // char strtonuminputstr[] = {};

            // if string exists and is before any other
            if (indexofnum <= current) {
                current = indexofnum;
                printf("current index = %d\n", current);
                // set first
                first = strtonum(strstrresult);
                printf("after strtonum %d\n", first);
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