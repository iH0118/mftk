#include "util.h"

SDL_Color get_json_color(cJSON *color_json)
{
    SDL_Color color;
    color.r = cJSON_GetArrayItem(color_json, 0)->valueint;
    color.g = cJSON_GetArrayItem(color_json, 1)->valueint;
    color.b = cJSON_GetArrayItem(color_json, 2)->valueint;
    color.a = cJSON_GetArrayItem(color_json, 3)->valueint;
    return color;
}

ui0118_widget_type get_widget_type(const char *type)
{
    if (!strcmp(type, "UI0118_CONTAINER" )) return UI0118_CONTAINER;
    if (!strcmp(type, "UI0118_TOGGLE"    )) return UI0118_TOGGLE;
    if (!strcmp(type, "UI0118_TOGGLE_MOM")) return UI0118_TOGGLE_MOM;
    if (!strcmp(type, "UI0118_LED_RED"   )) return UI0118_LED_RED;
    if (!strcmp(type, "UI0118_LED_AMBER" )) return UI0118_LED_AMBER;
    if (!strcmp(type, "UI0118_ROTARY"    )) return UI0118_ROTARY;
    if (!strcmp(type, "UI0118_TEXT"      )) return UI0118_TEXT;
    if (!strcmp(type, "UI0118_TEXT_COUNT")) return UI0118_TEXT_COUNT;
    return -1;
}
