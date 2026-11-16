/*
data.txt 첫째 줄의 키로 이진 탐색 트리를 만들고, 둘째 줄의 키를
반복문 방식의 delete_node 로 하나씩 삭제하면서 매번 중위/전위 순회 결과를 출력한다.
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

int read_keys(FILE *fp, int *a, int max)
{
    int n = 0, c;
    while (n < max) {
        c = fgetc(fp);
        while (c == ' ' || c == '\t' || c == '\r') c = fgetc(fp);
        if (c == '\n' || c == EOF) break;
        ungetc(c, fp);
        if (fscanf(fp, "%d", &a[n]) != 1) break;
        n++;
    }
    return n;
}

void delete_node(TreeNode **root, int key)
{
    TreeNode *p, *child, *succ, *succ_p, *t;
    p = NULL;
    t = *root;
    while (t != NULL && t->key != key) {
        p = t;
        t = (key < t->key) ? t->left : t->right;
    }
    if (t == NULL) {
        printf("key is not in the tree\n");
        return;
    }
    if ((t->left == NULL) && (t->right == NULL)) {
        if (p != NULL) {
            if (p->left == t) p->left = NULL;
            else p->right = NULL;
        }
        else *root = NULL;
    }
    else if ((t->left == NULL) || (t->right == NULL)) {
        child = (t->left != NULL) ? t->left : t->right;
        if (p != NULL) {
            if (p->left == t) p->left = child;
            else p->right = child;
        }
        else *root = child;
    }
    else {
        succ_p = t;
        succ = t->right;
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        if (succ_p->left == succ) succ_p->left = succ->right;
        else succ_p->right = succ->right;
        t->key = succ->key;
        t = succ;
    }
    free(t);
}

int main(void)
{
    FILE *fp;
    TreeNode *root = NULL;
    int keys[50];
    int n, i;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    n = read_keys(fp, keys, 50);
    for (i = 0; i < n; i++) insert_node(&root, keys[i]);
    printf("[초기 트리]\n");
    show(root);
    n = read_keys(fp, keys, 50);
    for (i = 0; i < n; i++) {
        printf("delete %d\n", keys[i]);
        delete_node(&root, keys[i]);
        show(root);
    }
    fclose(fp);
    free_tree(root);
    return 0;
}
