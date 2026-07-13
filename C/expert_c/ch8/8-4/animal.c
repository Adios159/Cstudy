#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animal_p.h"

void __animal_t_sound(void* this_ptr) {
    struct animal_t* animal_t = (struct animal_t*)this_ptr;
    printf("%s: Beeeeeep\n", animal_t->name);
}

animal_t* animal_t_new() {
    return (animal_t*)malloc(sizeof(animal_t));
}

void animal_t_ctor(animal_t* animal_t) {
    animal_t->name = (char*)malloc(10 * sizeof(char));
    strcpy(animal_t->name, "animal_t");
    animal_t->sound_func = __animal_t_sound;
}

void animal_t_dtor(animal_t* animal_t) {
    free(animal_t->name);
}

void animal_t_get_name(animal_t* animal_t, char* buffer) {
    strcpy(buffer, animal_t->name);
}

void animal_t_sound(animal_t* animal_t) {
    animal_t->sound_func(animal_t);
}