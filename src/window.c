#include "window.h"

#include "texture.h"
#include "util.h"
#include "widget.h"

ui0118_window *ui0118_create_window(const char *title, unsigned int size_x,
    unsigned int size_y, SDL_Color bg)
{
    ui0118_window *window = malloc(sizeof(ui0118_window));

    unsigned int renderer_flags =
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    window->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        size_x * UI0118_UNIT + 1,
        size_y * UI0118_UNIT + 1,
        0
    );

    window->renderer = SDL_CreateRenderer(window->window, -1, renderer_flags);
    window->widget_top = NULL;
    window->color_bg = bg;

    ui0118_init_textures(window);

    return window;
}

ui0118_window *ui0118_create_window_json(const char *ui_json)
{
    cJSON *root = cJSON_Parse(ui_json);
    cJSON *window_json = cJSON_GetObjectItem(root, "window");
    cJSON *widgets_json = cJSON_GetObjectItem(root, "widgets");
    cJSON *node;

    ui0118_window *window = ui0118_create_window(
        cJSON_GetObjectItem(window_json, "title")->valuestring,
        cJSON_GetObjectItem(window_json, "width")->valueint,
        cJSON_GetObjectItem(window_json, "height")->valueint,
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

    return window;
}

void ui0118_draw_window(ui0118_window *window)
{
    SDL_SetRenderDrawColor(
        window->renderer,
        window->color_bg.r,
        window->color_bg.g,
        window->color_bg.b,
        window->color_bg.a
    );

    SDL_RenderClear(window->renderer);

    for (ui0118_widget *node = window->widget_top; node; node = node->next)
    {
        ui0118_draw_widget(window, node);
    }

    if (window->trans_counter) window->trans_counter -= 1;
}
