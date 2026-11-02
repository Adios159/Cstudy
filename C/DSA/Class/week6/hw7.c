#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int key;            // 우선순위
    char name[30];      // 동물 이름
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int heap_size;
} HeapType;

// 힙 초기화
void init_heap(HeapType* h) {
    h->heap_size = 0;
}

// 최대 힙 삽입 연산
void insert_max_heap(HeapType* h, Element item) {
    int i = ++(h->heap_size);

    // 부모 노드와 비교하며 위치 찾아 올라감
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

// 힙 배열 순서대로 출력 (루트부터 인덱스 1..heap_size)
void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d: %s > ", h->heap[i].key, h->heap[i].name);
    }
    printf("\n");
}

int main() {
    HeapType h;
    init_heap(&h);

    // 1. data.txt 파일에서 데이터 읽어오기
    FILE* fp = fopen("data.txt", "r");
    if (fp != NULL) {
        Element item;
        while (fscanf(fp, "%d %s", &item.key, item.name) == 2) {
            printf(">>%d %s\n", item.key, item.name);
            insert_max_heap(&h, item);
            print_heap(&h);
            printf("\n");
        }
        fclose(fp);
    } else {
        printf("data.txt 파일을 열 수 없습니다.\n");
    }

    // 2. 사용자 입력 받기
    while (1) {
        Element item;
        printf("힙에 데이터를 넣을 동물의 우선순위와 이름을 입력하시오(완료시 우선순위 0)\n>>");
        if (scanf("%d", &item.key) != 1 || item.key == 0) {
            break;
        }
        scanf("%s", item.name);

        insert_max_heap(&h, item);
        print_heap(&h);
        printf("\n");
    }

    return 0;
}