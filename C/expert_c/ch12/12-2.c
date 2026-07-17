#include <stdio.h>
#define abs(x) _Generic((x), int: absi, double: absd)

int absi(int a) {
    return a > 0 ? a : -a;
}

double absd(double a) {
    return a > 0 ? a : -a;
}

int main(void) {
    printf("abs(-2): %d\n", abs(-2));
    printf("abs(2.5): %f\n", abs(2.5));
    return 0;
}