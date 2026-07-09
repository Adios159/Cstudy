#include "../Graph/graph.h"
#include "GraphTravel.h"

int main(void) {
    Graph* g = create_graph();

    Vertex* v1 = create_vertex(1);
    Vertex* v2 = create_vertex(2);
    Vertex* v3 = create_vertex(3);
    Vertex* v4 = create_vertex(4);
    Vertex* v5 = create_vertex(5);
    Vertex* v6 = create_vertex(6);
    Vertex* v7 = create_vertex(7);

    add_vertex(g, v1);
    add_vertex(g, v2);
    add_vertex(g, v3);
    add_vertex(g, v4);
    add_vertex(g, v5);
    add_vertex(g, v6);
    add_vertex(g, v7);

    add_edge(v1, create_edge(v1, v2, 0));
    add_edge(v1, create_edge(v1, v3, 0));

    add_edge(v2, create_edge(v2, v4, 0));
    add_edge(v2, create_edge(v2, v5, 0));

    add_edge(v3, create_edge(v3, v4, 0));
    add_edge(v3, create_edge(v3, v6, 0));
    
    add_edge(v4, create_edge(v4, v5, 0));
    add_edge(v4, create_edge(v4, v7, 0));
    
    add_edge(v5, create_edge(v5, v7, 0));

    add_edge(v6, create_edge(v6, v7, 0));

    int mode;
    printf("Enter mode(0:DFS, 1:BFS): ");
    scanf("%d", &mode);

    if(mode == 0) {
        DFS(g->vertices);
    }
    else {
        LinkedQueue* q = NULL;
        LQ_CreateQueue(&q);

        BFS(v1, q);
        LQ_DestroyQueue(q);
    }
    destroy_graph(g);
    return 0;
}