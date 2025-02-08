#ifndef INCLUDE_MFTK_WINDOW_H
#define INCLUDE_MFTK_WINDOW_H

#include "common.h"

mftk_window *mftk_create_window(const char *title, unsigned int size_x,
    unsigned int size_y, SDL_Color bg);

mftk_window *mftk_create_window_json(const char *ui_json);

void mftk_draw_window(mftk_window *window);

#endif
