#include "container.h"

#include "../texture.h"

void draw_widget_container(mftk_window *window, mftk_widget *widget)
{
    SDL_Texture *screw = window->texture_set.container.screw;

    int size_x_u = widget->data.container.size_x * MFTK_UNIT;
    int size_y_u = widget->data.container.size_y * MFTK_UNIT;
    int x_left   = widget->x * MFTK_UNIT;
    int x_right  = x_left + size_x_u + 1;
    int y_top    = widget->y * MFTK_UNIT;
    int y_bottom = y_top + size_y_u + 1;

    SDL_Rect rect1 = {x_left + 1, y_top + 2, size_x_u - 1, size_y_u - 2};
    SDL_Rect rect2 = {x_left + 2, y_top + 1, size_x_u - 2, size_y_u - 1};

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
        {x_left  + 1, y_top    + 2},
        {x_left  + 2, y_top    + 1},
        {x_left  + 5, y_top       }
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
