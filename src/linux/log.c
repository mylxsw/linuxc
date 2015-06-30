#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main()
{

    syslog(LOG_ERR|LOG_USER, "oops - Hello, 管宜尧\n");

    exit(0);
}
