
#include <unistd.h>

int main()
{
    for (; ;) {
        for (int i = 0; i < 9600000; i ++)
            ;
        sleep(10);
    }

    return 0;
}
