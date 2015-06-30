#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diediedie(int sig)
{
  puts("Goodbye cruel world ...\n");
  exit(1);
}

void echoHello(int sig)
{
  puts("Hello, 接收到一个信号!\n");
}

int catch_signal(int sig, void (*handler)(int))
{
 struct sigaction action;
 action.sa_handler = handler;
 sigemptyset(&action.sa_mask);
 action.sa_flags = 0;
 return sigaction(sig, &action, NULL);
}

int main()
{
  if (catch_signal(SIGINT, diediedie) == -1) {
    fprintf(stderr, "Can not map the handler");
    exit(2);
  }

  if (catch_signal(SIGALRM, echoHello) == -1) {
    fprintf(stderr, "Can not map the handler");
    exit(2);
  }

  alarm(10);

  char name[30];
  printf("Enter your name:");
  fgets(name, 30, stdin);

  printf("Hello, %s\n", name);
  return 0;
}
