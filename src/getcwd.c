#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  char *ptr;
  size_t size = 100;

  if (chdir("/tmp") < 0) {
    fputs("chdir failed", stderr);
    exit(2);
  }

  ptr = malloc(size);
  if (getcwd(ptr, size) == NULL) {
    fputs("getcwd failed", stderr);
    exit(2);
  }

  printf("cwd = %s\n", ptr);
  free(ptr);

  return 0;
}
