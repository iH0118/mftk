#ifndef INCLUDE_MFTK_ROTARY_H
#define INCLUDE_MFTK_ROTARY_H

#include "../common.h"

void mftk_draw_widget_rotary(
    mftk_window *window,
    mftk_widget *widget
);

void mftk_do_input_rotary(
    mftk_window *window,
    mftk_widget *widget,
    int          mouse_x,
    int          mouse_y,
    SDL_Event   *event
);

#endif
