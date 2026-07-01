#pragma once
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int element;
typedef struct HeapNode {
    element data;
} HeapNode;

typedef struct Heap {
    HeapNode* nodes;
    int capacity;
    int usedSize;
} Heap;

Heap* create(int initSize);
void destroy(Heap* h);
void insert(Heap* h, element data);
void  delete_min(Heap* h, HeapNode* root);
int get_parent(int index);
int get_left_child(int index);
void swap_nodes(Heap* h, int index1, int index2);
void print_nodes(Heap* h);