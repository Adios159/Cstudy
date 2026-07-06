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

int main(void) {
    StackType* stack1 = (StackType*)malloc(sizeof(StackType));
    StackType* stack2 = (StackType*)malloc(sizeof(StackType));

    init_stack(stack1);
    init_stack(stack2);
    for(int i = 1; i <= 5; i++) {
        printf("push %d\n", i);
        push(stack1, i);
    }
    printf("\n");

    for(int i = 0; i < 5; i++) {
        int tmp = 0;
        tmp = pop(stack1);
        printf("push %d\n", tmp);
        push(stack2, tmp);
    }

    free(stack1);
    free(stack2);
    return 0;
}