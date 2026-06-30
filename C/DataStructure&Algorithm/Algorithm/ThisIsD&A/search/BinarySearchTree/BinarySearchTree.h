#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    element data;
} TreeNode;

TreeNode* create_node(element newData);
void destroy_node(TreeNode* node);
void destroy_tree(TreeNode* tree);
TreeNode* search_node(TreeNode* tree, element target);
TreeNode* search_min_node(TreeNode* tree);
void insert_node(TreeNode* tree, TreeNode* child);
TreeNode* remove_node(TreeNode* tree, TreeNode* parent, element target);
void inorder_print(TreeNode* node);