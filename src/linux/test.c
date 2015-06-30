#include <stdio.h>
#include <stdlib.h>

struct host {
    char *name;
    int port;
};

void gethostname(struct host **);
void gethostname2(struct host *);

int main()
{
    struct host *hostname;
    struct host hostname2;

    gethostname(&hostname);
    printf("hostname: %s, port %d\n", hostname->name, hostname->port); 

    gethostname2(&hostname2);
    printf("hostname: %s, port %d\n", hostname2.name, hostname2.port);

    exit(0);
}

void gethostname(struct host **hostname)
{
    (*hostname) = (struct host *)malloc(sizeof(struct host *));
    (*hostname)->name = "aicode.cc";
    (*hostname)->port = 4455;
}

void gethostname2(struct host *hostname)
{
    hostname->name = "aicode.cc";
    hostname->port = 4444;

}
