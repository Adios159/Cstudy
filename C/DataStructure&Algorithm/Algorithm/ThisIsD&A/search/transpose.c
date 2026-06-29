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

ListNode* transpose(ListNode** head, element target) {
    ListNode* current = (*head);
    ListNode* pPrevious = NULL;
    ListNode* previous = NULL;
    ListNode* match = NULL;

    while(current != NULL) {
        if(current->data == target) {
            match = current;
            if(previous != NULL) {
                if(pPrevious != NULL)
                    pPrevious->link = current;
                else
                    (*head) = current;
                previous->link = current->link;
                current->link = previous;
            }
            break;
        }
        else {
            if(previous != NULL) 
                pPrevious = previous;
            previous = current;
            current = current->link;
        }
    }
    return match;
}

int main(void) {
    ListNode *head = NULL;
    ListNode **hPointer = &head;

    for(int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    printf("\n");

    ListNode* find = transpose(hPointer, 3);
    printf("where is node 3: %p\n", find);
    print_list(head);

    for(int i = 0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }

    return 0;
}