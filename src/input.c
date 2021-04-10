#include "input.h"

void input_system_init(struct inputsystem *system)
{
    system->quit = 0;
}

void input_controller_init(struct controller *controller)
{
    controller->map.up = SDLK_UP;
    controller->map.down = SDLK_DOWN;
    controller->map.left = SDLK_LEFT;
    controller->map.right = SDLK_RIGHT;
    controller->map.fire = SDLK_SPACE;

    controller->state.up = INPUT_STATE_UP;
    controller->state.down = INPUT_STATE_UP;
    controller->state.left = INPUT_STATE_UP;
    controller->state.right = INPUT_STATE_UP;
    controller->state.fire = INPUT_STATE_UP;

    controller->fire = 0;
    controller->x = 0;
    controller->y = 0;
}

void input_read_events(struct inputsystem *system, struct controller **controllers)
{
    int i;
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
        {
            system->quit = 1;
        }

        if (event.type == SDL_KEYDOWN)
        {
            for (i = 0; controllers[i] != NULL; i++)
            {
                input_controller_update_pressed(controllers[i], &event);
            }
        }
        else if (event.type == SDL_KEYUP)
        {
            for (i = 0; controllers[i] != NULL; i++)
            {
                input_controller_update_released(controllers[i], &event);
            }
        }
    }
}

void input_controller_update_pressed(struct controller *controller, SDL_Event *event)
{
    SDL_Keycode code = event->key.keysym.sym;

    if (code == controller->map.up)
    {
        if (controller->y != -1)
        {
            controller->y = -1;
        }
    }
    else if (code == controller->map.down)
    {
        if (controller->y != 1)
        {
            controller->y = 1;
        }
    }
    else if (code == controller->map.left)
    {
        if (controller->x != -1)
        {
            controller->x = -1;
        }
    }
    else if (code == controller->map.right)
    {
        if (controller->x != 1)
        {
            controller->x = 1;
        }
    }
    else if (code == controller->map.fire)
    {
        controller->fire = 1;
    }
}

void input_controller_update_released(struct controller *controller, SDL_Event *event)
{
    SDL_Keycode code = event->key.keysym.sym;

    if (code == controller->map.up)
    {
        if (controller->y == -1)
        {
            controller->y = 0;
        }
    }
    else if (code == controller->map.down)
    {
        if (controller->y == 1)
        {
            controller->y = 0;
        }
    }
    else if (code == controller->map.left)
    {
        if (controller->x == -1)
        {
            controller->x = 0;
        }
    }
    else if (code == controller->map.right)
    {
        if (controller->x == 1)
        {
            controller->x = 0;
        }
    }
    else if (code == controller->map.fire)
    {
        controller->fire = 0;
    }
}
