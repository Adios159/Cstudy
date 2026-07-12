#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int pow_10(int exp) {
    if(exp == 0) return 1;
    return 10 * pow_10(exp - 1);
}

int char_to_int(char num_char[], int idx, int length) {
    if(idx == 0) {
        return (num_char[0] - '0') * pow_10(length - 1);
    }
    return ((num_char[idx] - '0' )*  pow_10(length - 1 - idx)) + char_to_int(num_char, idx - 1, length);
}

int main(void) {
    char num[] = {'1', '2', '3'};
    int ans = char_to_int(num, 2, 3);
    printf("%d\n", ans);
    return 0;
}