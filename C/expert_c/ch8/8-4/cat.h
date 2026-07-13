#pragma once

struct cat_t;
struct cat_t* cat_new();
void cat_ctor(struct cat_t*);
void cat_dtor(struct cat_t*);