#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
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
    StackType s;
    init_stack(&s);
    char hello[20] = "Hello World";
    
    for(int i = 0; hello[i] != '\0'; i++) {
        push(&s, hello[i]);
    }
    for(int i = 0; hello[i] != '\0'; i++) {
        printf("%c", pop(&s));
    }

    return 0;
}