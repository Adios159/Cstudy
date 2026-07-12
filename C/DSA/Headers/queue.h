#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 7

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void init(QueueType *q);
int queue_is_full(QueueType *q);
int queue_is_empty(QueueType *q);
void enqueue(QueueType *q, element item);
int dequeue(QueueType *q);
void queue_print(QueueType *q);
