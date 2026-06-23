#include <stdio.h>
#include "car.h"

int main(void) {
    car car;
    car_construct(&car, "Renault");

    car_refuel(&car, 100.0);
    printf("car is refueled, current fuel level is %f\n", car.fuel);
    while(car.fuel > 0.0) {
        printf("current fuel level: %f\n", car.fuel);
        if(car.speed < 80.0) {
            car_accelarate(&car);
            printf("car has been accelarated. current speed: %f\n", car.speed);
        }
        else {
            car_brake(&car);
            printf("car has been slow down. current speed: %f\n", car.speed);
        }
    }

    printf("car ran out of the fuel! Slowing down...\n");
    while(car.speed > 0) {
        car_brake(&car);
        printf("car has been slow down. current speed: %f\n", car.speed);
    }

    car_destruct(&car);
    return 0;
}