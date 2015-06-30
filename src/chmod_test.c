#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  struct stat statbuf;

  if (stat("foo", &statbuf) < 0) {
    fputs("stat error for foo", stderr);
    return 2;
  }

  if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
    fputs("chmod error for foo", stderr);
    return 2;
  }

  if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
    fputs("chmod error for bar", stderr);
    return 2;
  }

  return 0;
}
