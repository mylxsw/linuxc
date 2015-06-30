#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main()
{
    int i;
    time_t the_time;
    time_t start;
    time_t end;

    start = time((time_t*)0);
    for (i = 1; i <= 10; i ++) {
        the_time = time((time_t *)0);
        printf("The time is %ld\n", the_time);
        sleep(2);
    }
    end = time((time_t*)0);
    printf("Time escape: %f\n", difftime(start, end));    

    exit(0);
}
