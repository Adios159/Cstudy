#include "PriorityQueue.h"

PQueue* create(int initSize) {
    PQueue* pq = (PQueue*)malloc(sizeof(PQueue));
    pq->capacity = initSize;
    pq->usedSize = 0;
    pq->nodes = (PQueueNode*)malloc(sizeof(PQueue) * pq->capacity);

    return pq;
}

void destroy(PQueue* pq) {
    free(pq->nodes);
    free(pq);
}

void enqueue(PQueue* pq, PQueueNode newNode) {
    int currentPosition = pq->usedSize;
    int parentPosition = get_parent(currentPosition);

    if(pq->usedSize == pq->capacity) {
        if(pq->capacity == 0)
            pq->capacity = 1;
        pq->capacity *= 2;
        pq->nodes = (PQueueNode*)realloc(pq->nodes, sizeof(PQueue) * pq->capacity);
    }
    pq->nodes[currentPosition] = newNode;
    
    while(currentPosition > 0 &&
    pq->nodes[currentPosition].priority < pq->nodes[parentPosition].priority) {
        swap_nodes(pq, currentPosition, parentPosition);
        currentPosition = parentPosition;
        parentPosition = get_parent(currentPosition);
    }
    pq->usedSize++;
}

void  dequeue(PQueue* pq, PQueueNode* root) {
    int parentPosition = 0;
    int leftPosition = 0;
    int rightPosition = 0;

    memcpy(root, &pq->nodes[0], sizeof(PQueueNode));
    memcpy(&pq->nodes[0], 0, sizeof(PQueueNode));
    pq->usedSize--;
    swap_nodes(pq, 0, pq->usedSize);

    while(1) {
        int selectedChild = 0;
        if(leftPosition >= pq->usedSize)
            break;
        if(rightPosition >= pq->usedSize)
            selectedChild = leftPosition;
        else {
            if(pq->nodes[leftPosition].data > pq->nodes[rightPosition].data)
                selectedChild = rightPosition;
            else
                selectedChild = leftPosition;
        }
        if(pq->nodes[selectedChild].data < pq->nodes[parentPosition].data) {
            swap_nodes(pq, parentPosition, selectedChild);
            parentPosition = selectedChild;
        }
        else 
            break;
        
        leftPosition = get_left_child(parentPosition);
        rightPosition = leftPosition + 1;
    }

    if(pq->usedSize < (pq->capacity / 2)) {
        pq->capacity /= 2;
        pq->nodes = (PQueueNode*)realloc(pq->nodes, sizeof(PQueueNode) * pq->capacity);
    }
}

int get_parent(int index) {
    return (int)((index - 1) / 2);
}

int get_left_child(int index) {
    return (2 * index) + 1;
}

void swap_nodes(PQueue* pq, int index1, int index2) {
    int copySize = sizeof(PQueueNode);
    PQueueNode* temp = (PQueueNode*)malloc(copySize);

    memcpy(temp, &pq->nodes[index1], copySize);
    memcpy(&pq->nodes[index1], &pq->nodes[index2], copySize);
    memcpy(&pq->nodes[index2], temp, copySize);
    free(temp);
}

void is_empty(PQueue* pq) {
    return (pq->usedSize == 0);
}

