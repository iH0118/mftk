#include "rotary.h"

#include "../texture.h"
void draw_widget_rotary(
    mftk_window *window,
    mftk_widget *widget
)
{
    blit(
        window->renderer,
        window->texture_set.rotary.base,
        widget->x * MFTK_UNIT + 6,
        widget->y * MFTK_UNIT + 6
    );

    blit(
        window->renderer,
        window->texture_set.rotary.dial[widget->data.rotary.state % 16],
        widget->x * MFTK_UNIT + 10,
        widget->y * MFTK_UNIT + 10
    );
}

void do_mouse_button_down(
    mftk_window *window,
    mftk_widget *widget,
    int          mouse_x,
    int          mouse_y,
    SDL_Event   *event
)
{
    switch (event->button.button)
    {
        /* left click */
        case 1:
        //TODO
        //window->stored_mouse_x = mouse_x;
        //window->stored_mouse_y = mouse_y;
        //SDL_SetRelativeMouseMode(SDL_TRUE);
        break;

        /* middle click: reset state to 0*/
        case 2:
        widget->data.rotary.state = 0;
        break;
    }
}

void do_mouse_button_up(
    mftk_window *window,
    mftk_widget *widget,
    SDL_Event   *event
)
{
    if (event->button.button != 1) return;

    //SDL_SetRelativeMouseMode(SDL_FALSE);
    //SDL_WarpMouseInWindow(
    //    window->window,
    //    window->stored_mouse_x,
    //    window->stored_mouse_y
    //);
}

void do_mouse_wheel(
    mftk_widget *widget,
    SDL_Event   *event
)
{
    if (event->wheel.y > 0)
    {
        widget->data.rotary.state = (widget->data.rotary.state + 1) % 16;
    }

    else if (event->wheel.y < 0)
    {
        widget->data.rotary.state = (widget->data.rotary.state + 15) % 16;
    }
}

void do_input_rotary(
    mftk_window *window,
    mftk_widget *widget,
    int          mouse_x,
    int          mouse_y,
    SDL_Event   *event
)
{
    if (event->type != SDL_EVENT_MOUSE_BUTTON_DOWN &&
        event->type != SDL_EVENT_MOUSE_BUTTON_UP &&
        event->type != SDL_EVENT_MOUSE_WHEEL)
    {
        return;
    }

    int dx = mouse_x - (widget->x + 4) * MFTK_UNIT;
    int dy = mouse_y - (widget->y + 4) * MFTK_UNIT;

    if (dx * dx + dy * dy <= MFTK_ROTARY_RADIUS2)
    {
        switch (event->type)
        {
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
            do_mouse_button_down(window, widget, mouse_x, mouse_y, event);
            break;

            case SDL_EVENT_MOUSE_BUTTON_UP:
            do_mouse_button_up(window, widget, event);
            break;

            case SDL_EVENT_MOUSE_WHEEL:
            do_mouse_wheel(widget, event);
            break;
        }
    }
}
