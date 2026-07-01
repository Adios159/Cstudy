#include "heap.h"

Heap* create(int initSize) {
    Heap* newHeap = (Heap*)malloc(sizeof(Heap));
    newHeap->capacity = initSize;
    newHeap->usedSize = 0;
    newHeap->nodes = (HeapNode*)malloc(sizeof(HeapNode) * newHeap->capacity);
    
    printf("size: %d\n", sizeof(HeapNode));
    return newHeap;
}

void destroy(Heap* h) {
    free(h->nodes);
    free(h);
}

void insert(Heap* h, element data) {
    int currentPosition = h->usedSize;
    int parentPosition = get_parent(currentPosition);
    if(h->usedSize == h->capacity) {
        h->capacity *= 2;
        h->nodes = (HeapNode*)realloc(h->nodes, sizeof(HeapNode) * h->capacity);
    }
    h->nodes[currentPosition].data = data;

    while(currentPosition > 0 && h->nodes[currentPosition].data < h->nodes[parentPosition].data) {
        swap_nodes(h, currentPosition, parentPosition);
        currentPosition = parentPosition;
        parentPosition = get_parent(currentPosition);
    }
    h->usedSize++;
}

void  delete_min(Heap* h, HeapNode* root) {
    int parentPosition = 0;
    int leftPosition = 0;
    int rightPosition = 0;

    memcpy(root, &h->nodes[0], sizeof(HeapNode));
    memcpy(&h->nodes[0], 0, sizeof(HeapNode));
    h->usedSize--;
    swap_nodes(h, 0, h->usedSize);

    while(1) {
        int selectedChild = 0;
        if(leftPosition >= h->usedSize)
            break;
        if(rightPosition >= h->usedSize)
            selectedChild = leftPosition;
        else {
            if(h->nodes[leftPosition].data > h->nodes[rightPosition].data)
                selectedChild = rightPosition;
            else
                selectedChild = leftPosition;
        }
        if(h->nodes[selectedChild].data < h->nodes[parentPosition].data) {
            swap_nodes(h, parentPosition, selectedChild);
            parentPosition = selectedChild;
        }
        else 
            break;
        
        leftPosition = get_left_child(parentPosition);
        rightPosition = leftPosition + 1;
    }

    if(h->usedSize < (h->capacity / 2)) {
        h->capacity /= 2;
        h->nodes = (HeapNode*)realloc(h->nodes, sizeof(HeapNode) * h->capacity);
    }
}

int get_parent(int index) {
    return (int)((index - 1) / 2);
}

int get_left_child(int index) {
    return (2 * index) + 1;
}

void swap_nodes(Heap* h, int index1, int index2) {
    int copySize = sizeof(HeapNode);
    HeapNode* temp = (HeapNode*)malloc(copySize);

    memcpy(temp, &h->nodes[index1], copySize);
    memcpy(&h->nodes[index1], &h->nodes[index2], copySize);
    memcpy(&h->nodes[index2], temp, copySize);
    free(temp);
}

void print_nodes(Heap* h) {
    int i = 0;
    for(i = 0; i < h->usedSize; i++) {
        printf("%d ", h->nodes[i].data);
    }
    printf("\n");
}