// ex.3 write multiple lines to a file

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
  char filename[] = "writelines.txt";
  int lines = 0;
  
  // get input
  printf("Enter number of lines to be written: ");
  scanf("%d", &lines);
  printf("\n");
  
  // open file & check for errors
  int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
  if (fd == -1) {
    printf("open() failed on \"%s\"\n", filename);
    exit(1);
  }
  printf("\"%s\" successfully opened.\n", filename);

  char line2write[] = "test line ";
  int line_len = strlen("test line ");
  char newline = '\n';

  // write to file
  for (int i=1; i <= lines; i++) {
    int i_len = (int) log10(i) + 2; // chars needed to allocate + '\n'
    char* i_strPtr = malloc(i_len*sizeof(char));
    sprintf(i_strPtr, "%d", i); // store i as a string
    strcat(i_strPtr, &newline);

    char* line2writePtr = malloc((line_len + i_len)*sizeof(char));
    strcpy(line2writePtr, line2write); // copy text to string
    strcat(line2writePtr, i_strPtr); // append line number to string
    
    int written = write(fd, line2writePtr, line_len + i_len);
    if (written == -1) {
      printf("write() failed on \"%s\"\n", filename);
      exit(1);
    }
    printf("line %d written\n", i);

    free(i_strPtr);
    free(line2writePtr);
  }

  close(fd);
  return 0;
}
