#include "CircleList.h"

int main(void) {
    int i = 0;
    int count = 0;
    Node* list = NULL;
    Node* newNode = NULL;
    Node* current = NULL;
    
    for(i = 0; i < 5; i++) {
        newNode = create_node(i);
        append_node(&list, newNode);
    }

    count = get_node_count(list);
    for(i = 0; i < count; i++) {
        current = get_node_at(list, i);
        printf("Lisr[%d]: %d\n", i, current->data);
    }

    current = get_node_at(list, 2);
    newNode = create_node(3000);
    insert_after(current, newNode);
    printf("\nInserting 3000 After [2]...\n\n");

    current = get_node_at(list, 2);
    remove_node(list, current);
    destroy_node(current);
    printf("\nRemoving node at [2]...\n");

    count = get_node_count(list);
    for(i = 0; i < count * 2; i++) {
        if(i == 0)
            current = list;
        else
            current = current->next;
        
            printf("List[%d] : %d\n", i, current->data);
    }

    count = get_node_count(list);
    for(i = 0; i < count; i++) {
        current = get_node_at(list, 0);
        if(current != NULL) {
            remove_node(&list, current);
            destroy_node(current);
        }
    }

    return 0;
}