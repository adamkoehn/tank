#include "vector.h"

double vector_magnitude(const struct vector *vector)
{
    return sqrt(pow(vector->x, 2.0) + pow(vector->y, 2.0));
}

void vector_multiply(struct vector *vector, double scale)
{
    double mag = vector_magnitude(vector);

    if (mag == 0.0)
    {
        vector->x = 0.0;
        vector->y = 0.0;
    }
    else
    {
        vector->x = (vector->x / mag) * (mag * scale);
        vector->y = (vector->y / mag) * (mag * scale);
    }
}