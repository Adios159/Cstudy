#include "graph.h"

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = NULL;
    graph->vertexCount = 0;

    return graph;
}

void destroy_graph(Graph* g) {
    while(g->vertices != NULL) {
        Vertex* vertices = g->vertices->next;
        destroy_vertex(g->vertices);
        g->vertices = vertices;
    }
    free(g);
}

Vertex* create_vertex(element data) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));

    v->data = data;
    v->next = NULL;
    v->adjacencyList = NULL;
    v->visited = NotVisited;
    v->index = -1;

    return v;
}

void destroy_vertex(Vertex* v) {
    while(v->adjacencyList != NULL) {
        Edge* edge = v->adjacencyList->next;
        destroy_edge(v->adjacencyList);
        v->adjacencyList = edge;
    }
    free(v);
}

Edge* create_edge(Vertex* from, Vertex* target, int weight) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->from = from;
    e->target = target;
    e->next = NULL;
    e->weight = weight;

    return e;
}

void  destroy_edge(Edge* e) {
    free(e);
}

void add_vertex(Graph* g, Vertex* v) {
   Vertex* vertexList = g->vertices;
   if(vertexList == NULL) {
    g->vertices = v;
   } 
   else {
    while(vertexList->next != NULL){
        vertexList = vertexList->next;
    }
    vertexList->next = v;
   }
   v->index = g->vertexCount++;
}

void add_edge(Vertex* v, Edge* e) {
    if(v->adjacencyList == NULL) {
        v->adjacencyList = e;
    }
    else {
        Edge* adjacencyList = v->adjacencyList;
        while(adjacencyList->next != NULL) {
            adjacencyList = adjacencyList->next;
        }
        adjacencyList->next = e;
    }
}

void print_graph(Graph* g) {
   Vertex* v = NULL;
   Edge* e = NULL;
   if((v = g->vertices) == NULL) {
        return;
   }
   while(v != NULL) {
        printf("%c: ", v->data);
        if((e = v->adjacencyList) == NULL) {
            v = v->next;
            printf("\n");
            continue;
        }
        while(e != NULL) {
            printf("%c[%d]", e->target->data, e->weight);
            e = e->next;
        }
        printf("\n");
        v = v->next;
    }
    printf("\n");
}