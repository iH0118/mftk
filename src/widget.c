#include "widget.h"

#include <string.h>
#include "util.h"
#include "widget/container.h"
#include "widget/toggle.h"
#include "widget/led.h"
#include "widget/text.h"

mftk_widget *mftk_get_widget(
    mftk_window *window,
    const char  *label
)
{
    mftk_widget *node = window->widget_top;
    while (node && strcmp(node->label, label)) node = node->next;
    return node;
}

mftk_widget *create_widget_from_node(
    cJSON *node
)
{
    mftk_widget *widget = calloc(1, sizeof(mftk_widget));

    widget->type = get_widget_type(
        cJSON_GetObjectItem(node, "type")->valuestring
    );

    widget->label = cJSON_GetObjectItem(node, "label")->valuestring;

    widget->x = cJSON_GetObjectItem(node, "x")->valueint;
    widget->y = cJSON_GetObjectItem(node, "y")->valueint;

    cJSON *data = cJSON_GetObjectItem(node, "data");

    switch (widget->type)
    {
        case MFTK_CONTAINER:
        widget->data.container.size_x =
            cJSON_GetObjectItem(data, "size_x")->valueint;
        widget->data.container.size_y =
            cJSON_GetObjectItem(data, "size_y")->valueint;
        widget->data.container.color = get_json_color(
            cJSON_GetObjectItem(data, "color")
        );
        break;

        case MFTK_TOGGLE:
        widget->data.toggle.count =
            cJSON_GetObjectItem(data, "count")->valueint;
        break;

        case MFTK_TOGGLE_MOM:
        widget->data.toggle_mom.orientation =
            cJSON_GetObjectItem(data, "orientation")->valueint;
        widget->data.toggle_mom.count =
            cJSON_GetObjectItem(data, "count")->valueint;
        break;

        case MFTK_LED_RED:
        case MFTK_LED_AMBER:
        widget->data.led.count = cJSON_GetObjectItem(data, "count")->valueint;
        break;

        case MFTK_ROTARY:
        break;

        case MFTK_TEXT:
        widget->data.text.text = cJSON_GetObjectItem(data, "text")->valuestring;
        widget->data.text.width = cJSON_GetObjectItem(data, "width")->valueint;
        widget->data.text.line = cJSON_GetObjectItem(data, "line")->valueint;
        break;

        case MFTK_TEXT_COUNT:
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

void mftk_draw_widget(
    mftk_window *window,
    mftk_widget *widget
)
{
    switch (widget->type)
    {
        case MFTK_CONTAINER:
        draw_widget_container(window, widget);
        break;

        case MFTK_TOGGLE:
        case MFTK_TOGGLE_MOM:
        draw_widget_toggle(window, widget);
        break;

        case MFTK_LED_AMBER:
        draw_widget_led_amber(window, widget);
        break;

        case MFTK_LED_RED:
        draw_widget_led_red(window, widget);
        break;

        case MFTK_ROTARY:
        //TODO
        break;

        case MFTK_TEXT:
        draw_widget_text(window, widget);
        break;

        case MFTK_TEXT_COUNT:
        draw_widget_text_count(window, widget);
        break;
    }
}
