#include "GraphTravel.h"

void DFS(Vertex* v) {
    Edge* e = NULL;
    printf("%d ", v->data);
    v->visited = Visited;
    e = v->adjacencyList;
    while(e != NULL) {
        if(e->target != NULL && e->target->visited == NotVisited) {
            DFS(e->target);
        }
        e = e->next;
    }
}

void BFS(Vertex* v, LinkedQueue* q) {
    Edge* e = NULL;
    printf("%d ", v->data);
    v->visited = Visited;
    LQ_Enqueue(q ,LQ_CreateNode(v));
    while(!LQ_IsEmpty(q)) {
        Node* popped = LQ_Dequeue(q);
        v = popped->Data;
        e = v->adjacencyList;
        while(e != NULL) {
            v = e->target;
            if(v != NULL && v->visited == NotVisited) {
                printf("%d ", v->data);
                v->visited = Visited;
                LQ_Enqueue(q, LQ_CreateNode(v));
            }
            e = e->next;
        }
    }
    printf("\n");
}