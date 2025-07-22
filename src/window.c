#include "window.h"

#include "texture.h"
#include "util.h"
#include "widget.h"

mftk_window *mftk_create_window (
    const char   *title,
    unsigned int  size_x,
    unsigned int  size_y,
    SDL_Color     bg
)
{
    mftk_window *window = malloc(sizeof(mftk_window));

    window->window = SDL_CreateWindow(
        title,
        size_x * MFTK_UNIT + 1,
        size_y * MFTK_UNIT + 1,
        0
    );

    window->renderer = SDL_CreateRenderer(window->window, NULL);
    SDL_SetRenderVSync(window->renderer, 1);
    window->widget_top = NULL;
    window->color_bg = bg;
    window->mouse_grabbed = false;
    window->mouse_offset = 0.0F;

    mftk_init_textures(window);

    return window;
}

mftk_window *mftk_create_window_json(
    const char *ui_json
)
{
    cJSON *root = cJSON_Parse(ui_json);
    cJSON *window_json = cJSON_GetObjectItem(root, "window");
    cJSON *widgets_json = cJSON_GetObjectItem(root, "widgets");
    cJSON *node;

    mftk_window *window = mftk_create_window(
        cJSON_GetObjectItem(window_json, "title")->valuestring,
        cJSON_GetObjectItem(window_json, "width")->valueint,
        cJSON_GetObjectItem(window_json, "height")->valueint,
        get_json_color(cJSON_GetObjectItem(window_json, "color_bg"))
    );

    mftk_widget **widget_next = &(window->widget_top);
    mftk_widget *widget_prev = NULL;

    for (node = widgets_json->child; node; node = node->next)
    {
        mftk_widget *widget = create_widget_from_node(node);

        *widget_next = widget;
        widget_next = &(widget->next);

        widget->prev = widget_prev;
        widget_prev = widget;
    }

    return window;
}

void mftk_draw_window(
    mftk_window *window
)
{
    SDL_SetRenderDrawColor(
        window->renderer,
        window->color_bg.r,
        window->color_bg.g,
        window->color_bg.b,
        window->color_bg.a
    );

    SDL_RenderClear(window->renderer);

    for (mftk_widget *node = window->widget_top; node; node = node->next)
    {
        mftk_draw_widget(window, node);
    }

    if (window->trans_counter) window->trans_counter -= 1;
}
