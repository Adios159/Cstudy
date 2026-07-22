#include "/home/adios/Cstudy/C/DSA/Headers/Datastructure/LL/linked_list.h"
#include <stdio.h>

ListNode* combine(ListNode* head1, ListNode* head2) {
    ListNode* temp = head1;
    while(temp->link != NULL) {
        temp = temp->link;
    }
    ListNode* temp2 = head2;
    while(temp2 != NULL) {
        insert(temp, temp, temp2->data);
        temp2 = temp2->link;
        temp = temp->link;
    }
    return head1;
}

int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    for(int i = 0; i < 5; i++) {
        insert_first(&head1, create_node(i));
        insert_first(&head2, create_node(i + 5));
    }
    print_list(head1);
    print_list(head2);
    combine(head1, head2);
    print_list(head1);
    return 0;
}