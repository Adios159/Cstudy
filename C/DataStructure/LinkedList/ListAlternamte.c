#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, int value) {
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
        printf("%d->", p->data);
    }
     printf("NULL \n");
}

void alternate_list(ListNode* list1, ListNode* list2, ListNode* result)
{
    ListNode* p = list1;
    ListNode* q = list2;
    ListNode* tail = result;

    while(p != NULL || q != NULL) {
        if(p != NULL) {
            insert(result, tail, p->data);
            tail = tail->link;
            p = p->link;
        }
        if(q != NULL) {
            insert(result, tail, q->data);
            tail = tail->link;
            q = q->link;
        }
    }
}

int main(void) {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head3 = (ListNode*)malloc(sizeof(ListNode));
    head3->link = NULL;

    for(int i = 0; i < 5; i++) {
        head1 = insert_first(head1, 4 - i);
        print_list(head1);
    }
    printf("\n");

    for(int i = 5; i < 10; i++) {
        head2 = insert_first(head2, 4 - i);
        print_list(head2);
    }
    printf("\n");

    alternate_list(head1, head2, head3);
    print_list(head3->link);

    return 0;
}