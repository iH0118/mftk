#ifndef INCLUDE_MFTK_TOGGLE_H
#define INCLUDE_MFTK_TOGGLE_H

#include "../common.h"

void mftk_draw_widget_toggle(
    mftk_window *window,
    mftk_widget *widget
);

void mftk_do_input_toggle(
    mftk_window *window,
    mftk_widget *widget,
    int          mouse_x,
    int          mouse_y,
    SDL_Event   *event
);

#endif
