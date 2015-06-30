#include <stdio.h>

int main() 
{

    int myarray[4] = {1, 2, 3, 0};
    int *p = myarray;
    int out = 0;
    
    while(out = *p++) {
        printf("%d ", out);
    }
    printf("\n");

    int x = 0;
    int y = x ++;
    printf("x = %d, y = %d\n", x, y);

    
    int *p2 = myarray;
    int *x2 = p2;
    p2 = p2 + 1;
    printf("*p2 = %d, *x2 = %d\n", *p2, *x2);



    char charvar = '\0';
    printf("address of charvar = %p\n", (void*)(&charvar));
    printf("address of charvar - 1 = %p\n", (void*)(&charvar - 1));
    printf("address of charvar + 1 = %p\n", (void*)(&charvar + 1));
   

    int intvar = 1;
    printf("address of intvar = %p\n", (void*)(&intvar));
    printf("address of intvar - 1 = %p\n", (void*)(&intvar - 1));
    printf("address of intvar + 1 = %p\n", (void*)(&intvar + 1));


    int numbers[5] = {1, 2, 3, 5, 6};
    int i = 0;

    printf("numbers = %p\n", numbers);

    do {
        printf("number[%u] = %p\n", i, (void*)(&numbers[i]));
        i ++;
    } while(i < 5);

    printf("sizeof(numbers) = %lu\n", sizeof(numbers));
    

    struct measure {
        char category;
        int width;
        int height;
    };

    struct measure ball;
    ball.category = 'C';
    ball.width = 5;
    ball.height = 3;


    printf("address of ball = %p\n", (void*)(&ball));
    printf("address of ball.category = %p\n", (void *)(&ball.category));
    printf("address of ball.width = %p\n", (void *)(&ball.width));
    printf("address of ball.height = %p\n", (void *)(&ball.height));

    printf("sizeof(ball) = %lu\n", sizeof(ball));

    return 0;
}
