#include "util.h"

#include <string.h>

SDL_Color get_json_color(cJSON *color_json)
{
    SDL_Color color;
    color.r = cJSON_GetArrayItem(color_json, 0)->valueint;
    color.g = cJSON_GetArrayItem(color_json, 1)->valueint;
    color.b = cJSON_GetArrayItem(color_json, 2)->valueint;
    color.a = cJSON_GetArrayItem(color_json, 3)->valueint;
    return color;
}

mftk_widget_type get_widget_type(const char *type)
{
    if (!strcmp(type, "MFTK_CONTAINER" )) return MFTK_CONTAINER;
    if (!strcmp(type, "MFTK_TOGGLE"    )) return MFTK_TOGGLE;
    if (!strcmp(type, "MFTK_TOGGLE_MOM")) return MFTK_TOGGLE_MOM;
    if (!strcmp(type, "MFTK_LED_RED"   )) return MFTK_LED_RED;
    if (!strcmp(type, "MFTK_LED_AMBER" )) return MFTK_LED_AMBER;
    if (!strcmp(type, "MFTK_ROTARY"    )) return MFTK_ROTARY;
    if (!strcmp(type, "MFTK_TEXT"      )) return MFTK_TEXT;
    if (!strcmp(type, "MFTK_TEXT_COUNT")) return MFTK_TEXT_COUNT;
    return -1;
}

int get_number_digits(int n)
{
    if (n / 10) return get_number_digits(n / 10) + 1;
    return 0;
}
