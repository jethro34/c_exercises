// ex.2 read from existing file

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  // read name of file
  char filename[100];
  printf("Enter name of file to be read: ");
  scanf("%s", filename);
  getchar();
  printf("\n");

  printf("File to be read: \"%s\"\n", filename);

  int fd = open(filename, O_RDONLY, 0400);
  if (fd == -1) {
    printf("open() failed on \"%s\"\n", filename);
    exit(1);
  }
  printf("%s successfully opened\n", filename);

  // allocate buffer to read contents in
  char* readBuffer = malloc(256 * sizeof(char));
  // read & store number of characters read
  int bytes_read = read(fd, readBuffer, 256);
  if (bytes_read == -1) {
    printf("read() failed.");
    exit(1);
  }
  printf("read() successful\n");
  
  // print out contents
  printf("Contents read from \"%s\": \n", filename);
  printf("%s\n", readBuffer);

  close(fd);
  return 0;
}
