// ex.18 display last modification time of a file

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

char* getfname(void);

int main(void)
{
  char current_dir[] = ".";

  // open directory
  DIR* cdPtr = opendir(current_dir);

  struct dirent* dir_entry;
  time_t lasttime;

  char* filename = getfname();

  while ((dir_entry = readdir(cdPtr)) != NULL) {
    if (strcmp(dir_entry->d_name, filename) == 0) {  
      // get meta data from file
      struct stat filestat;
      stat(dir_entry->d_name, &filestat);
      lasttime = filestat.st_atime;
      printf("last time \"%s\" was accessed: %s\n", dir_entry->d_name, ctime(&lasttime));  
    }
  }
  closedir(cdPtr);
  free(filename);
  return 0;
}

char* getfname(void)
{
  char* filename = malloc(64);
  if (filename == NULL) {
    printf("malloc() failed");
    exit(1);
  }

  printf("enter name of file to look up its last time opened: ");
  scanf("%s", filename);
  getchar();

  return filename;
}
