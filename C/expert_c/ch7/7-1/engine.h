#pragma once

struct engine;

struct engine* engine_new();
void engine_ctor(struct engine*);
void engine_dtor(struct engine*);

void engine_turn_on(struct engine*);
void engine_turn_off(struct engine*);
double get_engine_temperature(struct engine*);