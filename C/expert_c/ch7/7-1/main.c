#include <stdio.h>
#include <stdlib.h>
#include "car.h"

int main(void) {
    struct car* car = car_new();

    car_ctor(car);

    printf("engine temperature before start: %f\n", car_get_engine_temperature(car));
    car_start(car);
    printf("engine temperature after start: %f\n", car_get_engine_temperature(car));
    car_stop(car);
    printf("engine temperature after stop: %f\n", car_get_engine_temperature(car));

    car_dtor(car);
    free(car);
    return 0;
}