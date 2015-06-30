#include <stdio.h>

int main()
{
  FILE *file_handler = fopen("coffee", "r");
  printf("File descriptor: %d\n", fileno(file_handler));
  fclose(file_handler);
}
