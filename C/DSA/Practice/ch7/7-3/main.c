#include "linked_list.h"

int count_node(ListNode* head, int cnt) {
    if(head == NULL) {
        return cnt;
    }
    return count_node(head->link, cnt + 1);
}

int main(void) {
     ListNode *head = NULL;

    for(int i = 0; i < 5; i++) {
        insert_first(&head, create_node(i));
    }
    print_list(head);
    int ans = count_node(head, 0);
    printf("node: %d\n", ans);
    return 0;
}