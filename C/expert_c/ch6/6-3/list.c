#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define MAX_SIZE 10

typedef int bool_t;
typedef struct list {
    size_t size;
    int* items;
} list;


bool_t __list_is_full(list* list) {
    return(list->size == MAX_SIZE);
}

bool_t __check_index(list* list, const int index) {
    return(index >= 0 && index <= list->size);
}

struct list* list_malloc() {
    return (list*)malloc(sizeof(list));
}

void list_init(struct list* list) {
    list->size = 0;
    list->items = (int*)malloc(MAX_SIZE * sizeof(int));
}
void list_destroy(struct list* list) {
    free(list->items);
}

int list_add(struct list* list, const int item) {
    if(__list_is_full(list))
        return -1;
    list->items[list->size++] = item;
}
int list_get(struct list* list, const int index, int* result) {
    if(__check_index(list, index)) {
        *result = list->items[index];
        return 0;
    }
    return -1;
}
void list_clear(struct list* list) {
    list->size = 0;
}
size_t list_size(struct list* list) {
    return list->size;
}
void list_print(struct list* list) {
    printf("[");
    for(size_t i = 0; i < list->size; i++) {
        printf("%d ", list->items[i]);
    }
    printf("] ");
}