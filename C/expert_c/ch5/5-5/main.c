#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front, rear;
    double* arr;
} queue; 

void init(queue* q)  {
    q->front = q->rear = 0;
    q->arr = (double*)malloc(MAX_QUEUE_SIZE * sizeof(double));   
}

void destroy(queue* q) {
    free(q->arr); 
} 

int size(queue* q) {
    return q->rear - q->front;
}  

void enqueue(queue* q, double item) {
    q->arr[q->rear] = item;
    q->rear++;
}  

double dequeue(queue* q) {
    double item = q->arr[q->front];
    q->front++;
    return item;
}

int main()  {
    queue* q = (queue*)malloc(sizeof(queue));

    init(q);

    enqueue(q, 6.5);
    enqueue(q, 3.4);
    enqueue(q, 1.2);

    printf("%f\n", dequeue(q));
    printf("%f\n", dequeue(q));
    printf("%f\n", dequeue(q));

    destroy(q);
    free(q);

    return 0;
}
