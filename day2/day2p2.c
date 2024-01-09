#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// take each game input and count each color from each round. compare this number with 
//               12 red cubes, 13 green cubes, and 14 blue cubes
// sum the game numbers of the games in which the number of each is less than the given constraint


//example input

// Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
// Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
// Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
// Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
// Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

#define MAX_LINES 100
#define MAX_LEN 500

struct fileContents {
    int len;
    char** contents;
};

typedef struct fileContents Struct;

// function declarations
struct fileContents readFile(char* filename);
int getRoundScore(char* game);
int getGameScore(char* game_str);




int main() {
    // read file line by line into a string array
    struct fileContents contents = readFile("day2input.txt");
    int game_acc = 0;
    for (int i = 0; i < 100; i++ ) {
        // printf("current line : %s\n", contents.contents[i]);
        game_acc+= getGameScore(contents.contents[i]);
        printf("game %d, score %d\n", i+1, game_acc);
        // printf("modified %s", contents.contents[i]);
    }
    // parse the values
    // compare
    // if happy, add to accumulator
    // else continue

    printf("final score %i\n", game_acc);
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
    return contents;
}

int getGameScore(char* game_str) {
    int red = 12;
    int green = 13;
    int blue = 14;
    char* saveptr1; // need this for strtok_r
    char* current_word = strtok_r(game_str, " ", &saveptr1);

    char ** split_game = malloc(100 * sizeof(char*));
    // create memory for inner
    for (int i = 0; i < 100; i++) {
        split_game[i] = malloc(100 * sizeof(char));
    }

    int current_idx = 0;

    while (current_word != NULL) {
        split_game[current_idx] = current_word;
        current_word = strtok_r(NULL, " :,", &saveptr1); // modifies in place, including outside this function
        current_idx++;
    }

    int game_number = atoi(split_game[1]);
    int length = current_idx;

    current_idx = 2;
    while(current_idx < length) {
        // printf("here %s\n", split_game[current_idx+ 1] );
        if (strstr(split_game[current_idx+ 1],"red") != NULL) {
            red -= atoi(split_game[current_idx]);
        } else if (strstr(split_game[current_idx+ 1],"green") != NULL) {
            green -= atoi(split_game[current_idx]);
        } else if (strstr(split_game[current_idx+ 1],"blue") != NULL) {
            blue -= atoi(split_game[current_idx]);
        }
        // if end of round is reached
        if (strchr(split_game[current_idx+ 1], ';') != NULL) {
            if (red < 0 || green < 0 || blue < 0) {
                return 0;
            } else {
                red = 12;
                green = 13;
                blue = 14;
            }
        }
        current_idx+=2;
    }
    free(split_game);
    if (red < 0 || green < 0 || blue < 0) {
        return 0;
    }
    return game_number;
}
// int getRoundScore(char* game) {
//     // read until number, save it
//     // check next word
//     // 
//     //
//     return 0;
// }
