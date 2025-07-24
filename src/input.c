#include "input.h"

#include "widget/rotary.h"
#include "widget/toggle.h"

void mftk_do_input(
    mftk_window *window
)
{
    float mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    SDL_Event event;
    
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT) 
        {
            exit(0);
        }

        for (mftk_widget *node = window->widget_top; node; node = node->next)
        {
            switch (node->type)
            {
                case MFTK_TOGGLE:
                mftk_do_input_toggle(window, node, mouse_x, mouse_y, &event);
                break;

                case MFTK_TOGGLE_MOM:
                //TODO
                break;

                case MFTK_ROTARY:
                mftk_do_input_rotary(window, node, mouse_x, mouse_y, &event);
                break;

                default:
                break;
            }
        }
    }
}
