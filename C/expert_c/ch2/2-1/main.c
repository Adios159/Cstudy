#include  <stdio.h>
#include "h2-1.h"

int main(int argc, char** argv) {
    int array[5] = {10, 3, 5, -8, 9};
    double average = avg(array, 5, NORMAL);
    printf("average: %f\n", average);

    average = avg(array, 5, SQUARED);
    printf("average: %f\n", average);

    return 0;
}