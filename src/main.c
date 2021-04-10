#include <SDL2/SDL.h>

#include "input.h"
#include "tank.h"
#include "time.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    int run = 1;
    struct time time;
    struct inputsystem system;
    struct controller controller;
    struct tank tank;

    struct controller *controllers[2];

    controllers[0] = &controller;
    controllers[1] = NULL;

    input_system_init(&system);
    input_controller_init(&controller);
    tank_init(&tank, &controller, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

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

    time_init(&time);
    while (run)
    {
        input_read_events(&system, controllers);

        if (system.quit)
        {
            run = 0;
        }

        time_tick(&time);
        tank_update(&tank, time.scale);

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);

        SDL_Rect loc = (SDL_Rect){
            .x = tank.x + 16,
            .y = tank.y + 16,
            .w = 32,
            .h = 32,
        };
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xDD, 0x00);
        SDL_RenderDrawRect(renderer, &loc);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}