#pragma once

typedef void (*sound_func_t)(void*);

typedef struct animal_t {
    char*name;
    sound_func_t sound_func;
} animal_t;