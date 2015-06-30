#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char *my_env[] = {"FOOD=coffee", NULL};
  if (execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1) {
    fprintf(stderr, "Can not run process 0: %s\n", strerror(errno));
    return 1;
  }

  fprintf(stderr, "Can not create order: %s\n", strerror(errno));
  return 1;
}
