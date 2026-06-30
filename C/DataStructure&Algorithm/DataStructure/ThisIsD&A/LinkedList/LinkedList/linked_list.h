#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct node* Next;
} Node;

Node* create_node(element data);
void destroy_node(Node* node);
void append_node(Node** head, Node* newNode);
void insert_after(Node* current, Node* newNode);
void insert_new_head(Node** head, Node* newHead);
void remove_node(Node** head, Node* remove);
Node* get_node_at(Node* head, int location);
int get_node_count(Node* head);