#pragma once

struct animal_t;
struct animal_t* animal_t_new();
void animal_t_ctor(struct animal_t*);
void animal_t_dtor(struct animal_t*);
void animal_t_get_name(struct animal_t*, char*);
void animal_t_sound(struct animal_t*); 