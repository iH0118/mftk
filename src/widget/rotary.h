#ifndef INCLUDE_MFTK_ROTARY_H
#define INCLUDE_MFTK_ROTARY_H

#include "../common.h"

void draw_widget_rotary(
    mftk_window *window,
    mftk_widget *widget
);

void do_input_rotary(
    mftk_window *window,
    mftk_widget *widget,
    int          mouse_x,
    int          mouse_y,
    SDL_Event   *event
);

#endif
