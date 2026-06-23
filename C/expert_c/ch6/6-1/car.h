#pragma once

typedef struct{
    char name[32];
    double speed;
    double fuel;
} car;

void car_construct(car*, const char*);
void car_destruct(car*);
void car_accelarate(car*);
void car_brake(car*);
void car_refuel(car*, double);