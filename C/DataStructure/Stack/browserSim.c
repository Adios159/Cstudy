#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_URL 101

typedef char element[MAX_URL];

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) { s->top = -1; }
int is_empty(StackType *s) { return (s->top == -1); }
int is_full(StackType *s) { return (s->top == (MAX_STACK_SIZE - 1)); }

void push(StackType *s, char* item) {
    if(is_full(s)) { fprintf(stderr, "stack is full\n"); return; }
    strcpy(s->data[++(s->top)], item);
}

char* pop(StackType *s) {
    if(is_empty(s)) { fprintf(stderr, "stack is empty\n"); exit(1); }
    return s->data[(s->top)--];
}

char* peek(StackType *s) {
    if(is_empty(s)) { fprintf(stderr, "stack is empty\n"); exit(1); }
    return s->data[s->top];
}


int main() {
    StackType *foward = (StackType*)malloc(sizeof(StackType));
    StackType *back = (StackType*)malloc(sizeof(StackType));
    init_stack(foward);
    init_stack(back);
    char page[MAX_URL] = "", cmd, new_url[MAX_URL];
    printf("browser simulater\n");

    while(1) {
        printf("press command(v, b, f, p, q): ");
        scanf(" %c", &cmd);
        switch(cmd) {
            case 'v':
                printf("choose website you want: ");
                scanf("%s", new_url);
                if(page[0] != '\0') {
                    push(back, page);
                }
                init_stack(foward);
                strcpy(page, new_url);
                printf("you visit %s\n", page);
                break;
            case 'b':
                if(is_empty(back)) {
                    printf("stack is empty\n");
                    break;
                }
                push(foward, page);
                strcpy(page, pop(back));
                printf("back to %s\n", page);
                break;
            case 'f':
                if(is_empty(foward)) {
                    printf("stack is empty\n");
                    break;
                }
                push(back, page);
                strcpy(page, pop(foward));
                printf("foward to %s\n", page);
                break;
            case 'p':
                printf("current page is %s\n", page);
                break;
            case 'q':
                free(foward);
                free(back);
                printf("simulation off\n");
                return 0;
        }
    }
}