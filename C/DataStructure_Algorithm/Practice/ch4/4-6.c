#include <stdio.h>
#include <stdlib.h>


double harmonic_number(double num) {
    if(num == 0.0) {
        return 0.0;
    }
    return harmonic_number(num - 1) + 1.0 / num;
}
int main(void) {
    double ans = 0;
    ans = harmonic_number(5);
    printf("%f \n", ans);
    return 0;
}