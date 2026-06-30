#include "linked_list.h"

int main(void) {
    int i = 0;
    int count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* newNode = NULL;

    for(i = 0; i < 5; i++) {
        newNode = create_node(i);
        append_node(&list, newNode);
    }

    newNode = create_node(-1);
    insert_new_head(&list, newNode);

    newNode = create_node(-2);
    insert_new_head(&list, newNode);

    count = get_node_count(list);
    for(i = 0; i < count; i++) {
        current = get_node_at(list, i);
        printf("List[%d] : %d\n", i, current->data);
    }

    printf("\nInserting 3000 After [2]... \n\n");
    current = get_node_at(list, 2);
    newNode = create_node(3000);
    insert_after(current, newNode);

    count = get_node_count(list);
    for(i = 0; i < count; i++) {
        current = get_node_at(list, i);
        printf("List[%d] : %d\n", i, current->data);
    }

    printf("\nDestroy all node\n");
    for(i = 0; i < count; i++) {
        current = get_node_at(list, 0);
        if(current != NULL) {
            remove_node(&list, current);
            destroy_node(current);
        }
    }
    return 0;
}