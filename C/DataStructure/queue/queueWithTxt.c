#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

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
            printf("  |  ");
        else 
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp;
    QueueType queue;
    QueueType *q = &queue;
    element num;
    init(q);

    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE\n");
        exit(1);
    }
    while(fscanf(fp, "%d", &num) == 1) {
        enqueue(q, num);
        queue_print(q);
    }
    
    for(int i = 0; i <= q->rear; i++) {
        dequeue(q);
        queue_print(q);
    }

    fclose(fp);
    return 0;
}