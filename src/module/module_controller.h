#ifndef INCLUDE_MODULE_CONTROLLER_H
#define INCLUDE_MODULE_CONTROLLER_H

#include <stdlib.h>

#include "../object.h"
#include "../input.h"

struct modcontroller {
    struct controller *controller;
    float speed;
};

void module_controller_attach(struct object *object, struct controller *controller, float speed);


#endif