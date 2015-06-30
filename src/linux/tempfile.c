#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
/*
    char tmpname[L_tmpnam];
    char *filename;
    FILE *fmpfp;

    filename = tmpnam(tmpname);
    printf("Temporary file name is %s\n", filename);


    tmpfp = tmpfile();
    if (tmpfp) {
        printf("Opened a temporary file OK\n");
    } else {
        perror("tmpfile");
    }

*/
    char *filename;
    int tempfp;

    filename = mktemp("test_XXXXXX.tmp");
    printf("Temporary file name is %s\n", filename);

    tempfp = mkstemp("test_XXXXXX.tmp");
    if (tempfp) {
        printf("Opened a temporary file OK \n");
    } else {
        perror("tempfile");
    }

    close(tempfp);

    exit(0);
}
