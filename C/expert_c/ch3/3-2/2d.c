#include <math.h>
#include "geometry.h"

pos convert_to_2d_cartasian_pos(const polar* polar_pos) {
    pos result;
    result.x = polar_pos->length * cos_deg(polar_pos->theta);
    result.y = polar_pos->length * sin_deg(polar_pos->theta);
    return result;
}

polar convert_to_2d_polar_pos(const pos* cartasian_pos) {
    polar result;
    result.length = sqrt(pow(cartasian_pos->x, 2) + pow(cartasian_pos->y, 2));
    result.theta = to_degree(atan(cartasian_pos->y / cartasian_pos->x));
    return result;
}