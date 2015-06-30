#include <stdio.h>
#include <unistd.h>


int main(void)
{
  if (chdir("/tmp") < 0) {
    perror("chdir failed");
    return 2;
  }

  printf("chdir to /tmp succeeded\n");
  return 0;
}
