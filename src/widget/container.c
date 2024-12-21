#include "container.h"

void draw_widget_container(ui0118_window *window, ui0118_widget *widget)
{
    //IMPLEMENTATION TEST, FIX LATER
    SDL_SetRenderDrawColor(
        window->renderer,
        widget->data.container.color.r,
        widget->data.container.color.g,
        widget->data.container.color.b,
        widget->data.container.color.a
    );

    SDL_Rect rect = {
        widget->x * UI0118_UNIT,
        widget->y * UI0118_UNIT,
        (widget->x + widget->data.container.size_x - 1) * UI0118_UNIT + 1,
        (widget->y + widget->data.container.size_y - 1) * UI0118_UNIT + 1
    };

    SDL_RenderFillRect(window->renderer, &rect);
    SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(window->renderer, &rect);
}
