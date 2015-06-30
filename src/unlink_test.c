#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (open("tempfile", O_RDWR) < 0) {
    perror("open error");
    return 2;
  }

  //if (unlink("tempfile") < 0) {
  if (remove("tempfile") < 0) {
    perror("unlink error");
    return 2;
  }

  printf("file unlinked\n");
  sleep(15);
  printf("done \n");

  return 0;
}
