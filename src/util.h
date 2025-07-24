#ifndef INCLUDE_MFTK_UTIL_H
#define INCLUDE_MFTK_UTIL_H

#include "common.h"

SDL_Color mftk_get_json_color(
    cJSON *color_json
);

mftk_widget_type mftk_get_widget_type(
    const char *type
);

int mftk_count_digits(
    int n
);

#endif
