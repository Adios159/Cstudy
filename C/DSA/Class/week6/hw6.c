#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode; 

TreeNode* create_node(int data) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    if(temp == NULL) {
        return NULL;
    }
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(TreeNode* root) {
    if(root != NULL) {
        printf("[%d] ", root->data);
        inorder(root->left);
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

int get_height(TreeNode* root) {
    if(root == NULL) {
        return NULL;
    }
    return 1 + max(get_height(root->left), max(get_height(root->right)));
}

int get_node_count(TreeNode* root) {
    if(root == NULL) {
        return NULL;
    }
    return 1 + max(get_node_count(root->left), max(get_node_count(root->right)));
}

int get_leaf_count(TreeNode* root) {
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }
    return get_leaf_count(root->left) + get_leaf_count(root->right);
}

int is_perfect_tree(TreeNode* root) {
    int node_count = 0, leaf_count = 0, tree_height = 0;
    if(root == NULL) {
        return 0;
    }

    tree_height = get_height(root);
    node_count = get_node_count(root);
    leaf_count = get_leaf_count(root);


}

int main(void) {
    int e;
    TreeNode* root = NULL;
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE");
        exit(1);
    }

    while(fscanf(fp, "%d", &e) == 1) {
        if(insert_node(root, e)) {
            printf("insert success\n");
        }
        else {
            printf("insert fail\n");
        }
    }
    
    printf("\npreorder: ");
    preorder(root);

    int node_count = 0, leaf_count = 0, tree_height = 0;
    tree_height = get_height(root);
    node_count = get_node_count(root);
    leaf_count = get_leaf_count(root);

    fclose(fp);
    return 0;
}