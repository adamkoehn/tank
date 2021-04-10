#include <SDL2/SDL.h>

#include "input.h"
#include "tank.h"
#include "time.h"
#include "render.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    int run = 1;
    struct render render;
    struct time time;
    struct inputsystem system;
    struct controller controller;
    struct tank tank;

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

    render_init(&render, renderer);
    input_system_init(&system);
    input_controller_init(&controller);
    tank_init(
        &tank,
        &controller,
        SCREEN_WIDTH / 2,
        SCREEN_HEIGHT / 2,
        render_load_texture(&render, "assets/tank.png"));

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
        tank_update(&tank, time.scale);

        // Render
        render_clear(&render);
        SDL_Rect loc = (SDL_Rect){
            .x = tank.x + 16,
            .y = tank.y + 16,
            .w = 32,
            .h = 32,
        };
        render_draw_texture(&render, tank.texture, &loc);
        render_present(&render);
    }

    render_free(&render);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}