#include <stdio.h>

int main()
{
    char cmd[100];

    fgets(cmd, 100, stdin);
    system(cmd);
    
    return 0;
}
