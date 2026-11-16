#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

void insert_node(TreeNode **root, int key)
{
    TreeNode *p, *t;
    TreeNode *n;
    t = *root;
    p = NULL;
    while (t != NULL) {
        if (key == t->key) return;
        p = t;
        if (key < t->key) t = t->left;
        else t = t->right;
    }
    n = (TreeNode *)malloc(sizeof(TreeNode));
    if (n == NULL) return;
    n->key = key;
    n->left = n->right = NULL;
    if (p != NULL) {
        if (key < p->key) p->left = n;
        else p->right = n;
    }
    else *root = n;
}

int get_node_count(TreeNode *t)
{
    if (t == NULL) return 0;
    return 1 + get_node_count(t->left) + get_node_count(t->right);
}

int get_leaf_count(TreeNode *t)
{
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 1;
    return get_leaf_count(t->left) + get_leaf_count(t->right);
}

int get_height(TreeNode *t)
{
    int lh, rh;
    if (t == NULL) return 0;
    lh = get_height(t->left);
    rh = get_height(t->right);
    return 1 + (lh > rh ? lh : rh);
}

void free_tree(TreeNode *t)
{
    if (t == NULL) return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

int main(void)
{
    FILE *fp;
    int key;
    TreeNode *root = NULL;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    while (fscanf(fp, "%d", &key) == 1)
        insert_node(&root, key);
    fclose(fp);

    printf("노드 수: %d\n", get_node_count(root));
    printf("단말 노드 수: %d\n", get_leaf_count(root));
    printf("높이: %d\n", get_height(root));

    free_tree(root);
    return 0;
}
