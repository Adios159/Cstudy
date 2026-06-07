#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;

typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create() {
    ListType *plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    if (temp == NULL) error("메모리 할당 에러");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if (plist->tail == NULL) {
        plist->head = plist->tail = temp;
    } else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

// 🔧 pow() 대신 정수 거듭제곱 함수 사용
int ipow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

// 🔧 노드까지 완전히 해제하는 함수 추가
void free_list(ListType* plist) {
    ListNode* cur = plist->head;
    while (cur) {
        ListNode* next = cur->link;
        free(cur);
        cur = next;
    }
    free(plist);
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;

    while (a && b) {
        if (a->expon == b->expon) {
            sum = a->coef + b->coef;
            if (sum != 0) insert_last(plist3, sum, a->expon);
            a = a->link;
            b = b->link;
        } else if (a->expon > b->expon) {
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        } else {
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }

    for (; a != NULL; a = a->link)
        insert_last(plist3, a->coef, a->expon);
    for (; b != NULL; b = b->link)
        insert_last(plist3, b->coef, b->expon);
}

// 🔧 마지막 + 제거
void poly_print(ListType* plist) {
    ListNode* p = plist->head;
    printf("polynomial: ");
    while (p) {
        int c = p->coef;
        int e = p->expon;

        // 첫 항이 아니면 부호 분리 출력
        if (p != plist->head) {
            if (c < 0) { printf(" - "); c = -c; }
            else        { printf(" + "); }
        } else {
            if (c < 0) { printf("-"); c = -c; }
        }

        // 계수 출력 (1이고 지수가 0이 아니면 생략)
        if (c != 1 || e == 0) printf("%d", c);

        // 지수 출력
        if      (e == 0) { /* 상수항: 계수만 */ }
        else if (e == 1) printf("x");
        else             printf("x^%d", e);

        p = p->link;
    }
    printf("\n");
}

int calc_poly(ListType* plist, int x_val) {
    ListNode* p = plist->head;
    int sum = 0;
    for (; p; p = p->link) {
        sum += p->coef * ipow(x_val, p->expon);
    }
    return sum;
}

int main(void) {
    ListType *list1, *list2, *list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    poly_add(list1, list2, list3);
    poly_print(list3);

    // 🔧 반환값 출력 추가
    printf("list1 at x=2: %d\n", calc_poly(list1, 2));
    printf("list2 at x=2: %d\n", calc_poly(list2, 2));
    printf("list3 at x=2: %d\n", calc_poly(list3, 2));

    // 🔧 노드까지 완전 해제
    free_list(list1);
    free_list(list2);
    free_list(list3);

    return 0;
}