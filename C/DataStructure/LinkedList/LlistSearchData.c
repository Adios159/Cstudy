#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

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

element find_data(ListNode* head, element search) {
    for(ListNode *p = head; p != NULL; p = p->link) {
        if(p->data == search) {   
            return TRUE;
        }
    }
    return FALSE;   
}

int main(void) {
    ListNode *head = NULL;

    for(int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    printf("\n");

    if (find_data(head, 3)) 
        printf("List have data\n");
    else
        printf("List do not have data\n");

    if (find_data(head, 10)) 
        printf("List have data\n");
    else
        printf("List do not have data\n");


    printf("\n");

    for(int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}