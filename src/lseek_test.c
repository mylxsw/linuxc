#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
    puts("Can not seek!");
  } else {
    puts("Seek ok!");
  }

  exit(0);
}
