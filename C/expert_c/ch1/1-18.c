#include <stdio.h>

void func(int* a) {
    int b = 9;
    *a = 5;
    a = &b
;}

int main(int argc, char** argv) {
    int x = 3;
    int* xPtr = &x;
    printf("after call: %d\n", x);
    printf("address of x: %d\n", xPtr);
    func(xPtr);
    printf("after call: %d\n", x);
    printf("address of x: %d\n", xPtr);
    return 0;
}