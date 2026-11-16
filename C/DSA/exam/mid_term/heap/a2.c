/* data.txt의 정수들을 최대 히프에 넣은 뒤, delete_max_heap을 반복 호출하여
   내림차순으로 모두 꺼내 출력하는 프로그램 */
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

element delete_max_heap(HeapType *h)
{
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
            child++;
        if (temp.key >= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
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
    if (fscanf(fp, "%d", &n) != 1) {
        fclose(fp);
        return 1;
    }
    heap = create();
    if (heap == NULL) {
        fclose(fp);
        return 1;
    }
    init(heap);
    for (i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &e.key) != 1) break;
        insert_max_heap(heap, e);
    }
    fclose(fp);
    printf("히프: ");
    print_heap(heap);
    printf("삭제 순서:");
    while (heap->heap_size > 0) {
        e = delete_max_heap(heap);
        printf(" %d", e.key);
    }
    printf("\n");
    free(heap);
    return 0;
}
