#pragma once
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int element;
typedef struct PQueueNode {
    void* data;
    element priority;

} PQueueNode;

typedef struct PQueue {
    PQueueNode* nodes;
    int capacity;
    int usedSize;
} PQueue;

PQueue* create(int initSize);
void destroy(PQueue* pq);
void enqueue(PQueue* pq, PQueueNode newNode);
void dequeue(PQueue* pq, PQueueNode* root);
int get_parent(int index);
int get_left_child(int index);
void swap_nodes(PQueue* pq, int index1, int index2);
void is_empty(PQueue* pq);
void print_nodes(PQueueNode* pq);