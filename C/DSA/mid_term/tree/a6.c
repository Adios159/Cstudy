/*
 * BST를 만들고 원형 큐에 노드 포인터를 넣고 빼면서 위에서 아래로, 왼쪽에서 오른쪽으로 레벨 순회한다.
 * 큐 크기가 8로 작아도 원형 구조 덕분에 11개 노드를 모두 처리할 수 있음을 확인한다.
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

#define MAX_QUEUE 8

typedef struct {
    TreeNode *data[MAX_QUEUE];
    int front, rear;
} QueueType;

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return q->front == q->rear;
}

int is_full(QueueType *q)
{
    return (q->rear + 1) % MAX_QUEUE == q->front;
}

void enqueue(QueueType *q, TreeNode *item)
{
    if (is_full(q)) {
        printf("큐가 포화상태입니다\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->data[q->rear] = item;
}

TreeNode *dequeue(QueueType *q)
{
    if (is_empty(q)) {
        printf("큐가 공백상태입니다\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE;
    return q->data[q->front];
}

void level_order(TreeNode *root)
{
    QueueType q;
    TreeNode *t;
    init_queue(&q);
    if (root == NULL) return;
    enqueue(&q, root);
    while (!is_empty(&q)) {
        t = dequeue(&q);
        printf("%d ", t->key);
        if (t->left != NULL) enqueue(&q, t->left);
        if (t->right != NULL) enqueue(&q, t->right);
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

    printf("level order: ");
    level_order(root);
    printf("\n");

    free_tree(root);
    return 0;
}
