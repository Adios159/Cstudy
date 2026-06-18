#include <stdio.h>

int main(int argc, char** argv) {
    int var = 100;
    int* ptr = 0;
    printf("%d\n", ptr);

    ptr = &var;
    printf("%d\n%d\n", &var, ptr);

    *ptr = 200;
    printf("%d\n", var);

    return 0;
}