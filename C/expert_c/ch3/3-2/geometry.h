#pragma once
#define PI 3.14159265359

typedef struct {
    double x;
    double y;
} pos;

typedef struct {
    double length;
    double theta;    //도 단위(60도 120도 이런 식..)
} polar;

typedef struct {
    double x;
    double y;
    double z;
} pos_3d;

typedef struct {
    double length;
    double theta; 
    double phi;   //도 단위(60도 120도 이런 식..)
} polar_3d;

double to_radian(double deg);
double to_degree(double rad);

double cos_deg(double deg);
double acos_deg(double deg);

double sin_deg(double deg);
double asin_deg(double deg);

pos convert_to_2d_cartasian_pos(const polar* polar_pos);
polar convert_to_2d_polar_pos(const pos* cartasian_pos);

pos_3d convert_to_3d_cartasian_pos(const polar_3d* polar_pos);
polar_3d convert_to_3d_polar_pos(const pos_3d* cartasian_pos);