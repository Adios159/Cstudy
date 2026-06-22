#include <stdio.h>
#include "geometry.h"

int main(int argc, char** argv) {
    pos cartasian_pos;
    cartasian_pos.x = 100;
    cartasian_pos.y = 200;
    polar polar_pos = convert_to_2d_polar_pos(&cartasian_pos);
    printf("Polar PositionL Length: %f, theta: %f (deg)\n", polar_pos.length, polar_pos.theta);

    return 0;
}