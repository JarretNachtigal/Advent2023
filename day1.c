#include <stdio.h>
#include <stdlib.h>

// https://adventofcode.com/2023/day/1

#define MAX_LINES 1000
#define MAX_LEN 100

// char** readfile(char* filename);

int main(){
    char filecontents[MAX_LINES][MAX_LEN];

    FILE *fptr = fopen("day1.txt", "r");

    if (fptr == NULL) {
        printf("file machine broke");
        return 1;
    }

    int line = 0;

    while(!feof(fptr) && !ferror(fptr)) {
        if (fgets(filecontents[line], MAX_LEN, fptr) != NULL) {
            line++;
        }
    }

    fclose(fptr);
    return 0;
}