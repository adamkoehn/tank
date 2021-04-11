#include "module_sprite.h"

static void module_sprite_render(struct module *module, struct object *object, struct render *render)
{
    struct sprite *sprite = (struct sprite *)module->data;

    SDL_Rect dest = (SDL_Rect){
        .x = object->x,
        .y = object->y,
        .w = object->w * sprite->scale.x,
        .h = object->h * sprite->scale.y,
    };

    render_draw_texture(render, sprite->texture, &dest);
}

static void module_sprite_free(struct module *module)
{
    free(module->data);
}

void module_sprite_attach(struct object *object, int texture, float scaleX, float scaleY)
{
    struct module *module = object_add_module(object);
    struct sprite *sprite = malloc(sizeof(struct sprite));

    sprite->texture = texture;
    sprite->scale.x = scaleX;
    sprite->scale.y = scaleY;

    module->render = module_sprite_render;
    module->free = module_sprite_free;
    module->data = (void *)sprite;
}
