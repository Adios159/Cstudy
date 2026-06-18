#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "stack is full");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "stack is empty");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "stack is empty");
        exit(1);
    }
    else return s->data[s->top];
}

int main() {
    StackType q;          // 포인터 → 구조체 변수
    init_stack(&q);
    int arr[5];
    int tmp;
    printf("input number: ");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    printf("arr list: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    

    for(int i = 4; i >= 0; --i) {
        push(&q, arr[i]);
    }
    printf("\n");

    printf("stack list: ");
    for(int i = 0; i < 5; i++) {
        arr[i] = i + 1;
        printf("%d ", q.data[i]);
    }

    

    return 0;
}