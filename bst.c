/*
 * HW 2 : 이진 탐색 트리 (순환 / 반복 삽입 비교)
 *
 * - 순환(재귀)으로 삽입하는 함수와 반복(while)으로 삽입하는 함수를 각각 구현
 * - 같은 데이터를 두 방식으로 모두 삽입해서 걸리는 시간을 비교
 * - 현재 트리의 전체 노드 개수, 높이, 단말 노드 개수를 구해서 출력
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_DATA 200000
 
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;
 
Node *create_node(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
        return NULL;
 
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
void free_tree(Node *root)
{
    if (root == NULL)
        return;
 
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
 
Node *insert_recursive(Node *root, int key)
{
    if (root == NULL)
        return create_node(key);
 
    if (key < root->key)
        root->left = insert_recursive(root->left, key);
    else if (key > root->key)
        root->right = insert_recursive(root->right, key);
 
    return root;
}
 
Node *insert_iterative(Node *root, int key)
{
    Node *parent = NULL;
    Node *cur = root;
    Node *new_node;
 
    while (cur != NULL) {
        parent = cur;
        if (key < cur->key)
            cur = cur->left;
        else if (key > cur->key)
            cur = cur->right;
        else
            return root;
    }
 
    new_node = create_node(key);
    if (new_node == NULL)
        return root;
 
    if (parent == NULL)
        return new_node;
 
    if (key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;
 
    return root;
}
 
int count_nodes(const Node *root)
{
    if (root == NULL)
        return 0;
 
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}
 
int get_height(const Node *root)
{
    int lh, rh;
 
    if (root == NULL)
        return 0;
 
    lh = get_height(root->left);
    rh = get_height(root->right);
 
    return (lh > rh ? lh : rh) + 1;
}
 
int count_leaves(const Node *root)
{
    if (root == NULL)
        return 0;
 
    if (root->left == NULL && root->right == NULL)
        return 1;
 
    return count_leaves(root->left) + count_leaves(root->right);
}
 
void print_info(const char *title, const Node *root)
{
    printf("[%s]\n", title);
    printf("  전체 노드 개수 : %d\n", count_nodes(root));
    printf("  트리의 높이    : %d\n", get_height(root));
    printf("  단말 노드 개수 : %d\n", count_leaves(root));
}
 
int load_data(const char *filename, int *data, int max)
{
    FILE *fp;
    int n = 0;
 
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s 파일을 열 수 없습니다.\n", filename);
        return -1;
    }
 
    while (n < max && fscanf(fp, "%d", &data[n]) == 1)
        n++;
 
    fclose(fp);
    return n;
}
 
int main(void)
{
    static int data[MAX_DATA];
    Node *root_rec = NULL;
    Node *root_iter = NULL;
    clock_t start, end;
    double time_rec, time_iter;
    int n, i;
 
    n = load_data("data.txt", data, MAX_DATA);
    if (n <= 0) {
        printf("읽어온 데이터가 없습니다.\n");
        return 1;
    }
    printf("읽어온 데이터 개수 : %d\n", n);
 
    start = clock();
    for (i = 0; i < n; i++)
        root_rec = insert_recursive(root_rec, data[i]);
    end = clock();
    time_rec = (double)(end - start) / CLOCKS_PER_SEC;
 
    start = clock();
    for (i = 0; i < n; i++)
        root_iter = insert_iterative(root_iter, data[i]);
    end = clock();
    time_iter = (double)(end - start) / CLOCKS_PER_SEC;
 
    printf("\n=== 삽입 시간 비교 ===\n");
    printf("  순환 : %.4f 초\n", time_rec);
    printf("  반복 : %.4f 초\n", time_iter);
 
    printf("\n=== 구성된 트리 정보 ===\n");
    print_info("순환으로 만든 트리", root_rec);
    print_info("반복으로 만든 트리", root_iter);
 
    free_tree(root_rec);
    free_tree(root_iter);
    return 0;
}