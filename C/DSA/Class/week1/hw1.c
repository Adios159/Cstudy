/*
 * HW 1 : 단순 연결 리스트 + 버블정렬
 *
 * - data.txt(학번 이름 총점)를 읽어 동적 할당으로 단순 연결 리스트에 저장
 * - 이름은 글자 수만큼만(strlen + 1) 동적 할당해서 최소 메모리 사용
 * - 버블정렬 3가지
 *     1) 학번 : 오름차순 (선배 = 학번이 작은 사람 먼저)
 *     2) 이름 : 가나다순 (ㄱ 먼저)
 *     3) 총점 : 내림차순 (높은 점수 먼저)
 */
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100              

typedef struct Node {
    int id;                       
    char *name;                   
    int score;                    
    struct Node *next;
} Node;

/* ---------------- 단순 연결 리스트 함수 ---------------- */


Node *create_node(int id, const char *name, int score)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
        return NULL;

    node->name = (char *)malloc(strlen(name) + 1);
    if (node->name == NULL) {
        free(node);
        return NULL;
    }

    strcpy(node->name, name);
    node->id = id;
    node->score = score;
    node->next = NULL;
    return node;
}

void insert_last(Node **head, Node *new_node)
{
    Node *cur;

    if (*head == NULL) {         
        *head = new_node;
        return;
    }
    cur = *head;
    while (cur->next != NULL)     
        cur = cur->next;
    cur->next = new_node;
}

void display_list(const Node *head)
{
    const Node *p;

    for (p = head; p != NULL; p = p->next)
        printf("%d\t%s\t%d\n", p->id, p->name, p->score);
}

void free_list(Node *head)
{
    Node *next;

    while (head != NULL) {
        next = head->next;
        free(head->name);
        free(head);
        head = next;
    }
}

/* ---------------- 파일 입력 ---------------- */

Node *load_data(const char *filename)
{
    FILE *fp;
    Node *head = NULL;
    Node *node;
    int id, score;
    char name[MAX_NAME];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s 파일을 열 수 없습니다.\n", filename);
        return NULL;
    }

    while (fscanf(fp, "%d %99s %d", &id, name, &score) == 3) {
        node = create_node(id, name, score);
        if (node == NULL) {
            printf("메모리 할당 실패\n");
            break;
        }
        insert_last(&head, node);
    }

    fclose(fp);
    return head;
}

/* ---------------- 버블정렬 (노드 자체를 교환) ---------------- */

/* 비교 함수: a가 b보다 뒤로 가야 하면(= 자리를 바꿔야 하면) 1 반환 */
int need_swap_by_id(const Node *a, const Node *b)
{
    return a->id > b->id;                   
}

int need_swap_by_name(const Node *a, const Node *b)
{
    return strcmp(a->name, b->name) > 0;    
}

int need_swap_by_score(const Node *a, const Node *b)
{
    return a->score < b->score;             
}

int list_length(const Node *head)
{
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void bubble_sort(Node **head_ref, int (*need_swap)(const Node *, const Node *))
{
    int n = list_length(*head_ref);
    int i, j;
    int swapped;

    if (n < 2)
        return;

    for (i = 0; i < n - 1; i++) {
        Node **pp = head_ref;  

        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            Node *cur = *pp;
            Node *nxt = cur->next;

            if (need_swap(cur, nxt)) {
                cur->next = nxt->next;
                nxt->next = cur;
                *pp = nxt;           

                pp = &nxt->next;      
                swapped = 1;
            } else {
                pp = &cur->next;      
            }
        }

        if (!swapped)                
            break;
    }
}

/* 잘못된(숫자가 아닌) 입력이 들어왔을 때 표준입력 버퍼를 한 줄 비운다 */
void clear_input_line(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* ---------------- main ---------------- */

int main(void)
{
    Node *head = load_data("data.txt");
    int choice;

    if (head == NULL) {
        printf("읽어온 데이터가 없습니다.\n");
        return 1;
    }

    printf("=== 원본 ===\n");
    display_list(head);

    do {
        printf("\n----- 정렬 메뉴 -----\n");
        printf("1. 학번순 정렬 (선배 먼저)\n");
        printf("2. 이름순 정렬 (ㄱ 먼저)\n");
        printf("3. 총점순 정렬 (높은 점수 먼저)\n");
        printf("0. 종료\n");
        printf("선택 : ");

        if (scanf("%d", &choice) != 1) {   
            printf("숫자를 입력하세요.\n");
            clear_input_line();
            choice = -1;                   
            continue;
        }

        switch (choice) {
        case 1:
            bubble_sort(&head, need_swap_by_id);
            printf("\n=== 학번순 (선배 먼저) ===\n");
            display_list(head);
            break;
        case 2:
            bubble_sort(&head, need_swap_by_name);
            printf("\n=== 이름순 (ㄱ 먼저) ===\n");
            display_list(head);
            break;
        case 3:
            bubble_sort(&head, need_swap_by_score);
            printf("\n=== 총점순 (높은 점수 먼저) ===\n");
            display_list(head);
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("1, 2, 3, 0 중에서 선택하세요.\n");
        }
    } while (choice != 0);

    free_list(head);
    return 0;
}
