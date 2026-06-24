#pragma once

struct player;
struct gun;

struct player* player_new();
void player_ctor(struct player*, const char*);
void player_dtor(struct player*);

void player_pickup_gun(struct player*, struct gun*);
void player_shoot(struct player*);
void player_drop_gun(struct player*);