#include "object.h"

void object_init(struct object *object, double x, double y, double w, double h)
{
    object->x = x;
    object->y = y;
    object->w = w;
    object->h = h;
    object->mod.cap = 10;
    object->mod.size = 0;
    object->mod.modules = malloc(sizeof(struct module *) * 10);
}

void object_free(struct object *object)
{
    int i;
    for (i = 0; i < object->mod.size; i++)
    {
        object->mod.modules[i].free(&object->mod.modules[i]);
    }

    free(object->mod.modules);
}

struct module *object_add_module(struct object *object)
{
    if (object->mod.size == object->mod.cap)
    {
        object->mod.cap += 10;
        object->mod.modules = realloc(object->mod.modules, sizeof(struct module *) * object->mod.cap);
    }

    int mod = object->mod.size++;
    memset(&object->mod.modules[mod], 0, sizeof(struct module));

    return &object->mod.modules[mod];
}

void object_update_modules(struct object *object, float timescale)
{
    int i;
    for (i = 0; i < object->mod.size; i++)
    {
        if (object->mod.modules[i].update)
        {
            object->mod.modules[i].update(&object->mod.modules[i], object, timescale);
        }
    }
}

void object_render_modules(struct object *object, struct render *render)
{
    int i;
    for (i = 0; i < object->mod.size; i++)
    {
        if (object->mod.modules[i].render)
        {
            object->mod.modules[i].render(&object->mod.modules[i], object, render);
        }
    }
}
