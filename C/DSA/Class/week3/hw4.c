#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 레벨 순회를 위한 큐 정의
typedef struct Queue {
    Node* items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = node;
}

Node* dequeue(Queue* q) {
    if (is_empty(q)) {
        return NULL;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->items[q->front];
}

Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        exit(0);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// 레벨 순회 (BFS)
void level_order(Node* root) {
    if (root == NULL) return;

    Queue q;
    init_queue(&q);

    // 1. 루트 노드를 큐에 삽입
    enqueue(&q, root);

    // 2. 큐가 빌 때까지 반복
    while (!is_empty(&q)) {
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        // 왼쪽 자식이 있으면 큐에 삽입
        if (curr->left != NULL) {
            enqueue(&q, curr->left);
        }
        // 오른쪽 자식이 있으면 큐에 삽입
        if (curr->right != NULL) {
            enqueue(&q, curr->right);
        }
    }
}

// 전위 순회 (V -> L -> R)
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 중위 순회 (L -> V -> R)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// 후위 순회 (L -> R -> V)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* n1 = create_node(1);
    Node* n2 = create_node(4);
    Node* n3 = create_node(16);
    Node* n4 = create_node(25);
    Node* n5 = create_node(20);
    Node* n6 = create_node(15);

    /*
            트리 구조:
                15 (n6)
               /   \
             4(n2)  20(n5)
            /       /   \
          1(n1)  16(n3) 25(n4)
    */

    n2->left = n1;
    n6->left = n2; n6->right = n5;
    n5->left = n3; n5->right = n4;

    printf("Level-order: ");
    level_order(n6);
    printf("\n");

    printf("Inorder    : ");
    inorder(n6);
    printf("\n");

    printf("Preorder   : ");
    preorder(n6);
    printf("\n");

    printf("Postorder  : ");
    postorder(n6);
    printf("\n");

    free(n1); free(n2); free(n3);
    free(n4); free(n5); free(n6);

    return 0;
}