#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H

#include <stdlib.h>
#include <string.h>

#include "render.h"

struct module;

struct object
{
    double x;
    double y;
    double h;
    double w;
    struct
    {
        int size;
        int cap;
        struct module *modules;
    } mod;
};

struct module
{
    void (*update)(struct module *self, struct object *selfobj, double timescale);
    void (*render)(struct module *self, struct object *selfobj, struct render *render);
    void (*free)(struct module *self);
    void *data;
};

void object_init(struct object *object, double x, double y, double w, double h);

void object_free(struct object *);

struct module *object_add_module(struct object *);

void object_update_modules(struct object *, float);

void object_render_modules(struct object *, struct render *);

#endif