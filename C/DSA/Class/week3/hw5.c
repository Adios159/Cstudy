#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 100
#define MAX_MEANING 200

// 이진 탐색 트리 노드 구조체
typedef struct TreeNode {
    char word[MAX_WORD];
    char meaning[MAX_MEANING];
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 노드 생성
TreeNode* create_node(char *word, char *meaning) {
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    strcpy(new_node->word, word);
    strcpy(new_node->meaning, meaning);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// 노드 삽입 (알파벳순 비교)
TreeNode* insert_node(TreeNode *root, char *word, char *meaning) {
    if (root == NULL) {
        return create_node(word, meaning);
    }

    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insert_node(root->left, word, meaning);
    } else if (cmp > 0) {
        root->right = insert_node(root->right, word, meaning);
    } else {
        strcpy(root->meaning, meaning); // 이미 존재하는 단어는 뜻 갱신
    }
    return root;
}

// 오른쪽 서브트리에서 가장 작은 노드 탐색 (후계자 찾기)
TreeNode* min_value_node(TreeNode *node) {
    TreeNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// 노드 삭제
TreeNode* delete_node(TreeNode *root, char *word) {
    if (root == NULL) return NULL;

    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = delete_node(root->left, word);
    } else if (cmp > 0) {
        root->right = delete_node(root->right, word);
    } else {
        // 자식이 0개 또는 1개인 경우
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // 자식이 2개인 경우: 오른쪽 서브트리의 최솟값 노드로 대체
        TreeNode *temp = min_value_node(root->right);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = delete_node(root->right, temp->word);
    }
    return root;
}

// 노드 탐색
TreeNode* search_node(TreeNode *root, char *word) {
    if (root == NULL) return NULL;

    int cmp = strcmp(word, root->word);
    if (cmp == 0) return root;
    else if (cmp < 0) return search_node(root->left, word);
    else return search_node(root->right, word);
}

// 중위 순회(Inorder Traversal) 출력 (오름차순)
void display_inorder(TreeNode *root) {
    if (root != NULL) {
        display_inorder(root->left);
        printf("트리노드(%s : %s)->", root->word, root->meaning);
        display_inorder(root->right);
    }
}

// 트리 메모리 해제
void free_tree(TreeNode *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("data.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    TreeNode *root = NULL;
    char command;
    char word[MAX_WORD];
    char meaning[MAX_MEANING];

    printf("--------------------------------\n");

    while (fscanf(fp, " %c", &command) != EOF) {
        if (command == 'q') {
            break;
        }

        switch (command) {
            case 'i': // 단어 삽입
                fscanf(fp, "%s %s", word, meaning);
                root = insert_node(root, word, meaning);
                printf("%s : %s 삽입\n", word, meaning);
                break;

            case 'd': // 단어 삭제
                fscanf(fp, "%s", word);
                root = delete_node(root, word);
                printf("%s 삭제\n", word);
                break;

            case 's': // 단어 탐색
                fscanf(fp, "%s", word);
                {
                    TreeNode *found = search_node(root, word);
                    if (found != NULL) {
                        printf("단어 %s의 의미:%s\n", found->word, found->meaning);
                    } else {
                        printf("단어 %s을(를) 찾을 수 없습니다.\n", word);
                    }
                }
                break;

            case 'p': // 트리 중위 순회 출력 (실행 예시 오타 dispaly 반영)
                printf("dispaly : \n");
                display_inorder(root);
                printf("\n");
                break;

            default:
                break;
        }
        printf("--------------------------------\n");
    }

    fclose(fp);
    free_tree(root);
    return 0;
}