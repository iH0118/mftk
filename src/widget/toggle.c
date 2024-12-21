#include "toggle.h"

#include "../texture.h"

void draw_widget_toggle(ui0118_window *window, ui0118_widget *widget)
{
    for (int i = 0; i < widget->data.toggle.count; i++)
    {
        blit(
            window->renderer,
            window->texture_set.toggle.base,
            (widget->x + 2 * i) * UI0118_UNIT + 2,
            widget->y * UI0118_UNIT + 1
        );

        blit(
            window->renderer,
            widget->data.toggle.trans_state >>
                (widget->data.toggle.count - i - 1) & 1
                ? window->texture_set.toggle.center
                : widget->data.toggle.state >>
                    (widget->data.toggle.count - i - 1) & 1
                    ? window->texture_set.toggle.up
                    : window->texture_set.toggle.down,
            (widget->x + 2 * i) * UI0118_UNIT + 5,
            widget->y * UI0118_UNIT + 1
        );

        if (!window->trans_counter) widget->data.toggle.trans_state = 0;
    }
}

void do_input_toggle(ui0118_window *window, ui0118_widget *node,
    int mouse_x, int mouse_y, SDL_Event *event)
{
    if (event->type != SDL_MOUSEBUTTONDOWN && event->type != SDL_MOUSEWHEEL)
    {
        return;
    }

    for (int i = 0; i < node->data.toggle.count; i++)
    {
        int dx = mouse_x - (node->x + 1 + 2 * i) * UI0118_UNIT;
        int dy = mouse_y - (node->y + 1) * UI0118_UNIT;

        if (dx * dx + dy * dy <= UI0118_TOGGLE_RADIUS2)
        {
            long state_prev = node->data.toggle.state;

            if (event->type == SDL_MOUSEBUTTONDOWN)
            {
                switch (event->button.button)
                {
                    /* left click: toggle individual switch on*/
                    case 1:
                    node->data.toggle.state ^= 1 <<
                        (node->data.toggle.count - i - 1);
                    break;

                    /* middle click: reset row of switches to 0 */
                    case 2:
                    node->data.toggle.state = 0;
                    break;
                }
            }

            else if (event->type == SDL_MOUSEWHEEL)
            {
                /* scroll up: increase switch row value*/
                if (event->wheel.y > 0)
                {
                    node->data.toggle.state = (node->data.toggle.state + 1) %
                        (1 << node->data.toggle.count);
                }

                /* scroll down: decrease switch row value*/
                else if (event->wheel.y < 0)
                {
                    node->data.toggle.state = (node->data.toggle.state - 1) %
                        (1 << node->data.toggle.count);
                }
            }

            node->data.toggle.trans_state = node->data.toggle.state ^ state_prev;
            window->trans_counter = TRANSITION_TIME;
        }
    }
}
