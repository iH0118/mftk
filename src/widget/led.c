#include "led.h"

#include "../texture.h"

void draw_widget_led_amber(mftk_window *window, mftk_widget *widget)
{
    for (int i = 0; i < widget->data.led.count; i++)
    {
        blit(
            window->renderer,
            widget->data.led.state >> (widget->data.led.count - i - 1) & 1
                ? window->texture_set.led_amber.on
                : window->texture_set.led_amber.off,
            (widget->x + 2 * i) * MFTK_UNIT + 2,
            widget->y * MFTK_UNIT + 2
        );
    }
}

void draw_widget_led_red(mftk_window *window, mftk_widget *widget)
{
    for (int i = 0; i < widget->data.led.count; i++)
    {
        blit(
            window->renderer,
            widget->data.led.state >> (widget->data.led.count - i - 1) & 1
                ? window->texture_set.led_red.on
                : window->texture_set.led_red.off,
            (widget->x + 2 * i) * MFTK_UNIT + 2,
            widget->y * MFTK_UNIT + 2
        );
    }
}
