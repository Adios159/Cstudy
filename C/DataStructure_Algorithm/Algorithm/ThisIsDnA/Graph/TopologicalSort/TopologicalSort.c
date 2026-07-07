#include "TopologicalSort.h"

void TopologicalSort(Vertex* v, ListNode** list) {
    while(v != NULL) {
        if(v->visited == NotVisited)
            dfs(v, list);
        v = v->next;
    }
}
void dfs(Vertex* v, ListNode** list) {
    ListNode* newHead = NULL;
    Edge* e = NULL;

    v->visited = Visited;
    e = v->adjacencyList;

    while(e != NULL) {
        if(e->target != NULL && e->target->visited == NotVisited)
            dfs(e->target, list);
        e = e->next;
    }
    printf("%c\n", v->data);
    newHead = create_node(v);
    insert_first(list, newHead);
}