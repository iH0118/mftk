#ifndef INCLUDE_MFTK_WIDGET_H
#define INCLUDE_MFTK_WIDGET_H

#include "common.h"

mftk_widget *mftk_get_widget(
    mftk_window *window,
    const char  *label
);

mftk_widget *create_widget_from_node(
    cJSON *node
);

void mftk_draw_widget(
    mftk_window *window,
    mftk_widget *widget
);

#endif
