#include "stack.h"
#include "queue.h"
#include "deque.h"
#include "linked_list.h"

int main(void) {
    // 스택 테스트
    StackType s;
    init_stack(&s);
    push(&s, 10);
    push(&s, 20);
    printf("[stack] peek = %d\n", peek(&s));

    // 큐 테스트
    QueueType q;
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    printf("[queue] dequeue = %d\n", dequeue(&q));

    // 덱 테스트
    DequeType d;
    init_deque(&d);
    add_rear(&d, 100);
    add_front(&d, 50);
    deque_print(&d);

    // 연결 리스트 테스트
    ListNode *head = NULL;
    head = insert_first(head, 1);
    head = insert_first(head, 2);
    print_list(head);

    return 0;
}
