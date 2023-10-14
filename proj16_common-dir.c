// ex.16 get common directory

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char* paths[3] = {
    "/home/me/user/temp/a",
    "/home/me/user/temp/b",
    "/home/me/user/temp/c/d"
  };
  char* marker[3] = { NULL, NULL, NULL };
  char commonpath[1024] = "/";
  int first = 1;

  for (;;) {
    int i = 0;
    char* tempdirPtr = strtok_r((first ? paths[i] : NULL), "/", &marker[i]); 
    for (i=1; i<3; i++) {
      char* tempdirPtr2 = strtok_r((first ? paths[i] : NULL), "/", &marker[i]);
      if (strcmp(tempdirPtr, tempdirPtr2) != 0) {
        printf("common tree is: \"%s\"\n", commonpath);
        return 0;
      }
      strcat(commonpath, "/");
      strcat(commonpath, tempdirPtr);
    }
    first = 0;
  }
  return 0;
}
