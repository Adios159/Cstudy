#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_NAME 50

typedef struct student {
    char name[MAX_NAME];
    long long student_code;
    int score;
} student;

// 구조체 포인터 배열을 받아 점수(score) 기준으로 오름차순 정렬
void insert_sort(student* list[], int n) {
    int i, j;
    student* key;

    for (i = 1; i < n; i++) {
        key = list[i]; // 현재 삽입할 학생 포인터 보관

        // 점수를 비교하여 큰 값을 뒤로 한 칸씩 밀어냄
        for (j = i - 1; j >= 0 && list[j]->score > key->score; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = key;
    }
}

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        exit(1);
    }

    student* list[MAX_SIZE];
    int n = 0;

    // 최대 크기를 넘지 않고, 3개의 항목을 정상적으로 읽었을 때만 반복
    while (n < MAX_SIZE) {
        student* temp = (student*)malloc(sizeof(student)); // 학생 1명분의 메모리 할당
        if (fscanf(fp, "%s %lld %d", temp->name, &temp->student_code, &temp->score) != 3) {
            free(temp); // 더 이상 읽을 데이터가 없으면 할당한 메모리 해제 후 종료
            break;
        }
        list[n] = temp;
        n++;
    }
    fclose(fp); // 파일 닫기

    printf("before:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %lld %d\n", list[i]->name, list[i]->student_code, list[i]->score);
    }
    printf("\n");

    insert_sort(list, n);

    printf("\nafter:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %lld %d\n", list[i]->name, list[i]->student_code, list[i]->score);
    }

    for (int i = 0; i < n; i++) {
        free(list[i]);
    }

    return 0;
}