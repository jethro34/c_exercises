// ex.16 get common directory

#include <stdio.h>
#include <string.h>

int main(void)
{
  char* paths[3] = {
    "/home/me/user/temp/a",
    "/home/me/user/temp/b",
    "/home/me/user/temp/c/d"
  };
  char* marker[3] = { 0 };
  char* tempdirPtr = "";
  char* tempdirPtr2 = "";
  char* commonpathPtr = "/";

  for (;;) {
    int i = 0;
    tempdirPtr = strtok_r(paths[i], "/", &marker[i]); 
    for (i=1; i<3; i++) {
      tempdirPtr2 = strtok_r(paths[i], "/", &marker[i]);
      if (strcmp(tempdirPtr, tempdirPtr2) != 0) {
        printf("common tree is: \"%s\"\n", commonpathPtr);
        return 0;
      }
      strcat(commonpathPtr, "/");
      strcat(commonpathPtr, tempdirPtr);
    }
  }
  return 0;
}
