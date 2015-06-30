#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

char* get_file_type(const struct stat *filestat);

int main(int argc, char *argv[])
{
  struct stat filestat;
  char *result;
  
  if (lstat(argv[1], &filestat) < 0) {
    perror("get fileinfo error");
    return -1;
  }

  result = get_file_type(&filestat);

  printf("%s\n", result);
  return 0;
}

/**
 * 从文件stat中获取文件类型的字符串表示
 */
char* get_file_type(const struct stat *filestat)
{
  char *result;
  if (S_ISREG(filestat->st_mode)) {
    result = "regular";
  } else if (S_ISDIR(filestat->st_mode)) {
    result = "directory";
  } else if (S_ISCHR(filestat->st_mode)) {
    result = "character special";
  } else if (S_ISBLK(filestat->st_mode)) {
    result = "block special";
  } else if (S_ISFIFO(filestat->st_mode)) {
    result = "fifo";
  } else if (S_ISLNK(filestat->st_mode)) {
    result = "symbolic link";
  } else if (S_ISSOCK(filestat->st_mode)) {
    result = "socket";
  } else {
    result = "** unknown mode **";
  }

  return result;
}
