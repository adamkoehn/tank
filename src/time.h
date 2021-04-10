#ifndef INCLUDE_TIME_H
#define INCLUDE_TIME_H

#include <SDL2/SDL.h>

struct time
{
    Uint32 previous;
    Uint32 current;
    float scale;
};

void time_init(struct time *);

void time_tick(struct time *);

#endif