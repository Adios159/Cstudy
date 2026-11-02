/* data.txt의 정수들을 최소 히프에 삽입한 뒤, 삭제 연산(delete_min_heap)을 반복하여
   작은 값부터 차례로 출력한다. 각 삭제 후의 히프 배열도 함께 출력한다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType *create(void)
{
    return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void insert_min_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(HeapType *h)
{
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
            child++;
        if (temp.key <= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void print_heap(HeapType *h)
{
    int i;
    for (i = 1; i <= h->heap_size; i++)
        printf("%d ", h->heap[i].key);
    printf("\n");
}

int main(void)
{
    FILE *fp;
    HeapType *heap;
    element e;
    int n, i;

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
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &e.key);
        insert_min_heap(heap, e);
    }
    fclose(fp);

    printf("초기 히프: ");
    print_heap(heap);
    while (heap->heap_size > 0) {
        e = delete_min_heap(heap);
        printf("삭제: %d -> ", e.key);
        print_heap(heap);
    }
    free(heap);
    return 0;
}
