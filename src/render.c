#include "render.h"

void render_init(struct render *render, SDL_Renderer *renderer)
{
    render->renderer = renderer;
    render->next = 0;
    render->size = 0;
    render->cap = 10;
    render->textures = malloc(sizeof(SDL_Texture *) * 10);
}

void render_free(struct render *render)
{
    int i;
    for (i = 0; i < render->size; i++)
    {
        SDL_DestroyTexture(render->textures[i]);
    }

    free(render->textures);
}

void render_clear(struct render *render)
{
    SDL_RenderClear(render->renderer);
}

void render_present(struct render *render)
{
    SDL_RenderPresent(render->renderer);
}

int render_load_texture(struct render *render, const char *path)
{
    int texture;

    SDL_Surface *surface = IMG_Load(path);
    if (!surface)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "could not load image %s", path);
    }

    texture = render->next++;
    render->size++;
    render->textures[texture] = SDL_CreateTextureFromSurface(render->renderer, surface);
    SDL_FreeSurface(surface);

    if (render->size == render->cap)
    {
        render->cap += 10;
        render->textures = realloc(render->textures, sizeof(SDL_Texture *) * render->cap);
    }

    return texture;
}

void render_draw_texture(struct render *render, int texture, SDL_Rect *dest)
{
    SDL_RenderCopy(render->renderer, render->textures[texture], NULL, dest);
}
