#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS
#define MAX_VERTICES 100

int main(void) {
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        exit(1);
    }

    int vertex, n;
    fscanf(fp, "%d %d", &vertex, &n);
    int start, end; 
    int vertices[MAX_VERTICES] = {0};

    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d %d", &start, &end);
        vertices[start]++;
        vertices[end]++;
    }

    int max = 0;
    for(int i = 0; i < vertex; i++) {
        printf("vertex %d: %d\n", i, vertices[i]);
        if(vertices[i] >= max) {
            max = vertices[i];
        }
    }
    printf("vertex with max edge: ");
    for(int i = 0; i < vertex; i++) {
        if(vertices[i] == max) {
            printf("%d ", i);
        }
    }

    printf("\nodd edge vertex: ");
    for(int i = 0; i < vertex; i++) {
        if(vertices[i] % 2 == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    fclose(fp);
    return 0;
}