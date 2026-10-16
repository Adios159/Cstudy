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

void inorder(TreeNode* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

TreeNode* insert_node(TreeNode* node, int data) {
    if (node == NULL) {
        return create_node(data);
    }

    if (data < node->data) {
        node->left = insert_node(node->left, data);
    } 
    else if (data > node->data) {
        node->right = insert_node(node->right, data);
    }

    return node; 
}

void free_tree(TreeNode* root) {
    if(root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }   
}
int main(void) {
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE");
        exit(1);
    }

    TreeNode* root = NULL;
    int temp = 0;
    int cnt = 0;
    while(fscanf(fp, "%d", &temp) >= 1) {
        root = insert_node(root, temp);
        cnt++;
    }
    printf("개수: %d\n", cnt);
    inorder(root);
    printf("\n");

    fclose(fp);
    free_tree(root);
    return 0;
}