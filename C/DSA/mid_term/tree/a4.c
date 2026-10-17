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

void preorder(TreeNode* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postrder(TreeNode* root) {
    if(root != NULL) {
        postrder(root->left);
        postrder(root->right);
        printf("%d ", root->data);
    }
}

int insert_node(TreeNode **root, int data)
{
    TreeNode *p, *t;
    TreeNode *n;
    t = *root;
    p = NULL;
    while (t != NULL) {
        if (data == t->data) return 1;
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
    return 0;
}


int main(void) {
    int node = 0, same = 0, e = 0;
    TreeNode* root = NULL;

    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE");
        exit(1);
    }

    while(fscanf(fp, "%d", &e) == 1) {
        if(insert_node(&root, e) == 1) {
            same++;
        }
        else node++;
    }

    printf("Preorder: "); preorder(root); printf("\n");
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Postrder: "); postrder(root); printf("\n");
    printf("노드개수: %d, 중복개수: %d\n", node, same);

    fclose(fp);
    return 0;
}