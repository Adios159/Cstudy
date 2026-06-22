#include <math.h>
#include "geometry.h"

pos_3d convert_to_3d_cartasian_pos(const polar_3d* polar_pos) {
    pos_3d result;
    result.x = polar_pos->length * sin_deg(polar_pos->theta) * cos_deg(polar_pos->phi);
    result.y = polar_pos->length * sin_deg(polar_pos->theta) * sin_deg(polar_pos->phi);
    result.x = polar_pos->length * cos_deg(polar_pos->theta);
    return result;
}

polar_3d convert_to_3d_polar_pos(const pos_3d* cartasian_pos) {
    polar_3d result;
    result.length = sqrt(pow(cartasian_pos->x, 2) + pow(cartasian_pos->y, 2) + pow(cartasian_pos->z, 2));
    result.theta = to_degree(acos(cartasian_pos->z / result.length));
    result.phi = to_degree(atan(cartasian_pos->y / cartasian_pos->x));
    return result;
}