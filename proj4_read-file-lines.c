// ex.4 read file & store lines in array

#include <stdio.h>
#include <string.h>

int main(void)
{
  char filename[64];
  printf("Enter file to read from: ");
  scanf("%63s", filename);
  getchar();
  printf("\n");

  printf("filename \"%s\" is of length %d\n", filename, (int) strlen(filename));

  //  FILE* fd;

  return 0;
}
