#include "rotary.h"

#include "../texture.h"
#include <SDL2/SDL_events.h>

void draw_widget_rotary(mftk_window *window, mftk_widget *widget)
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

void do_mouse_button_down()
{
    
}

void do_mouse_button_up()
{

}

void do_mouse_wheel()
{

}

void do_input_rotary(mftk_window *window, mftk_widget *widget,
    int mouse_x, int mouse_y, SDL_Event *event)
{
    if (event->type != SDL_MOUSEBUTTONDOWN &&
        event->type != SDL_MOUSEBUTTONUP &&
        event->type != SDL_MOUSEWHEEL)
    {
        return;
    }

    int dx = mouse_x - (widget->x + 4) * MFTK_UNIT;
    int dy = mouse_y - (widget->y + 4) * MFTK_UNIT;

    if (dx * dx + dy * dy <= MFTK_ROTARY_RADIUS2)
    {
        switch (event->type)
        {
            case SDL_MOUSEBUTTONDOWN:
            do_mouse_button_down();
            break;

            case SDL_MOUSEBUTTONUP:
            do_mouse_button_up();
            break;

            case SDL_MOUSEWHEEL:
            do_mouse_wheel();
            break;
        }
    }
}
