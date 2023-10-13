// ex.1 create file & store data in it

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
  // read in name of file to be created               
  char filename[100];
  printf("Enter name of file to write into: ");          
  scanf("%s", filename);
  getchar();
  printf("\n");
  // printf("name of file to be created: \"%s\"\n", filename);
  
  // read in contents to be persisted
  // alternative way: scanf("%[^\n]s", buffer_out); / getchar();
  char buffer_out[256];
  printf("Enter content to be persisted: \n");
  if (fgets(buffer_out, 256, stdin) == NULL) {
      printf("fgets() failed");
      exit(1);
    }
  
  /*
  // check input string
  for (int i=0; i <= strlen(buffer_out); i++)
    printf(" %d ", buffer_out[i]);
  printf("\n");
  */
  // replace newline character
  buffer_out[strlen(buffer_out)-1] = '\0';
  /*
  for (int i=0; i <= strlen(buffer_out); i++)
    printf(" %d ", buffer_out[i]);
  printf("\n");
  
  printf("content entered for writing: %s\n", buffer_out);
  */
  // create file
  int file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
  if (file_descriptor == -1) {
    printf("open() failed on \"%s\"\n", filename);
    exit(1);
  }
  printf("file \"%s\" successfully created and/or open for writing\n", filename); 
  
  // write to file
  int writtenBytes = write(file_descriptor, buffer_out, strlen(buffer_out));
  if (writtenBytes == -1) {
    printf("write() failed on \"%s\"\n", filename);
    exit(1);
  }
  printf("content successfully written to \"%s\"!\n", filename); 
  
  close(file_descriptor);
  return 0;
}
