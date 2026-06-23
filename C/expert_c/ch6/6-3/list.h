#pragma once
#include <unistd.h>

struct list;

struct list* list_malloc();

void list_init(struct list*);
void list_destroy(struct list*);

int list_add(struct list*, int);
int list_get(struct list*, int, int*);
void list_clear(struct list*);
size_t list_size(struct list*);
void list_print(struct list*);