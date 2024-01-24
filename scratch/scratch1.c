#include <stdio.h>

int main() {
    // variables
    int a = 1;
    char b = 'b'; // must be ' not ""

    // arrays
    int intarr[] = {}; // empty
    char chararr[] = "yup"; //string must be " not '
    char chararr2[] = {'y', 'u' , 'j', 'p'}; // these need \0
    char chararr3[] = {'y', 'u' , 'g', 'p'}; // 

    printf("%s\n", chararr);
    printf("%s\n", chararr2);
    printf("%s\n", chararr3);
    // yup
    // yujpyugp
    // yugp
    // this illustrates the need for the null termninator

    char chararr4[] = "yep";
    char chararr5[] = "yeppers";
    printf("%s\n", chararr4);
    printf("%s\n", chararr5);
    // these are printing correctly as they are automatically null terminated
    printf("%ld\n", sizeof(chararr4) / sizeof(char));
    // the size of yup is 4 due to the hidden null terminator

    // the array is basically a pointer and an offset
    printf("%p\n", chararr4);

    // decay?
    char * cptr = chararr4; // point to array
    printf("%ld\n", sizeof(chararr4)); // 4 - correct
    printf("%ld\n", sizeof(cptr));  // 8 - incorrect
    printf("%ld\n", sizeof(cptr) / sizeof(char));  // 8 - incorrect
    printf("%ld\n", sizeof(char));  // 1 - for reference
    // this same thing will happen if an array is passed as a parameter

}