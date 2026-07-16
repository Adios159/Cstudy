#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef int element;

typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead);
void print_dlist(DListNode* phead);
void dinsert(DListNode* before, element data);
void ddelete(DListNode* head, DListNode* removed);

#endif // DOUBLE_LIST_H
