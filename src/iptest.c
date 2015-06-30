#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    if (execlp("ipconfig", "ipconfig", NULL) == -1) {
        if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1) {
            fprintf(stderr, "Can not run ipconfig: %s", strerror(errno));
            return 1;
        }
    }
    return 0;
}
