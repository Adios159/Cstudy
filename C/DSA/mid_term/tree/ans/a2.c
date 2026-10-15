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
    int n, i;
    int *arr;
    TreeNode *root = NULL;
    TreeNode *t;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }
    if (fscanf(fp, "%d", &n) != 1 || n <= 0) {
        fclose(fp);
        return 1;
    }
    arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        fclose(fp);
        return 1;
    }
    for (i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            n = i;
            break;
        }
    }
    fclose(fp);

    printf("입력 순서: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        insert_node(&root, arr[i]);
    }
    printf("\n");
    printf("중위 순회: ");
    inorder(root);
    printf("\n");

    if (root != NULL) {
        t = root;
        while (t->left != NULL) t = t->left;
        printf("최솟값: %d\n", t->key);
        t = root;
        while (t->right != NULL) t = t->right;
        printf("최댓값: %d\n", t->key);
    }

    free_tree(root);
    free(arr);
    return 0;
}