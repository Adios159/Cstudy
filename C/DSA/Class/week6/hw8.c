#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int key;            // 입장 번호 (우선순위)
    char name[30];      // 손님 이름
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int heap_size;
} HeapType;

void init_heap(HeapType* h) {
    h->heap_size = 0;
}

// 최소 힙 삽입 연산
void insert_min_heap(HeapType* h, Element item) {
    int i = ++(h->heap_size);

    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

// 최소 힙 삭제 연산
Element delete_min_heap(HeapType* h) {
    int parent, child;
    Element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
            child++;

        if (temp.key <= h->heap[child].key)
            break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;

    // 앞 사람이 퇴장하면 힙에 남아있는 모든 손님의 번호를 1씩 당김
    for (int i = 1; i <= h->heap_size; i++) {
        h->heap[i].key--;
    }

    return item;
}

// 배열 기반 완전이진트리의 중위 순회 (In-order: Left -> Root -> Right)
void inorder(HeapType* h, int index) {
    if (index <= h->heap_size) {
        inorder(h, index * 2);                          // 왼쪽 자식
        printf("%d - %s\n", h->heap[index].key, h->heap[index].name); // 루트
        inorder(h, index * 2 + 1);                      // 오른쪽 자식
    }
}

int main() {
    HeapType h;
    init_heap(&h);

    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("data.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    char command;
    while (fscanf(fp, " %c", &command) == 1) {
        if (command == 'i') {
            Element item;
            fscanf(fp, "%s", item.name);
            item.key = h.heap_size + 1; // 대기 순번 부여

            printf(">> 손님(%s) 입장\n", item.name);
            insert_min_heap(&h, item);

            printf("< 히프 중위 순회 출력 >\n");
            inorder(&h, 1);
            printf("\n");
        } else if (command == 'o') {
            if (h.heap_size > 0) {
                Element out = delete_min_heap(&h);
                printf(">> 손님(%s) 퇴장\n", out.name);
                printf("< 히프 중위 순회 출력 >\n");
                inorder(&h, 1);
                printf("\n");
            }
        }
    }

    fclose(fp);
    return 0;
}