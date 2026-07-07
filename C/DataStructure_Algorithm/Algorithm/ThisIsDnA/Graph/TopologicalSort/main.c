#include "TopologicalSort.h"

int main(void) {
    Graph* graph = create_graph();

    Vertex* a = create_vertex('A');
    Vertex* b = create_vertex('B');
    Vertex* c = create_vertex('C');
    Vertex* d = create_vertex('D');
    Vertex* e = create_vertex('E');
    Vertex* f = create_vertex('F');
    Vertex* g = create_vertex('G');
    Vertex* h = create_vertex('H');

    add_vertex(graph, a);
    add_vertex(graph, b);
    add_vertex(graph, c);
    add_vertex(graph, d);
    add_vertex(graph, e);
    add_vertex(graph, f);
    add_vertex(graph, g);
    add_vertex(graph, h);

    add_edge(a, create_edge(a, d, 0));
    add_edge(a, create_edge(a, c, 0));

    add_edge(b, create_edge(b, c, 0));
    add_edge(b, create_edge(b, e, 0));

    add_edge(c, create_edge(c, f, 0));

    add_edge(d, create_edge(d, f, 0));
    add_edge(d, create_edge(d, g, 0));

    add_edge(e, create_edge(e, g, 0));

    add_edge(f, create_edge(f, h, 0));

    add_edge(g, create_edge(g, h, 0));

    ListNode* sorted = NULL;
    TopologicalSort(graph->vertices, &sorted);

    printf("Topological order: ");
    print_list(sorted);

    while(sorted != NULL)
        sorted = delete_first(sorted);

    destroy_graph(graph);

    return 0;
}
