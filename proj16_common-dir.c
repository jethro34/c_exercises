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
  char* tempdirPtr = NULL;
  char* tempdirPtr2 = NULL;
  char commonpath[1024] = "/";
  int first = 1;

  for (;;) {
    tempdirPtr = strtok_r((first ? paths[0] : NULL), "/", &marker[0]); 
    for (int i=1; i<3; i++) {
      tempdirPtr2 = strtok_r((first ? paths[i] : NULL), "/", &marker[i]);
      if (strcmp(tempdirPtr, tempdirPtr2) != 0) {
        printf("common tree is: \"%s\"\n", commonpath);
        return 0;
      }
    }
    strcat(commonpath, "/");
    strcat(commonpath, tempdirPtr);
    first = 0;
  }
  return 0;
}
