#include "BinarySearchTree.h"

TreeNode* create_node(element newData) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    return newNode;
}

void destroy_node(TreeNode* node) {
    free(node);
}

void destroy_tree(TreeNode* tree) {
    if(tree->right != NULL)
        destroy_tree(tree->right);
    if(tree->left != NULL)
        destroy_tree(tree->left);
    
    tree->left = NULL;
    tree->right = NULL;
    destroy_node(tree);
}

TreeNode* search_node(TreeNode* tree, element target) {
    if(tree == NULL)
        return NULL;
    if(tree->data == target)
        return tree;
    else if(tree->data > target)
        return search_node(tree->left, target);
    else
        return search_node(tree->right, target);
}

TreeNode* search_min_node(TreeNode* tree) {
    if(tree == NULL)
        return NULL;
    if(tree->left == NULL)
        return tree;
    else    
        return search_min_node(tree->left);
}

void insert_node(TreeNode* tree, TreeNode* child) {
    if(tree->data < child->data) {
        if(tree->right == NULL)
            tree->right = child;
        else
            insert_node(tree->right, child);
    }
    else if(tree->data > child->data) {
        if(tree->left == NULL)
            tree->left = child;
        else
            insert_node(tree->left, child);
    }
}

TreeNode* remove_node(TreeNode* tree, TreeNode* parent, element target) {
    TreeNode* removed = NULL;

    if(tree == NULL)
        return NULL;
    if(tree->data > target)
        removed = remove_node(tree->left, tree, target);
    else if(tree->data < target)
        removed = remove_node(tree->right, tree, target);
    else {
        removed = tree;
        if(tree->left == NULL && tree->right == NULL) {
            if(parent->left == tree)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else {
            if(tree->left != NULL && tree->right != NULL) {
                TreeNode* minNode = search_min_node(tree->right);
                minNode = remove_node(tree, NULL, minNode->data);
                tree->data = minNode->data;
            }
            else {
                TreeNode* temp = NULL;
                if(tree->left != NULL)
                    temp = tree->left;
                else
                    temp = tree->right;
                if(parent->left == tree)
                    parent->left = temp;
                else 
                    parent->right = temp;
            }
        }
    }
    return removed;
}

void inorder_print(TreeNode* node) {
    if(node == NULL)
        return;
    inorder_print(node->left);
    printf("%d ", node->data);
    inorder_print(node->right);
}