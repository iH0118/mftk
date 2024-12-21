#ifndef INCLUDE_UI0118_WIDGET_H
#define INCLUDE_UI0118_WIDGET_H

#include "common.h"

ui0118_widget *ui0118_get_widget(ui0118_window *window, const char *label);

ui0118_widget *create_widget_from_node(cJSON *node);

void ui0118_draw_widget(ui0118_window *window, ui0118_widget *widget);

#endif
