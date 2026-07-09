#include <stdio.h>

typedef unsigned long ulong;

ulong power(int base, int exponent) {
    if(exponent == 1)
        return base;
    else if(base == 0)
        return 1;
    
    if(exponent % 2 == 0) {
        ulong newBase = power(base, exponent / 2);
        return newBase * newBase;
    }
    else {
        ulong  newBase = power(base, (exponent - 1) / 2);
        return (newBase * newBase) * base;
    }
}

int main(void) {
    int base = 2;
    int exponent = 30;
    printf("%d^%d = %lu\n", base, exponent, power(base, exponent));
    return 0;
}