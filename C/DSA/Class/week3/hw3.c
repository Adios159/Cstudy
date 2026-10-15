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

//L -> M -> R
void inorder(Node* root) {
    if(root == NULL) {
        exit(1);
    }
    inorder(root->left);
    printf("[%d] ", root->data);
    inorder(root->right);
}

//M -> L -> R
void preorder(Node* root) {
    if(root == NULL) {
        exit(1);
    }
    printf("[%d] ", root->data);
    preorder(root->left); 
    preorder(root->right);
}

//L -> R -> M
void postorder(Node* root) {
    if(root == NULL) {
        exit(1);
    }
    postorder(root->left);
    postorder(root->right);
    printf("[%d] ", root->data);
}

int main() {
    Node* n1 = create_node(1);
    Node* n2 = create_node(4);
    Node* n3 = create_node(16);
    Node* n4 = create_node(25);
    Node* n5 = create_node(20);
    Node* n6 = create_node(15);

    n2->left = n1;
    n6->left = n2; n6->right = n5;
    n5->left = n3; n5->right = n4;

    inorder(n6);
    preorder(n6);
    postorder(n6);

    free(n1); free(n2); free(n3);
    free(n4); free(n5); free(n6);

    return 0;
}