#include "/home/adios/Cstudy/C/DSA/Headers/Datastructure/LL/linked_list.h"
#include <stdio.h>

ListNode* find_middle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL) {
        if(fast->link != NULL && fast->link->link != NULL) {
            slow = slow->link;
        fast = fast->link->link;
        }
        else {
            break;
        }
    }
    return slow;
}