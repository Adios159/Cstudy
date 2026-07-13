#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animal_p.h"
#include "animal.h"

typedef struct cat_t {
    animal_t animal_t;
} cat_t;

void __cat_sound(void* ptr) {
    struct animal_t* animal_t = (struct animal_t*)ptr;
    printf("%s: Meow\n", animal_t->name);
}

cat_t* cat_new() {
    return malloc(sizeof(cat_t));
}

void cat_ctor(cat_t* cat) {
    animal_t_ctor((struct animal_t*)cat);
    strcpy(cat->animal_t.name, "cat");
    cat->animal_t.sound_func = __cat_sound;
}

void cat_dtor(cat_t* cat) {
    animal_t_dtor((struct animal_t*)cat);
}