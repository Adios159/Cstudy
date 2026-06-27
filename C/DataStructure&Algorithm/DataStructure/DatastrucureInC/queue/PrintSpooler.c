#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct {
    char docName[100];
    int page;
} element;

typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
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
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main() {
    FILE *fp;
    QueueType queue;
    QueueType *q = &queue;
    init_queue(q);

    fp = fopen("doc.txt", "r");
    printf("print spooler simulator.\n");

    if(fp == NULL) {
        printf("NO FILE\n");
        exit(1);
    }

    element doc;
    while(fscanf(fp, "%s %d", doc.docName, &doc.page) == 2) {
        for(int i = 1; i <= doc.page; i++) {
            printf("spooling page %d/%d\n", i, doc.page);
        }
        enqueue(q, doc);
        printf("%s is spooled\n", doc.docName);
        printf("\n");
    }

    fclose(fp);
    return 0;
}