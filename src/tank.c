#include "tank.h"

void tank_init(struct tank *tank, struct controller *controller, float x, float y, int texture)
{
    tank->texture = texture;
    tank->controller = controller;
    tank->speed = 3.0;
    tank->x = x;
    tank->y = y;
}

void tank_update(struct tank *tank, float timescale)
{
    tank->x += (tank->controller->x * tank->speed) * timescale;
    tank->y += (tank->controller->y * tank->speed) * timescale;
}