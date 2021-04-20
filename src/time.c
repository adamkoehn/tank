#include "time.h"

void time_init(struct time *time)
{
    Uint32 now = SDL_GetTicks();

    time->previous = now;
    time->current = now;
    time->scale = 0.0;
}

void time_tick(struct time *time)
{
    time->previous = time->current;
    time->current = SDL_GetTicks();
    time->scale = ((double)time->current - (double)time->previous) / 16.0;
}
