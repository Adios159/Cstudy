#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode; 

TreeNode* create_node(int data) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(TreeNode* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postrder(TreeNode* root) {
    if(root != NULL) {
        postrder(root->left);
        postrder(root->right);
        printf("%d ", root->data);
    }
}

void insert_node(TreeNode **root, int data)
{
    TreeNode *p, *t;
    TreeNode *n;
    t = *root;
    p = NULL;
    while (t != NULL) {
        if (data == t->data) return;
        p = t;
        if (data < t->data) t = t->left;
        else t = t->right;
    }
    n = (TreeNode *)malloc(sizeof(TreeNode));
    if (n == NULL) return;
    n->data = data;
    n->left = n->right = NULL;
    if (p != NULL) {
        if (data < p->data) p->left = n;
        else p->right = n;
    }
    else *root = n;
}

void free_tree(TreeNode* root) {
    if(root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main(void) {
    TreeNode* root = NULL;
    FILE* fp = fopen("data.txt", "r");
    if(!fp) {
        printf("NO FILE!");
        exit(1);
    }

    int n = 0;
    if(fscanf(fp, "%d", &n) != 1) {
        exit(1);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        fscanf(fp, "%d", &n);
        insert_node(&root, n);
        cnt++;
    }

    printf("중위 순회: "); inorder(root); printf("\n");
    printf("삭제 순서: "); postrder(root); printf("\n");
    printf("해제 할 노드 개수: %d\n", cnt);
    free_tree(root); fclose(fp); printf("Tree is free!\n");

    return 0;
}