// ex.4 read file & store lines in array

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // get file name
  char filename[64];
  printf("Enter file to read from: ");
  scanf("%63s", filename);
  getchar();
  printf("\n");

  // printf("filename \"%s\" is of length %d\n", filename, (int) strlen(filename));

  // open file for reading
  FILE* fd = fopen(filename, "r");
  if (fd == NULL) {
    printf("open() failed on \"%s\"\n", filename);
    exit(1);
  }
  printf("\"%s\" opened successfully\n", filename);

  // figure out number of lines
  int newlines = 0;
  char ch;
  while ((ch = fgetc(fd)) != EOF) {
    if (ch == '\n')
      newlines++;
  }
  // printf("there are %d lines in \"%s\"\n", newlines, filename);
  
  // dynamically allocate memory for pointer of pointers to strings
  char** lines = malloc(newlines * sizeof(char*));
  if (lines == NULL) {
    printf("malloc() failed\n");
    exit(1);
  }  

  // allocate memory for each pointer to string in array
  for (int i=0; i < newlines; i++) {
    lines[i] = malloc(1024*sizeof(char));
    // check for allocation errors
    if (lines[i] == NULL) {
      printf("malloc() failed allocating memory for lines[%d]\n", i);
      // free previously allocated memory before aborting
      for (int j=0; j<i; j++)
        free(lines[j]);
      free(lines);
      exit(1);
    }
  }

  // rewind file pointer back to beginning
  fseek(fd, 0, SEEK_SET); // rewind(fd); is also possible
  
  // read lines from file & store in lines
  for (int i=0; i < newlines; i++) {
    if (fgets(lines[i], 1024, fd) != NULL) {
      printf("line %d successfully read\n", i+1);
      // substitute newline with null-terminator
      lines[i][strlen(lines[i])-1] = '\0';
    } else
      printf("fgets() failed to read from line %d", i+1);
  }
  
  // print out from array
  for (int i=0; i<newlines; i++) {
    printf("line %d's content: \"%s\"\n", i+1, lines[i]);
  }
  // free allocated memory
  for (int i=0; i<newlines; i++)
    free(lines[i]);
  free(lines);

  fclose(fd);
  return 0;
}
