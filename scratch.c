#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// conclusion - somewhat wrong behavior when no explicit null terminator in dynamic size array using clang
// strlen implementation or dynamic array implemention

int main() {

  // printf("%s\n",strstr("big string", "string"));
  char bigstr[] = "big string";
  int len = strlen(bigstr);
  char smallstr[len];

  strncpy(smallstr, bigstr+0, 5);
  printf("%s\n", smallstr);

  // char arr[] = {'A', '\0'}; // 6 - consistent-ish
  // char arr_four[] = {'5','x','k','q','k','j','f','j','g','k','s','f','l','f','c','q','r','g','r','h','m','f','x','f','l','s','c','s','x','s','r','d','h','x','g','p','f','i','v','e','t','x','g','p','z','z','l','f','z','j','1', '\0'};
  // char arr_two[] = {'A', '\0'}; // 1
  // char arr_five[] = {'1','2'};
  // char arr_three[] = {'5','x','k','q','k','j','f','j','g','k','s','f','l','f','c','q','r','g','r','h','m','f','x','f','l','s','c','s','x','s','r','d','h','x','g','p','f','i','v','e','t','x','g','p','z','z','l','f','z','j','1'};



  // for (int i  = 0; i <= strlen(arr); i++ ) {
  //   // printf("%c", arr[i]);
  // }

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

  // printf("%lu\n", strlen(arr));
  // printf("%lu\n", strlen(arr_four));
  // printf("%lu\n", strlen(arr_two));
  // printf("%lu\n", strlen(arr_five));
  // printf("%lu\n", strlen(arr_three));
  // printf("%lu\n", strlen(arr_term));
}
