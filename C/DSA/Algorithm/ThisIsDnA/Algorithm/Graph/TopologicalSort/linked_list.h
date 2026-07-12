#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// graph.h가 이미 int를 element로 typedef해서 이름 충돌이 나므로 리스트 쪽은 별도 이름을 쓴다.
typedef Vertex* ListElement;
typedef struct ListNode{
    ListElement data;
    struct ListNode *link;
} ListNode;

ListNode* create_node(ListElement data);
void insert_first(ListNode **head, ListNode *p);
ListNode* insert(ListNode *head, ListNode *pre, ListElement value);
ListNode* delete_first(ListNode *head);
ListNode* delete_node(ListNode *head, ListNode *pre);
void print_list(ListNode *head);