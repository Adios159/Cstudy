#include "/home/adios/Cstudy/C/DSA/Headers/Datastructure/LL/linked_list.h"
#include <stdio.h>

int is_same_list(ListNode* head, ListNode* node1, ListNode* node2) {
    ListNode* temp = head;
    int have_node1 = 0;
    int have_node2 = 0;
    if(head == NULL) {
        return 0;
    }
    if(node1 == node2) {
        return 0;
    }
    while(temp != NULL) {
        if(temp == node1 && temp != node2) {
            have_node1 = 1;
            temp = temp->link;
        }
        else if(temp == node2 && temp != node1) {
            have_node2 = 1;
            temp = temp->link;
        }
        else {
            temp = temp->link;
        }
    }
    return have_node1 && have_node2;
}