#include <SDL2/SDL.h>

#include "input.h"
#include "time.h"
#include "render.h"
#include "object.h"

#include "module/module_sprite.h"
#include "module/module_controller.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    int run = 1;
    struct render render;
    struct time time;
    struct inputsystem system;
    struct controller controller;
    struct object tank;

    struct controller *controllers[2];

    controllers[0] = &controller;
    controllers[1] = NULL;

    SDL_Window *window = SDL_CreateWindow(
        "keymap",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);

    render_init(&render, renderer);
    input_system_init(&system);
    input_controller_init(&controller);
    object_init(
        &tank,
        SCREEN_WIDTH / 2,
        SCREEN_HEIGHT / 2,
        32,
        32);
    module_sprite_attach(
        &tank,
        render_load_texture(&render, "assets/tank.png"),
        1.0,
        1.0);
    module_controller_attach(&tank, &controller);

    time_init(&time);
    while (run)
    {
        // Events
        input_read_events(&system, controllers);
        if (system.quit)
        {
            run = 0;
        }

        // Update
        time_tick(&time);
        object_update_modules(&tank, time.scale);

        // Render
        render_clear(&render);
        object_render_modules(&tank, &render);
        render_present(&render);
    }

    object_free(&tank);
    render_free(&render);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}