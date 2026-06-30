#include "linked_list.h"

Node* create_node(element data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->Next = NULL;
    return newNode;
}

void destroy_node(Node* node) {
    free(node);
}

void append_node(Node** head, Node* newNode) {
    if((*head) == NULL) {
        *head = newNode;
    }
    else {
        Node* tail = (*head);
        while(tail->Next != NULL) {
            tail = tail->Next;
        }
        tail->Next = newNode;
    }
}

void insert_after(Node* current, Node* newNode) {
    newNode->Next = current->Next;
    current->Next = newNode;
}
void insert_new_head(Node** head, Node* newHead) {
    if(head == NULL) {
        (*head) = newHead;
    }
    else {
        newHead->Next = (*head);
        (*head) = newHead;
    }
}

void remove_node(Node** head, Node* remove) {
    if(*head == remove) {
        *head = remove->Next;
    }
    else {
        Node* current = *head;
        while(current != NULL && current->Next != remove) {
            current = current->Next;
        }
        if(current != NULL) {
            current->Next = remove->Next;
        }
    }
}

Node* get_node_at(Node* head, int location) {
    Node* current = head;
    while(current != NULL && (--location) >= 0) {
        current = current->Next;
    }
    return current;
}

int get_node_count(Node* head) {
    int count = 0;
    Node* current = head;
    while(current != NULL) {
        current = current->Next;
        count++;
    }
    return count;
}
