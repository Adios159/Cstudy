#include <stdio.h>

typedef unsigned long ulong;
typedef struct matrix {
    ulong data[2][2];
} matrix;

matrix multiply_matrix(matrix a, matrix b) {
    matrix c;
    c.data[0][0] = a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0];
    c.data[0][1] = a.data[0][0] * b.data[1][0] + a.data[0][1] * b.data[1][1];
    c.data[1][0] = a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0];
    c.data[1][1] = a.data[1][0] * b.data[1][0] + a.data[1][1] * b.data[1][1];

    return c;
}

matrix matrix_power(matrix a, int n) {
    if(n > 1) {
        a = matrix_power(a, n / 2);
        a = multiply_matrix(a, a);
        if(n & 1) {
            matrix b;
            b.data[0][0] = 1;
            b.data[0][1] = 1;
            b.data[1][0] = 1;
            b.data[1][1] = 0;

            a = multiply_matrix(a, b);
        }
    }
    return a;
}

ulong fibonacci(int n) {
    matrix a;
    a.data[0][0] = 1;
    a.data[0][1] = 1;
    a.data[1][0] = 1;
    a.data[1][1] = 0;

    a = matrix_power(a, n);
    return a.data[0][1];
}

int main(void) {
    int n = 46;
    ulong result = fibonacci(n);

    printf("Fibonacci(%d): %lu\n", n, result);
    return 0;
}