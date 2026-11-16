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

void find_min(TreeNode* root) {
    TreeNode* curr = root;
    int cnt = 0;
    while(curr->left != NULL) {
        curr = curr->left;
        cnt++;
    }
    printf("최솟값: %d (왼쪽으로 %d번 이동함)\n", curr->data, cnt);
}

void find_max(TreeNode* root) {
    TreeNode* curr = root;
    int cnt = 0;
    while(curr->right != NULL) {
        curr = curr->right;
        cnt++;
    }
    printf("최댓값: %d (오른쪽으로 %d번 이동함)\n", curr->data, cnt);
}

void free_tree(TreeNode* root) {
    if(root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }   
}

int main() {
    TreeNode* root = NULL;
    TreeNode** head = &root;
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("NO FILE");
        exit(1);
    }

    int temp = 0;
    while(fscanf(fp, "%d", &temp) >= 1) {
        insert_node(head, temp);
    }

    find_min(root);
    find_max(root);
    free_tree(root);

    fclose(fp);
    return 0;

}