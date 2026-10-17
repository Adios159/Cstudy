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

void delete_node(TreeNode **root, int data)
{
    TreeNode *p, *child, *succ, *succ_p, *t;
    p = NULL;
    t = *root;
    while (t != NULL && t->data != data) {
        p = t;
        t = (data < t->data) ? t->left : t->right;
    }
    if (t == NULL) { printf("data is not in the tree\n"); return; }
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
        t->data = succ->data;
        t = succ;
    }
    free(t);
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
    if(fp == NULL) {
        printf("NO FILE");
        exit(1);
    }

    int e;
    while(fscanf(fp, "%d ", &e) == 1) {
        insert_node(&root, e);
    }
    printf("[초기 트리]\n");
    printf("중위순회: ");
    inorder(root);
    printf("\n후위순회: ");
    preorder(root);
    printf("\n");

    while(fscanf(fp, "%d", &e) == 1) {
        delete_node(&root, e);
        printf("중위순회: ");
        inorder(root);
        printf("\n전위순회: ");
        preorder(root);
        printf("\n");
    }

    fclose(fp);
    free_tree(root);
    return 0;
}