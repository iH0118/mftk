#ifndef INCLUDE_UI0118_UTIL_H
#define INCLUDE_UI0118_UTIL_H

#include "common.h"

SDL_Color get_json_color(cJSON *color_json);

ui0118_widget_type get_widget_type(const char *type);

int get_number_digits(int n);

#endif
