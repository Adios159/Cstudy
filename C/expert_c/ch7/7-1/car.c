#include <stdlib.h>
#include "engine.h"

typedef struct car
{
    struct engine* engine;
} car;

car* car_new() {
    return (car*)malloc(sizeof(car));
}
void car_ctor(car* car) {
    car->engine = engine_new();
    engine_ctor(car->engine);
}
void car_dtor(car* car) {
    free(car->engine);
}

void car_start(car* car) {
    engine_turn_on(car->engine);
}
void car_stop(car* car) {
    engine_turn_off(car->engine);
}
double car_get_engine_temperature(car* car) {
    return get_engine_temperature(car->engine);
}
