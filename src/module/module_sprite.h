#ifndef INCLUDE_MODULE_SPRITE_H
#define INCLUDE_MODULE_SPRITE_H

#include <stdlib.h>

#include "../render.h"
#include "../object.h"

struct sprite {
    int texture;
    struct {
        float x;
        float y;
    } scale;
};

void module_sprite_attach(struct object *, int, float, float);

#endif