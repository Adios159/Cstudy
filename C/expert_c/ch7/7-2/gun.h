#pragma once

typedef int bool_t;

struct gun;

struct gun* gun_new();
void gun_ctor(struct gun*, int);
void gun_dtor(struct gun*);

bool_t gun_has_bullets(struct gun*);
void gun_trigger(struct gun*);
void gun_reload(struct gun*);
