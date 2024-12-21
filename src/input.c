#include "input.h"

#include "widget/toggle.h"

void ui0118_do_input(ui0118_window *window)
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    SDL_Event event;
    ui0118_widget *node;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) exit(0);

        for (node = window->widget_top; node; node = node->next)
        {
            if (node->type == UI0118_TOGGLE)
            {
                do_input_toggle(window, node, mouse_x, mouse_y, &event);
            }
        }
    }
}
