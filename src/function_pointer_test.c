#include <stdio.h>

void sayHello();

void sayHello() {
    printf("hello world\n");
}

int main() {
    void (*sayHelloPtr)() = sayHello;
    sayHello();

    (*sayHelloPtr)();
}
