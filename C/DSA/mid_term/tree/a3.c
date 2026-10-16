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

int get_node_count(TreeNode* root) {
    int cnt = 0;
    if(root != NULL) {
        get_node_count(root->left);
        cnt++;
        get_node_count(root->right);
    }
    return cnt;
}

int get_leaf_count(TreeNode *root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return get_leaf_count(root->left) + get_leaf_count(root->right);
}

int get_height(TreeNode *root) {
    int cnt = 0;
    TreeNode* temp = root;
    if (root == NULL) {
        return 0;
    }
    while(temp->left == NULL) {
        cnt++;
        temp = temp->left;
    }
    return cnt;
}

int main(void) {
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE");
        exit(1);
    }
    int temp = 0;
    TreeNode* root = NULL;
    TreeNode* temp = NULL;
    int cnt = 0;

    while(fscanf(fp, "%d", &temp) != 0) {
        int data = 0;
        fscanf(fp, "%d", &data);
        insert_node(root, data);
        cnt++;
    }
    printf("노드 개수: %d\n", cnt);
    printf("단말 노드 개수: %d\n", get_leaf_count(root));
    printf("트리 높이: %d\n", get_height(root));

    fclose(fp);
    return 0;
}