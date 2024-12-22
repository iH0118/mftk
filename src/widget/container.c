#include "container.h"

#include "../texture.h"
#include <SDL2/SDL_render.h>

void draw_widget_container(ui0118_window *window, ui0118_widget *widget)
{
    int x_left   = widget->x * UI0118_UNIT;
    int x_right  = (widget->x + widget->data.container.size_x) * UI0118_UNIT + 1;
    int y_top    = widget->y * UI0118_UNIT;
    int y_bottom = (widget->y + widget->data.container.size_y) * UI0118_UNIT + 1;

    SDL_Texture *screw = window->texture_set.container.screw;

    SDL_Rect rect1 = {
        x_left + 1,
        y_top + 2,
        widget->data.container.size_x * UI0118_UNIT - 1,
        widget->data.container.size_y * UI0118_UNIT - 2
    };

    SDL_Rect rect2 = {
        x_left + 2,
        y_top + 1,
        widget->data.container.size_x * UI0118_UNIT - 2,
        widget->data.container.size_y * UI0118_UNIT - 1
    };

    SDL_SetRenderDrawColor(
        window->renderer,
        widget->data.container.color.r,
        widget->data.container.color.g,
        widget->data.container.color.b,
        widget->data.container.color.a
    );

    SDL_RenderFillRect(window->renderer, &rect1);
    SDL_RenderFillRect(window->renderer, &rect2);

    SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);

    SDL_Point points[] = {
        {x_left  + 5, y_top       },
        {x_right - 5, y_top       },
        {x_right - 2, y_top    + 1},
        {x_right - 1, y_top    + 2},
        {x_right,     y_top    + 5},
        {x_right,     y_bottom - 5},
        {x_right - 1, y_bottom - 2},
        {x_right - 2, y_bottom - 1},
        {x_right - 5, y_bottom    },
        {x_left  + 5, y_bottom    },
        {x_left  + 2, y_bottom - 1},
        {x_left  + 1, y_bottom - 2},
        {x_left,      y_bottom - 5},
        {x_left,      y_top    + 5},
        {x_left + 1,  y_top    + 2},
        {x_left + 2,  y_top    + 1},
        {x_left + 5,  y_top       }
    };

    SDL_RenderDrawLines(
        window->renderer,
        points,
        sizeof(points) / sizeof(SDL_Point)
    );

    blit(window->renderer, screw, x_left + 3, y_top + 3);
    blit(window->renderer, screw, x_right - 9, y_top + 3);
    blit(window->renderer, screw, x_right - 9, y_bottom - 9);
    blit(window->renderer, screw, x_left + 3, y_bottom - 9);
}
