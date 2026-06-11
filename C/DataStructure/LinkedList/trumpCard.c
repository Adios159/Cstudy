#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    char shape;
} element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode *head) {
    if(head == NULL)
        return NULL;
    ListNode *removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre) {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_card(element card) {
    char *faces[] = {"A", "2", "3", "4", "5", "6", "7",
                     "8", "9", "10", "J", "Q", "K"};
    printf("[%s%c]", faces[card.num - 1], card.shape);
}

void print_list(ListNode *head) {
    for(ListNode *p = head; p != NULL; p = p->link) {
        print_card(p->data);
        printf(" -> ");
    }
    printf("NULL\n");
}

void shuffle(ListNode **head) {
    ListNode *arr[52];
    ListNode *cur = *head;
    int cnt = 0;
    while(cur != NULL) {
        arr[cnt++] = cur;
        cur = cur->link;   // next 아니고 link
    }

    for(int i = cnt - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        ListNode *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    *head = arr[0];
    for(int i = 0; i < cnt - 1; i++) {
        arr[i]->link = arr[i + 1];
    }
    arr[cnt - 1]->link = NULL;
}

int main() {
    ListNode *head = NULL;
    element card;
    
    char cmd = ' ';
    char suit[4] = {'s', 'h', 'c', 'd'};
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= 13; j++) {
            card.num = j;
            card.shape = suit[i];
            head = insert_first(head, card);
        }
    }

    printf("card simulater\n");
    while(1) {
        printf("choose command(d, s, p, q): ");
        scanf(" %c", &cmd);
        switch(cmd) {
            case 'd':
                if(head == NULL) { printf("no card left\n"); break; }
                print_card(head->data);
                printf(" drawn!\n");
                head = delete_first(head);
                break;
            case 's':
                shuffle(&head);
                break;
            case 'p':
                print_list(head);
                break;
            case 'q':
                free(head);
                printf("shutdown simulation\n");
                return 0;
            default:
                printf("wrong command\n");
                break;
        }
    }

}