#include "widget.h"

#include "util.h"
#include "widget/container.h"
#include "widget/toggle.h"
#include "widget/led.h"

ui0118_widget *ui0118_get_widget(ui0118_window *window, const char *label)
{
    ui0118_widget *node = window->widget_top;
    while (node && strcmp(node->label, label)) node = node->next;
    return node;
}

ui0118_widget *create_widget_from_node(cJSON *node)
{
    ui0118_widget *widget = calloc(1, sizeof(ui0118_widget));

    widget->type = get_widget_type(
        cJSON_GetObjectItem(node, "type")->valuestring
    );

    widget->label = cJSON_GetObjectItem(node, "label")->valuestring;

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
        widget->data.toggle.count =
            cJSON_GetObjectItem(data, "count")->valueint;
        break;

        case UI0118_TOGGLE_MOM:
        widget->data.toggle_mom.orientation =
            cJSON_GetObjectItem(data, "orientation")->valueint;
        widget->data.toggle_mom.count =
            cJSON_GetObjectItem(data, "count")->valueint;
        break;

        case UI0118_LED_RED:
        case UI0118_LED_AMBER:
        widget->data.led.count = cJSON_GetObjectItem(data, "count")->valueint;
        break;

        case UI0118_ROTARY:
        break;

        case UI0118_TEXT:
        widget->data.text.text = cJSON_GetObjectItem(data, "text")->valuestring;
        widget->data.text.width = cJSON_GetObjectItem(data, "width")->valueint;
        widget->data.text.line = cJSON_GetObjectItem(data, "line")->valueint;
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

void ui0118_draw_widget(ui0118_window *window, ui0118_widget *widget)
{
    switch (widget->type)
    {
        case UI0118_CONTAINER:
        draw_widget_container(window, widget);
        break;

        case UI0118_TOGGLE:
        case UI0118_TOGGLE_MOM:
        draw_widget_toggle(window, widget);
        break;

        case UI0118_LED_AMBER:
        draw_widget_led_amber(window, widget);
        break;

        case UI0118_LED_RED:
        draw_widget_led_red(window, widget);
        break;

        case UI0118_ROTARY:
        //TODO
        break;

        case UI0118_TEXT:
        //TODO
        break;

        case UI0118_TEXT_COUNT:
        //TODO
        break;
    }
}
