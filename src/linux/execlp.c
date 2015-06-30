#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Running ps with execlp!\n");
    execlp("ps", "ps", "ax", 0);
    printf("Done.\n");
    exit(EXIT_SUCCESS);
}
