#include "ui0118.h"
#include <SDL2/SDL.h>

ui0118_window *ui0118_create_window(
    const char *title, unsigned int size_x, unsigned int size_y
)
{
    ui0118_window *window = malloc(sizeof(ui0118_window));

    unsigned int renderer_flags = 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    window->window = SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        (int) size_x * UI0118_UNIT + 1,
        (int) size_y * UI0118_UNIT + 1,
        0
    );

    window->renderer = SDL_CreateRenderer(window->window, -1, renderer_flags);

    window->widget_top = NULL;
    window->widget_bottom = NULL;

    return window;
}


