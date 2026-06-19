#ifndef H2_1_H
#define H2_1_H

typedef enum {
    NONE,
    NORMAL,
    SQUARED
} average_type_t;

double avg(int*, int, average_type_t);

#endif