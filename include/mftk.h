#ifndef INCLUDE_MFTK_H
#define INCLUDE_MFTK_H

#include "types.h"

mftk_window *mftk_create_window(
    const char   *title,
    unsigned int  size_x,
    unsigned int  size_y,
    SDL_Color     bg
);

mftk_window *mftk_create_window_json(
    const char *ui_json
);

mftk_widget *mftk_get_widget(
    mftk_window *window,
    const char  *label
);

void mftk_draw_widget(
    mftk_window *window,
    mftk_widget *widget
);

void mftk_draw_window(
    mftk_window *window
);

void mftk_do_input(
    mftk_window *window
);

#endif
