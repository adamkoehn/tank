#ifndef INCLUDE_INPUT_H
#define INCLUDE_INPUT_H

#include <SDL2/SDL.h>

enum inputstate
{
    INPUT_STATE_UP,
    INPUT_STATE_DOWN,
};

struct inputsystem
{
    int quit;
};

struct inputmap
{
    int up;
    int down;
    int left;
    int right;
    int fire;
};

struct controller
{
    struct inputmap map;
    struct
    {
        enum inputstate up;
        enum inputstate down;
        enum inputstate left;
        enum inputstate right;
        enum inputstate fire;
    } state;
    float x;
    float y;
    int fire;
};

void input_system_init(struct inputsystem *);

void input_controller_init(struct controller *);

void input_read_events(struct inputsystem *, struct controller **);

void input_controller_update_pressed(struct controller *, SDL_Event *);

void input_controller_update_released(struct controller *, SDL_Event *);

#endif