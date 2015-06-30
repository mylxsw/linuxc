#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

#define HOSTNAME_LEN 255

void printHostInfo();

int main() 
{
    char hostname[HOSTNAME_LEN];
    if (gethostname(hostname, HOSTNAME_LEN - 1) != 0) {
        perror("hostname");
    } 

    printf("The hostname is %s\n", hostname);

    printHostInfo();

    exit(0);
}


void printHostInfo()
{

    struct utsname utsname;
    if (uname(&utsname)) {
        perror("uname");
    }

    printf("The system is %s, nodename is %s, release is %s, version is %s, machine is %s\n", 
            utsname.sysname, 
            utsname.nodename, 
            utsname.release, 
            utsname.version, 
            utsname.machine);


}
