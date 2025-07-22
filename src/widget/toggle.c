#include "toggle.h"

#include "../texture.h"

void draw_widget_toggle(
    mftk_window *window,
    mftk_widget *widget
)
{
    for (int i = 0; i < widget->data.toggle.count; i++)
    {
        long state_offset = widget->data.toggle.count - i - 1;

        blit(
            window->renderer,
            window->texture_set.toggle.base,
            (widget->x + 2 * i) * MFTK_UNIT + 2,
            widget->y * MFTK_UNIT + 1
        );

        blit(
            window->renderer,
            (widget->data.toggle.trans_state >> state_offset) & 1
                ? window->texture_set.toggle.center
                : (widget->data.toggle.state >> state_offset) & 1
                    ? window->texture_set.toggle.up
                    : window->texture_set.toggle.down,
            (widget->x + 2 * i) * MFTK_UNIT + 5,
            widget->y * MFTK_UNIT + 1
        );

        if (!window->trans_counter) widget->data.toggle.trans_state = 0;
    }
}

void do_input_toggle(
    mftk_window *window,
    mftk_widget *widget,
    int          mouse_x,
    int          mouse_y,
    SDL_Event   *event
)
{
    if (event->type != SDL_EVENT_MOUSE_BUTTON_DOWN && 
        event->type != SDL_EVENT_MOUSE_WHEEL)
    {
        return;
    }

    for (int i = 0; i < widget->data.toggle.count; i++)
    {
        int dx = mouse_x - (widget->x + 1 + 2 * i) * MFTK_UNIT;
        int dy = mouse_y - (widget->y + 1) * MFTK_UNIT;

        if (dx * dx + dy * dy <= MFTK_TOGGLE_RADIUS2)
        {
            long state_prev = widget->data.toggle.state;

            if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN)
            {
                switch (event->button.button)
                {
                    /* left click: toggle individual switch on*/
                    case 1:
                    widget->data.toggle.state ^= 1 <<
                        (widget->data.toggle.count - i - 1);
                    break;

                    /* middle click: reset row of switches to 0 */
                    case 2:
                    widget->data.toggle.state = 0;
                    break;
                }
            }

            else if (event->type == SDL_EVENT_MOUSE_WHEEL)
            {
                /* scroll up: increase switch row value*/
                if (event->wheel.y > 0)
                {
                    widget->data.toggle.state =
                        (widget->data.toggle.state + 1) %
                        (1 << widget->data.toggle.count);
                }

                /* scroll down: decrease switch row value*/
                else if (event->wheel.y < 0)
                {
                    widget->data.toggle.state =
                        (widget->data.toggle.state - 1) %
                        (1 << widget->data.toggle.count);
                }
            }

            widget->data.toggle.trans_state =
                widget->data.toggle.state ^ state_prev;

            window->trans_counter = MFTK_TRANSITION_TIME;
        }
    }
}
