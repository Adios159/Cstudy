#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 7

typedef  int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)) {
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

void enqueue(QueueType *q, element data) {
    if(is_full(q)) 
        error("queue overflow");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

element dequeue(QueueType *q) {
    if(is_empty(q)) {
        error("queue underflow");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q) {
    if(is_empty(q)) {
            error("queue underflow");
        }
    return q->data[(q->front * 1) % MAX_QUEUE_SIZE];
}

int main(void) {
    QueueType queue;
    int data;

    init_queue(&queue);
    printf("---Add phase---\n");
    while(!is_full(&queue)) {
        printf("input number: ");
        scanf("%d",&data);
        enqueue(&queue, data);
        queue_print(&queue);
    }
    printf("queue is full!\n\n");

    printf("---delete phase ---\n");
    while(!is_empty(&queue)) {
        data = dequeue(&queue);
        printf("output number: %d \n", data);
        queue_print(&queue);
    }

    printf("queue is empty\n\n");

    return 0;
}