#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode; 

TreeNode* create_node(int data) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(TreeNode* root) {
    if(root != NULL) {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(void) {
    TreeNode* n1 = create_node(15);
    TreeNode* n2 = create_node(4);
    TreeNode* n3 = create_node(20);
    TreeNode* n4 = create_node(1);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;

    preorder(n1);
    printf("\n");

    inorder(n1);
    printf("\n");

    postorder(n1);
    printf("\n");

    free(n1); free(n2);
    free(n3); free(n4);

    return 0;
}
