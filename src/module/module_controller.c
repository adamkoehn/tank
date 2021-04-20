#include "module_controller.h"

static void module_controller_update(struct module *self, struct object *selfobj, double timescale)
{
    struct modcontroller *mod = (struct modcontroller *)self->data;
    struct vector vector = {.x = mod->controller->x, .y = mod->controller->y};
    vector_multiply(&vector, mod->speed * timescale);

    selfobj->x += vector.x;
    selfobj->y += vector.y;
}

static void module_controller_free(struct module *self)
{
    free(self->data);
}

void module_controller_attach(struct object *object, struct controller *controller, double speed)
{
    struct module *module = object_add_module(object);
    struct modcontroller *mod = malloc(sizeof(struct modcontroller));

    mod->controller = controller;
    mod->speed = 3.0;

    module->update = module_controller_update;
    module->free = module_controller_free;
    module->data = (void *)mod;
}
