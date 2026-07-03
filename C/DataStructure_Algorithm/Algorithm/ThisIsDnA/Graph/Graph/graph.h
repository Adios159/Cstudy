#pragma once
#include <stdio.h>
#include <stdlib.h>

enum VisitNode {
    Visited,
    NotVisited
};
typedef int element;
typedef struct Vertex {
    element data;
    int visited;
    int index;
    struct Vertex* next;
    struct Edge* adjacencyList;
} Vertex;

typedef struct Edge {
    int weight;
    struct Edge* next;
    Vertex* from;
    Vertex* target;
} Edge;

typedef struct Graph {
    Vertex* vertices;
    int vertexCount;
} Graph;

Graph* create_graph();
void destroy_graph(Graph* g);
Vertex* create_vertex(element data);
void destroy_vertex(Vertex* v);
Edge* create_edge(Vertex* from, Vertex* target, int weight);
void  destroy_edge(Edge* e);
void add_vertex(Graph* g, Vertex* v);
void add_edge(Vertex* v, Edge* e);
void print_graph(Graph* g);