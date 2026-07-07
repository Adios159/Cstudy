#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, int value);
ListNode* insert(ListNode *head, ListNode *pre, element value);
ListNode* delete_first(ListNode *head);
ListNode* delete_node(ListNode *head, ListNode *pre);
void print_list(ListNode *head);