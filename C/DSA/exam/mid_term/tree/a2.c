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
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

TreeNode* insert_node(TreeNode* node, int data) {
    if(node == NULL) {
        return create_node(data);
    }
    if(data < node->data) {
        node->left = insert_node(node->left, data);
    }
    else if(data > node->data) {
        node->right = insert_node(node->right, data);
    }
}

int find_max(TreeNode* root) {
    TreeNode* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

int find_min(TreeNode* root) {
    TreeNode* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

int main(void) {
    TreeNode* root = NULL;
    TreeNode* temp = NULL;
    int arr[20];
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE\n");
        return 1;
    }
    int idx = 1;

    while(!feof) {
        int data = 0;
        fscanf(fp, "%d", &data);
        insert_node(root, data);
        arr[idx] = data;
        idx++;
    }
    printf("data list: ");
    for(int i = 1; i <= 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("inorder tree: ");
    inorder(root);
    printf("\n");

    printf("min data: %d\n", find_min(root));
    printf("max data: %d\n", find_max(root));
    fclose(fp);

    return 0;
}