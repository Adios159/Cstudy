#include "linked_list.h"
#include "common.h"
#include "random.h"

int return_second(ListNode* head) {
    ListNode* temp = head;
    while(1) {
        if(temp->link->link == NULL) {
            return  temp->data;
        }
        temp = temp->link;
    }
}

int main() {
    ListNode* head = NULL;
    rng_t rng;   
    rng_seed(&rng, 0);

    for(int i = 0; i < 5; i++) {
        int data = rng_int(&rng, 0, 100);
        ListNode* node = create_node(data);
        insert_first(&head, node);
    }
    print_list(head);
    int ans = return_second(head);
    printf("second node: %d\n", ans);
    return 0;
}