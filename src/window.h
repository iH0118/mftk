#ifndef INCLUDE_UI0118_WINDOW_H
#define INCLUDE_UI0118_WINDOW_H

#include "common.h"

ui0118_window *ui0118_create_window(const char *title, unsigned int size_x,
    unsigned int size_y, SDL_Color bg);

ui0118_window *ui0118_create_window_json(const char *ui_json);

void ui0118_draw_window(ui0118_window *window);

#endif
