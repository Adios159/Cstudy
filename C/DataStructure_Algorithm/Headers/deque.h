#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 7

typedef  int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

void init_deque(DequeType *q);
int dq_is_empty(DequeType *q);
int dq_is_full(DequeType *q);
void add_front(DequeType *q, element item);
element delete_front(DequeType *q);
element get_front(DequeType *q) ;
void add_rear(DequeType *q, element item) ;
element delete_rear(DequeType *q);
element get_rear(DequeType *q);
void deque_print(DequeType *q);