#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gun.h"

typedef struct {
    char* name;
    struct gun* gun;
} player;

player* player_new() {
    return (player*)malloc(sizeof(player));
}
void player_ctor(player* player, const char* name) {
    player->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(player->name, name);
    player->gun = NULL;
}
void player_dtor(player* player) {
    free(player->name);
}

void player_pickup_gun(player* player, struct gun* gun) {
    player->gun = gun;
}
void player_shoot(player* player) {
    if(player->gun) {
        gun_trigger(player->gun);
    }
    else {
        printf("Player doesn't have gun!");
        exit(1);
    }
}
void player_drop_gun(player* player) {
    player->gun = NULL;
}