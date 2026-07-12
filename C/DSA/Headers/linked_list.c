#include "linked_list.h"
#include "common.h"


ListNode* create_node(element data) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = data;
    p->link = NULL;   // 힌트: 아직 리스트 어디에도 안 붙은 노드야, link는 뭐가 자연스러울까?
    return p;
}

void insert_first(ListNode **head, ListNode *p) {
    // p는 이미 만들어진 노드. 여기선 연결만.
    p->link = *head;
    *head = p;
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

ListNode* delete_node(ListNode *head, ListNode *pre) {
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

