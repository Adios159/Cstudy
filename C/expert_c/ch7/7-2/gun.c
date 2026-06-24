#include <stdlib.h>

typedef int bool_t;

typedef struct gun {
    int bullets;
} gun;

gun* gun_new() {
    return (gun*)malloc(sizeof(gun));
}
void gun_ctor(gun* gun, int initial_bullets) {
    gun->bullets = 0;
    if(initial_bullets > 0) {
        gun->bullets = initial_bullets;
    }
}
void gun_dtor(gun* gun) {

}

bool_t gun_has_bullets(gun* gun) {
    return (gun->bullets > 0);
}
void gun_trigger(gun* gun) {
    gun->bullets--;
}
void gun_reload(gun* gun) {
    gun->bullets = 7;
}