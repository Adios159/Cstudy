#include "deque.h"
#include "common.h"


void init_deque(DequeType *q) {
    q->front = q->rear = 0;
}

int dq_is_empty(DequeType *q) {
    return (q->front == q->rear);
}

int dq_is_full(DequeType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void add_front(DequeType *q, element item) {
    if(dq_is_full(q)) {
        error("deque overflow");
    }
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(DequeType *q) {
    if(dq_is_empty(q))
        error("deque uunderflow");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q) {
    if(dq_is_empty(q))
        error("deque underflow");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_rear(DequeType *q, element item) {
    if(dq_is_full(q)) {
        error("deque overflow");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_rear(DequeType *q) {
    int prev = q->rear;
    if(dq_is_empty(q))
        error("deque uunderflow");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_rear(DequeType *q) {
    if(dq_is_empty(q))
        error("deque underflow");
    return q->data[q->rear];
}



void deque_print(DequeType *q) {
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!dq_is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
            if(i == q->rear)
                break;
        } while(i != q->front);
    }
    printf("\n");
}