#ifndef INCLUDE_TANK_H
#define INCLUDE_TANK_H

#include "input.h"

struct tank
{
    int texture;
    struct controller *controller;
    float speed;
    float x;
    float y;
};

void tank_init(struct tank *, struct controller *, float, float, int);

void tank_update(struct tank *, float);

#endif