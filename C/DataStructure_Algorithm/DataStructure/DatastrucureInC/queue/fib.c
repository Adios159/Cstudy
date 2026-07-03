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

int peek(QueueType *q) {
    if(is_empty(q)) {
        error("queue underflow");
        return -1;
    }
    return q->data[(q->front + 1)];
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

void calc_fib(QueueType* q, int num) {
    init(q);
    int sum = 0;
    enqueue(q, 0); enqueue(q, 1);

    if(num == 0)      printf("answer: 0\n");
    else if(num < 0)  printf("error");
    else if(num == 1) printf("answer: 0\n");
    else if(num == 2) printf("answer: 1\n");
    else {
        for(int i = 2; i < num; i++) {
            sum = dequeue(q) + peek(q);
            enqueue(q, sum);
        }
        printf("answer: %d\n", q->data[q->rear]);
    }
}

int main(void) {
    QueueType q;
    init(&q);

    calc_fib(&q, 0);
    calc_fib(&q, 1);
    calc_fib(&q, 5);
    calc_fib(&q, -2);

    return 0;
}