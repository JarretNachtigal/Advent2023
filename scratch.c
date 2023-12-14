#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// conclusion - somewhat undefined behavior when no explicit null terminator in dynamic size array using clang

int main() {

  char arr[] = {'A'}; // 6
  char arr_two[] = {'A', '\0'}; // 1


  // char arr[] = {'A','n'}; // 7
  // char arr[] = {'A','n', 'y'}; // 3
  // char arr[] = {'A','n', 'y', 'a'}; // 9
  // char arr[] = {'A','n', 'y', 'a', 'A'}; // 5
  // char arr_term[] = {'A','n','y','a', '\0'}; // 4

  // for (int i =0; i < 100; i ++) {
  //   char * arr = malloc(3 * sizeof(char)); // 5
  //   arr[0] = 'b';
  //   arr[1] = '\0';
  //   printf("%lu\n", strlen(arr));
  //   free(arr);

  // }

  printf("%lu\n", strlen(arr));
  // printf("%lu\n", strlen(arr_term));
}
