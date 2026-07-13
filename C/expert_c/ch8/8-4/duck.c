#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animal_p.h"
#include "animal.h"

typedef struct duck_t {
    animal_t animal_t;
} duck_t;

void __duck_sound(void* ptr) {
    struct animal_t* animal_t = (struct animal_t*)ptr;
    printf("%s: Qwack\n", animal_t->name);
}

duck_t* duck_new() {
    return malloc(sizeof(duck_t));
}

void duck_ctor(duck_t* duck) {
    animal_t_ctor((struct animal_t*)duck);
    strcpy(duck->animal_t.name, "duck");
    duck->animal_t.sound_func = __duck_sound;
}

void duck_dtor(duck_t* duck) {
    animal_t_dtor((struct animal_t*)duck);
}