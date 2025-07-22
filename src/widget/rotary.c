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
        window->mouse_grabbed = true;
        SDL_SetWindowRelativeMouseMode(window->window, true);
        SDL_Rect constraint = {mouse_x, mouse_y, 1, 1};
        SDL_SetWindowMouseRect(window->window, &constraint);
        break;

        /* middle click: reset state to 0 */
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
    switch (event->button.button)
    {
        /* left click */
        case 1:
        window->mouse_grabbed = false;
        SDL_SetWindowRelativeMouseMode(window->window, false);
        SDL_SetWindowMouseRect(window->window, NULL);
        window->mouse_offset = 0.0F;
        break;
    }
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

void do_mouse_motion(
    mftk_window *window,
    mftk_widget *widget,
    SDL_Event   *event
)
{
    if (window->mouse_grabbed)
    {
        window->mouse_offset += event->motion.yrel;

        if (window->mouse_offset <= -MFTK_MOUSE_THRESHOLD)
        {
            window->mouse_offset += MFTK_MOUSE_THRESHOLD;
            widget->data.rotary.state = (widget->data.rotary.state + 1) % 16;
        }

        else if (window->mouse_offset >= MFTK_MOUSE_THRESHOLD)
        {
            window->mouse_offset -= MFTK_MOUSE_THRESHOLD;
            widget->data.rotary.state = (widget->data.rotary.state + 15) % 16;
        }
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

            case SDL_EVENT_MOUSE_MOTION:
            do_mouse_motion(window, widget, event);
            break;
        }
    }
}
