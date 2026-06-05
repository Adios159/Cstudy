#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 7

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(QueueType *q) {
    q->rear = -1;
    q->front = -1;
}

int is_full(QueueType *q) {
    if(q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(QueueType *q) {
    if(q->front == q->rear) 
        return 1;
    else    
        return 0;
}

void enqueue(QueueType *q, element item) {
    if(is_full(q)) {
        error("queue overflow");
        return;
    }
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {
    if(is_empty(q)) {
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

int main()
{
    int item = 0;
    QueueType q;

    init(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);

    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);

    return 0;
}
