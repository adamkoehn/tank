#include "module_controller.h"

static void module_controller_update(struct module *self, struct object *selfobj, float timescale)
{
    struct modcontroller *mod = (struct modcontroller *)self->data;
    selfobj->x += (mod->controller->x * mod->speed) * timescale;
    selfobj->y += (mod->controller->y * mod->speed) * timescale;
}

static void module_controller_render(struct module *self, struct object *selfobj, struct render *render)
{
    //
}

static void module_controller_free(struct module *self)
{
    free(self->data);
}

void module_controller_attach(struct object *object, struct controller *controller)
{
    struct module *module = object_add_module(object);
    struct modcontroller *mod = malloc(sizeof(struct modcontroller));

    mod->controller = controller;
    mod->speed = 3.0;

    module->update = module_controller_update;
    module->free = module_controller_free;
    module->render = module_controller_render;
    module->data = (void *)mod;
}