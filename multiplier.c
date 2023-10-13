// multiply two input-given numbers

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int result = 1;
  for (int i = 1; i < argc; i++) {
    result *= atoi(argv[i]);
  }
  
  printf("the result is: %d\n", result);
  return 0;
}
