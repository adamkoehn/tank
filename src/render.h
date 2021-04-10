#ifndef INCLUDE_RENDER_H
#define INCLUDE_RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct render
{
    SDL_Renderer *renderer;
    int next;
    int size;
    int cap;
    SDL_Texture **textures;
};

void render_init(struct render *, SDL_Renderer *);

void render_free(struct render *);

void render_clear(struct render *);

void render_present(struct render *);

int render_load_texture(struct render *, const char *);

void render_draw_texture(struct render *, int, SDL_Rect *);

#endif