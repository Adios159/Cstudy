#include <stdlib.h>

typedef enum {
    ON,
    OFF
} state;

typedef struct {
    state state;
    double temperature;
} engine;

engine* engine_new() {
    return (engine*)malloc(sizeof(engine));
}
void engine_ctor(engine* engine) {
    engine->state = OFF;
    engine->temperature = 15;
}
void engine_dtor(engine* engine) {

}

void engine_turn_on(engine* engine) {
    if(engine->state == ON) {
        return;
    }
    engine->state = ON;
    engine->temperature = 75;
}
void engine_turn_off(engine* engine) {
    if(engine->state == OFF) {
        return;
    }
    engine->state = OFF;
    engine->temperature = 15;
}
double get_engine_temperature(engine* engine) {
    return engine->temperature;
}