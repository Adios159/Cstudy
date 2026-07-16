#ifndef CIRCLE_LLIST_H
#define CIRCLE_LLIST_H

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void print_list(ListNode* head);
void free_list(ListNode* head);
ListNode* insert_first(ListNode* head, element data);
ListNode* insert_last(ListNode* head, element data);

#endif // CIRCLE_LLIST_H
