#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main()
{

    char buf[100];

    getcwd(buf, 100);
    printf("current dir: %s\n", buf);

   if (mkdir("testdir", 0777)) {
       perror("create failed");
   }

   chdir("testdir");
   getcwd(buf, 100);
   printf("current dir: %s\n", buf);

   DIR *dir;
   dir = opendir(buf);
   struct dirent *dirent = readdir(dir);
   printf("%s\n", dirent->d_name);

   printf("current pos: %d\n", telldir(dir));

   closedir(dir);

    exit(0);
}
