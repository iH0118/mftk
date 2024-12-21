#ifndef INCLUDE_UI0118_TOGGLE_H
#define INCLUDE_UI0118_TOGGLE_H

#include "../common.h"

void draw_widget_toggle(ui0118_window *window, ui0118_widget *widget);

void do_input_toggle(ui0118_window *window, ui0118_widget *node,
    int mouse_x, int mouse_y, SDL_Event *event);

#endif
