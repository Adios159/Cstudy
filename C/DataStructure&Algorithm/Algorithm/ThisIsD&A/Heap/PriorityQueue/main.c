#include "PriorityQueue.h"

void print_nodes(PQueueNode* pq) {
    printf("Task name: %s \tPriority: %d", pq->data, pq->priority);
}

int main(void) {
    PQueue* pq = create(3);
    PQueueNode popped;

    PQueueNode nodes[7] = {
        {34, (void*)"coding"},
        {12, (void*)"meeting customer"},
        {87, (void*)"make coffee"},
        {45, (void*)"documentation"},
        {35, (void*)"debugging"},
        {66, (void*)"brush teeth"},
    };

    for(int i = 0; i < 7; i++) {
        enqueue(pq, nodes[i]);
    }
    printf("remained tasks in queue: %d\n", pq->usedSize);
   
    destroy(pq);
    return 0;
}