#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct { int key; } element;
typedef struct { element heap[MAX_ELEMENT]; int heap_size; } HeapType;

HeapType *create(void)
{
    return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void print_heap(HeapType *h)
{
    int i;
    if (h->heap_size == 0) {
        printf("(empty)\n");
        return;
    }
    for (i = 1; i <= h->heap_size; i++) {
        if (i > 1) printf(" ");
        printf("%d", h->heap[i].key);
    }
    printf("\n");
}

void insert_max_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

int main(void)
{
    FILE *fp;
    HeapType *heap;
    element e;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    heap = create();
    if (heap == NULL) {
        fclose(fp);
        return 1;
    }
    init(heap);
    while (fscanf(fp, "%d", &e.key) == 1) {
        insert_max_heap(heap, e);
        printf("insert %2d: ", e.key);
        print_heap(heap);
    }
    printf("루트: %d, 원소 수: %d\n", heap->heap[1].key, heap->heap_size);
    fclose(fp);
    free(heap);
    return 0;
}
