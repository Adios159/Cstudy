#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s); 
int stack_is_empty(StackType *s); 
int stack_is_full(StackType *s); 
void push(StackType *s, element item);
element pop(StackType *s); 
element peek(StackType *s);