#include "input.h"

#include "widget/toggle.h"

void mftk_do_input(
    mftk_window *window
)
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    SDL_Event event;
    mftk_widget *node;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) exit(0);

        for (node = window->widget_top; node; node = node->next)
        {
            switch (node->type)
            {
                case MFTK_TOGGLE:
                do_input_toggle(window, node, mouse_x, mouse_y, &event);
                break;

                case MFTK_TOGGLE_MOM:
                //TODO
                break;

                case MFTK_ROTARY:
                //TODO
                break;

                default:
                break;
            }
        }
    }
}
