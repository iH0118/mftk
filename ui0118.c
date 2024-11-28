#include "ui0118.h"
#include <SDL2/SDL.h>
#include <cjson/cJSON.h>
#include <stdlib.h>

ui0118_window *ui0118_create_window(const char *title, unsigned int size_x,
    unsigned int size_y, SDL_Color bg
)
{
    ui0118_window *window = malloc(sizeof(ui0118_window));

    unsigned int renderer_flags =
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    window->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        (int) size_x * UI0118_UNIT + 1,
        (int) size_y * UI0118_UNIT + 1,
        0
    );

    window->renderer = SDL_CreateRenderer(window->window, -1, renderer_flags);
    window->widget_top = NULL;
    window->color_bg = bg;

    return window;
}

static ui0118_widget_type get_widget_type(const char *restrict type)
{
    if (!strcmp(type, "UI0118_CONTAINER")) return UI0118_CONTAINER;
    if (!strcmp(type, "UI0118_TOGGLE")) return UI0118_TOGGLE;
    if (!strcmp(type, "UI0118_TOGGLE_MOM")) return UI0118_TOGGLE_MOM;
    if (!strcmp(type, "UI0118_LED_RED")) return UI0118_LED_RED;
    if (!strcmp(type, "UI0118_LED_AMBER")) return UI0118_LED_AMBER;
    if (!strcmp(type, "UI0118_ROTARY")) return UI0118_ROTARY;
    if (!strcmp(type, "UI0118_TEXT")) return UI0118_TEXT;
    if (!strcmp(type, "UI0118_TEXT_COUNT")) return UI0118_TEXT_COUNT;
    return -1;
}

static SDL_Color get_json_color(cJSON *color_json)
{
    SDL_Color color;
    color.r = cJSON_GetArrayItem(color_json, 0)->valueint;
    color.g = cJSON_GetArrayItem(color_json, 1)->valueint;
    color.b = cJSON_GetArrayItem(color_json, 2)->valueint;
    color.a = cJSON_GetArrayItem(color_json, 3)->valueint;
    return color;
}

ui0118_widget *create_widget_from_node(cJSON *node)
{
    ui0118_widget *widget = malloc(sizeof(ui0118_widget));

    widget->type = get_widget_type(
        cJSON_GetObjectItem(node, "type")->valuestring
    );

    widget->x = cJSON_GetObjectItem(node, "x")->valueint;
    widget->y = cJSON_GetObjectItem(node, "y")->valueint;

    cJSON *data = cJSON_GetObjectItem(node, "data");

    switch (widget->type)
    {
        case UI0118_CONTAINER:
            widget->data.container.size_x = 
                cJSON_GetObjectItem(data, "size_x")->valueint;
            widget->data.container.size_y =
                cJSON_GetObjectItem(data, "size_y")->valueint;
            widget->data.container.color = get_json_color(
                cJSON_GetObjectItem(data, "color")
            );
            break;

        case UI0118_TOGGLE:
            //TODO
            break;

        case UI0118_TOGGLE_MOM:
            //TODO
            break;

        case UI0118_LED_RED:
        case UI0118_LED_AMBER:
            widget->data.led.count =
                cJSON_GetObjectItem(data, "count")->valueint;
            break;

        case UI0118_ROTARY:
            break;

        case UI0118_TEXT:
            widget->data.text.text =
                cJSON_GetObjectItem(data, "text")->valuestring;
            widget->data.text.width =
                cJSON_GetObjectItem(data, "width")->valueint;
            widget->data.text.line =
                cJSON_GetObjectItem(data, "line")->valueint;
            break;

        case UI0118_TEXT_COUNT:
            widget->data.text_count.start =
                cJSON_GetObjectItem(data, "start")->valueint;
            widget->data.text_count.count =
                cJSON_GetObjectItem(data, "count")->valueint;
            widget->data.text_count.step =
                cJSON_GetObjectItem(data, "step")->valueint;
            break;
    }

    return widget;
}

ui0118_window *ui0118_create_window_json(const char *restrict ui_json)
{
    cJSON *root = cJSON_Parse(ui_json);
    cJSON *window_json = cJSON_GetObjectItem(root, "window");
    cJSON *widgets_json = cJSON_GetObjectItem(root, "widgets");
    cJSON *node;

    ui0118_window *window = ui0118_create_window(
        cJSON_GetObjectItem(window_json, "title")->valuestring,
        cJSON_GetObjectItem(window_json, "size_x")->valueint,
        cJSON_GetObjectItem(window_json, "size_y")->valueint,
        get_json_color(cJSON_GetObjectItem(window_json, "color_bg"))
    );

    ui0118_widget **widget_next = &(window->widget_top);
    ui0118_widget *widget_prev = NULL;

    for (node = widgets_json->child; node; node = node->next)
    {
        ui0118_widget *widget = create_widget_from_node(node);

        *widget_next = widget;
        widget_next = &(widget->next);

        widget->prev = widget_prev;
        widget_prev = widget;
    }

    //TODO

    return window;
}
