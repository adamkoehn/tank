#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

#include <math.h>

struct vector {
    double x;
    double y;
};

double vector_magnitude(const struct vector *vector);

void vector_multiply(struct vector *vector, double scale);

#endif