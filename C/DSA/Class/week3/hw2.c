#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        exit(0);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main(void) {
    Node* n1 = create_node(10);
    Node* n2 = create_node(20);
    Node* n3 = create_node(30);

    n1->left = n2;
    n1->right = n3;

    printf("      %d      \n", n1->data);
    printf("      |   \\ \n");
    printf("      %d    %d\n", n2->data, n3->data);

    free(n1); free(n2); free(n3);
    return 0;
}