// ex.16 get common directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int commonchars(char** str_arr, int arr_len);
char* extractdir(char* str, int maxlen);

int main(void)
{
  char* paths[3] = {
    "/home/me/user/temp/a",
    "/home/me/user/temp/b",
    "/home/me/user/temp/c/d"
  };
  
  char* tree = extractdir(paths[0], commonchars(paths, 3));
  printf("common tree: \"%s\"\n", tree);

  return 0;
}

int commonchars(char** str_arr, int arr_len)
// return number of common characters in a string array
{
  int pos = 0;
  int strlen0 = strlen(str_arr[0]);
  while (pos < strlen0) {
    char ch = str_arr[0][pos];
    for (int i=1; i<arr_len; i++) {
      if ((pos >= strlen(str_arr[i])) || (ch != str_arr[i][pos])) 
        return pos--;
    }
    pos++;
  }
  return 0;
}

char* extractdir(char* str, int strlen)
// shorten a string to a directory
{
  while (str[strlen-1] != '/') {
    strlen--;
  };

  char* tree = malloc(strlen);
  if (tree == NULL) {
    printf("malloc() failed");
    exit(1);
  }

  strncat(tree, str, strlen -1);
  tree[strlen] = '\0';
  
  return tree;
}

