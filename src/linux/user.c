#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>

int main()
{
   
    uid_t uid;
    char *username;
    struct passwd *passwd;

    uid = getuid();
    printf("UID: %d\n", uid);

    username = getlogin();
    printf("Username: %s\n", username);

    passwd = getpwuid(uid);
    printf("The username is %s, uid is %d, gid is %d, home directory is %s, full name is %s, the default shell program is %s\n", passwd->pw_name, passwd->pw_uid, passwd->pw_gid, passwd->pw_dir, passwd->pw_gecos, passwd->pw_shell);

    exit(0);
}
