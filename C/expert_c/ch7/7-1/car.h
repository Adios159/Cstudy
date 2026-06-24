#pragma once
struct car;

struct car* car_new();
void car_ctor(struct car*);
void car_dtor(struct car*);

void car_start(struct car*);
void car_stop(struct car*);
double car_get_engine_temperature(struct car*);