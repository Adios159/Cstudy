#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE");
        return 1;
    }
    int n, sum, temp, max;
    fscanf(fp, "%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &temp);
        arr[i] = temp;
        sum += temp;
        if(temp > max) {
            max = temp;
        }
    }
    
    printf("개수: %d\n", n);
    printf("합: %d\n", sum);
    printf("평균: %.2f\n", (float)(sum / n));
    printf("최댓값: %d\n", max);
    
    fclose(fp);
    free(arr);

    return 0;
}
