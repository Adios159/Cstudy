#include "heap.h"

int main(void) {
    Heap* h = create(3);
    HeapNode minNode;

    insert(h, 12);
    insert(h, 87);
    insert(h, 111);
    insert(h, 34);
    insert(h, 16);
    insert(h, 75);
    print_nodes(h);

    for(int i = 0; i < 6; i++) {
        delete_min(h, &minNode);
        print_nodes(h);
    }

    return 0;
}