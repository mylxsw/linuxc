#include <stdio.h>
#include <sys/stst.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
  return 0;
}


#define FTW_F     1
#define FTW_D     2
#define FTW_DNR   3
#define FTW_NS    4

static char *fullpath;
static size_t pathlen;

static int myftw(char *pathname, MyFunc *func)
{
  fullpath = path_alloc(&pathlen);

  if (pathlen <= strlen(pathname)) {
    pathlen = strlen(pathname) * 2;
    if ((fullpath = realloc(fullpath, pathlen) == NULL) {
      fputs("realloc failed!", stderr);
      exit(2);
    }
  }

  strcpy(fullpath, pathname);
  return dopath(func);
}


static int dopath(MyFunc* func)
{
  struct stat    statbuf;
  struct dirent  *dirp;
  DIR            *dp;
  int            ret, n;

  if (lstat(fullpath, &statbuf) < 0) {
    return func(fullpath, &statbuf, FTW_NS);
  }

  if (S_ISDIR(statbuf.st_mode) == 0) {
    return func(fullpath, &statbuf, FTW_F);
  }

  if ((ret = func(fullpath, &statbuf, FTW_D)) != 0) {
    return ret;
  }

  n = strlen(fullpath);
  if (n + 
}


char *path_alloc(size_t *sizep)
{
  char *ptr;
  size_t size = 1024;

  if((ptr = malloc(size)) == NULL) {
    perror("malloc error for pathname");
    exit(2);
  }

  if (sizep != NULL) {
    *sizep = size;
  }

  return ptr;
}
