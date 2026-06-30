#include "DList.h"

Node* create_node(element data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

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
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    }
}

void insert_after(Node* current, Node* newNode) {
    newNode->next = current->next;
    newNode->prev = current;
    if(current->next != NULL) {
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void remove_node(Node** head, Node* remove) {
    if(*head == remove) {
        *head = remove->next;
        if((*head) != NULL){
            (*head)->prev = NULL;
        }
        remove->prev = NULL;
        remove->next = NULL;
    }
    else {
        Node* temp = remove;
        if(remove->prev != NULL) {
            remove->prev->next = temp->next;
        }
        if(remove->next != NULL) {
            remove->next->prev = temp->prev;
        }
        remove->prev = NULL;
        remove->next = NULL;
    }
}

Node* get_node_at(Node* head, int location) {
    Node* current = head;
    while(current != NULL && (--location) >= 0) {
        current = current->next;
    }
    return current;
}

int get_node_count(Node* head) {
    unsigned int count = 0;
    Node* current = head;
    while(current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

void print_node(Node* _node) {
    if(_node->prev == NULL) {
        printf("Prev: NULL");
    }
    else {
        printf("Prev: %d", _node->prev->data);
        printf("Current: %d", _node->data);
    }
    if(_node->next == NULL) {
        printf("Next: NULL\n");
    }
    else {
        printf("Next: %d\n", _node->next->data);
    }
}