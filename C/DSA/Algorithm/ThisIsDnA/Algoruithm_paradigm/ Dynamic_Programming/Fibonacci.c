#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong;

ulong fibonacci(int n) {
    int i;
    ulong result;
    ulong* fibonacciTable;

    if(n == 0 || n == 1)
        return n;
    
    fibonacciTable = (ulong*)malloc(sizeof(ulong) * (n + 1));
    fibonacciTable[0] = 0;
    fibonacciTable[1] = 1;

    for(i = 2; i <= n; i++) {
        fibonacciTable[i] = fibonacciTable[i - 1] + fibonacciTable[i - 2];
    }
    result = fibonacciTable[n];
    free(fibonacciTable);
    return result;
}

int main() {
    int n = 46;
    ulong result = fibonacci(n);

    printf("Fibonacci(%d): %lu\n", n, result);
    return 0;
}