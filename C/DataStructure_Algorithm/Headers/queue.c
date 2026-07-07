#include "queue.h"
#include "common.h"


void init(QueueType *q) {
    q->rear = -1;
    q->front = -1;
}

int queue_is_full(QueueType *q) {
    if(q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int queue_is_empty(QueueType *q) {
    if(q->front == q->rear) 
        return 1;
    else    
        return 0;
}

void enqueue(QueueType *q, element item) {
    if(queue_is_full(q)) {
        error("queue overflow");
        return;
    }
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {
    if(queue_is_empty(q)) {
        error("queue underflow");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}

void queue_print(QueueType *q) {
    for(int i = 0; i<MAX_QUEUE_SIZE; i++) {
        if(i <= q->front || i > q->rear)
            printf(" | ");
        else 
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}