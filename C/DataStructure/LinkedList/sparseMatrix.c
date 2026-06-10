#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int num;
} element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode *head) {
    if(head == NULL)
        return NULL;
    ListNode *removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre) {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head) {
    for(ListNode *p = head; p != NULL; p = p->link) {
        printf("(%d, %d, %d)->", p->data.row, p->data.col, p->data.num);
    }
     printf("NULL \n");
}

int main() {
    ListNode *head = NULL;
    element matrix_data;
    FILE *fp;
    int data, row, col;

    printf("input matrix`s rows, cols: ");
    scanf("%d %d", &row, &col);
    fp = fopen("sparse.txt", "r");
    if(fp == NULL) {
        printf("NO FILE");
        exit(1);
    }

    for(int i = 1; i <= col; i++) {
        for(int j = 1; j <= row; j++) {
            fscanf(fp, "%d", &data);
            if(data != 0) {
                matrix_data.col = i;
                matrix_data.row = j;
                matrix_data.num = data;
                head = insert_first(head, matrix_data);
                print_list(head);
            }
        }
    }

    fclose(fp);
    return 0;
}