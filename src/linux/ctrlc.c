#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ouch(int sig)
{
    printf("OUCH! - I got signal %d\n", sig);
    signal(SIGINT, SIG_DFL);
}

int main()
{
    signal(SIGINT, ouch);
    while (1) {
        printf("Hello, world!\n");
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}
