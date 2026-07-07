#include "stack.h"

void init_stack(StackType *s) {
    s->top = -1;
}

int stack_is_empty(StackType *s) {
    return (s->top == -1);
}

int stack_is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
    if(stack_is_full(s)) {
        fprintf(stderr, "stack is full");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if(stack_is_empty(s)) {
        fprintf(stderr, "stack is empty");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s) {
    if(stack_is_empty(s)) {
        fprintf(stderr, "stack is empty");
        exit(1);
    }
    else return s->data[s->top];
}