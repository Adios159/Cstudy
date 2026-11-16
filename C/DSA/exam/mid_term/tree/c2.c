/*
data.txt 에서 읽은 키로 BST 를 만들고, 최소값 삭제와 최대값 삭제를
반복문으로 구현하여 몇 번 수행한 뒤 남은 키를 큰 순서대로 모두 삭제한다.
*/
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

void inorder(TreeNode *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(TreeNode *root)
{
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void free_tree(TreeNode *root)
{
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

void show(TreeNode *root)
{
    if (root == NULL) {
        printf("  (빈 트리)\n");
        return;
    }
    printf("  중위: ");
    inorder(root);
    printf("\n  전위: ");
    preorder(root);
    printf("\n");
}

int delete_min(TreeNode **root)
{
    TreeNode *p, *t;
    int key;
    if (*root == NULL) return -1;
    p = NULL;
    t = *root;
    while (t->left != NULL) {
        p = t;
        t = t->left;
    }
    key = t->key;
    if (p != NULL) p->left = t->right;
    else *root = t->right;
    free(t);
    return key;
}

int delete_max(TreeNode **root)
{
    TreeNode *p, *t;
    int key;
    if (*root == NULL) return -1;
    p = NULL;
    t = *root;
    while (t->right != NULL) {
        p = t;
        t = t->right;
    }
    key = t->key;
    if (p != NULL) p->right = t->left;
    else *root = t->left;
    free(t);
    return key;
}

int main(void)
{
    FILE *fp;
    TreeNode *root = NULL;
    int n, i, key;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    if (fscanf(fp, "%d", &n) != 1) {
        fclose(fp);
        return 1;
    }
    for (i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &key) != 1) break;
        insert_node(&root, key);
    }
    fclose(fp);
    printf("[초기 트리]\n");
    show(root);
    for (i = 0; i < 2; i++) {
        key = delete_min(&root);
        printf("delete_min -> %d\n", key);
        show(root);
    }
    for (i = 0; i < 2; i++) {
        key = delete_max(&root);
        printf("delete_max -> %d\n", key);
        show(root);
    }
    printf("남은 키를 큰 순서대로 삭제:");
    while ((key = delete_max(&root)) != -1) printf(" %d", key);
    printf("\n");
    show(root);
    free_tree(root);
    return 0;
}
