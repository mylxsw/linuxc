#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int val;
  if (argc != 2) {
    fputs("usage: a.out <descriptor#>\n", stderr); 
    exit(1);
  }

  if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
    printf("fcntl error for fd %d", atoi(argv[1]));
    exit(1);
  }

  switch(val & O_ACCMODE) {
  case O_RDONLY:
    printf("read only");
    break;
  case O_WRONLY:
    printf("write only");
    break;
  case O_RDWR:
    printf("read write");
    break;
  default:
    fputs("unknown access mode", stderr);
    exit(1);
  }

  if (val & O_APPEND) {
    printf(", append");
  }

  if (val & O_NONBLOCK) {
    printf(", noblocking");
  }

  if (val & O_SYNC) {
    printf(", synchronmous writes");
  }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
  if (val & O_FSYNC) {
    printf(", synchronmous writes");
  }
#endif

  putchar('\n');

  return 0;


}
