#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int id;
    int rank;
} Student;

void print_students(Student* arr, int n, const char* title) {
    printf("< %s >\n", title);
    printf("---------------------\n");
    printf("| 이름 | 학 번 |등수|\n");
    printf("---------------------\n");
    for (int i = 0; i < n; i++) {
        printf("|%s| %d| %d |\n", arr[i].name, arr[i].id, arr[i].rank);
    }
    printf("---------------------\n\n");
}

void selection_sort_rank(Student* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].rank < arr[min_idx].rank) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Student temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void insertion_sort_id(Student* arr, int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].id > key.id) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort_name(Student* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE* fp = fopen("data1.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int count = 0;
    char temp_name[20];
    int temp_id, temp_rank;
    while (fscanf(fp, "%s %d %d", temp_name, &temp_id, &temp_rank) == 3) {
        count++;
    }

    Student* origin = (Student*)malloc(sizeof(Student) * count);
    Student* list = (Student*)malloc(sizeof(Student) * count);

    rewind(fp);
    for (int i = 0; i < count; i++) {
        fscanf(fp, "%s %d %d", origin[i].name, &origin[i].id, &origin[i].rank);
    }
    fclose(fp);

    memcpy(list, origin, sizeof(Student) * count);
    print_students(list, count, "정렬전 데이터");

    memcpy(list, origin, sizeof(Student) * count);
    insertion_sort_id(list, count);
    print_students(list, count, "학번 정렬후 데이터");

    memcpy(list, origin, sizeof(Student) * count);
    bubble_sort_name(list, count);
    print_students(list, count, "이름 정렬후 데이터");

    memcpy(list, origin, sizeof(Student) * count);
    selection_sort_rank(list, count);
    print_students(list, count, "등수 정렬후 데이터");

    free(origin);
    free(list);

    return 0;
}