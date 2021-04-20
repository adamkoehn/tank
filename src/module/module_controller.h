#ifndef INCLUDE_MODULE_CONTROLLER_H
#define INCLUDE_MODULE_CONTROLLER_H

#include <stdlib.h>

#include "../object.h"
#include "../input.h"
#include "../vector.h"

struct modcontroller {
    struct controller *controller;
    double speed;
};

void module_controller_attach(struct object *object, struct controller *controller, double speed);


#endif