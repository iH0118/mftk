#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/ui0118.h"
//#include "ui0118_texture.h"

int main(void)
{
    FILE *stream_ui_json = fopen("test.json", "r");
    fseek(stream_ui_json, 0L, SEEK_END);
    int filesize = ftell(stream_ui_json);
    rewind(stream_ui_json);
    char *ui_json = malloc(filesize);
    fread(ui_json, sizeof(char), filesize, stream_ui_json);
    fclose(stream_ui_json);

    SDL_Init(SDL_INIT_VIDEO);

    ui0118_window *window = ui0118_create_window_json(ui_json);

    free(ui_json);

    ui0118_widget *sw_op_a = ui0118_get_widget(window, "switches_op_a");
    ui0118_widget *sw_op_b = ui0118_get_widget(window, "switches_op_b");
    ui0118_widget *sw_add_sub = ui0118_get_widget(window, "switch_add_sub");
    ui0118_widget *led_carry = ui0118_get_widget(window, "led_carry");
    ui0118_widget *leds_result = ui0118_get_widget(window, "leds_result");
    ui0118_widget *leds_op_a = ui0118_get_widget(window, "leds_op_a");
    ui0118_widget *leds_op_b = ui0118_get_widget(window, "leds_op_b");
    ui0118_widget *led_add = ui0118_get_widget(window, "led_add");
    ui0118_widget *led_sub = ui0118_get_widget(window, "led_sub");

    sw_add_sub->data.toggle.state = 1;

    while (1)
    {
        ui0118_do_input(window);

        led_add->data.led.state = sw_add_sub->data.toggle.state;
        led_sub->data.led.state = !sw_add_sub->data.toggle.state;

        leds_op_a->data.led.state = sw_op_a->data.toggle.state;
        leds_op_b->data.led.state = sw_op_b->data.toggle.state;

        int result = sw_add_sub->data.toggle.state
            ? sw_op_a->data.toggle.state + sw_op_b->data.toggle.state
            : sw_op_a->data.toggle.state - sw_op_b->data.toggle.state;

        leds_result->data.led.state = result;
        led_carry->data.led.state = result >> 8;

        ui0118_draw_window(window);
        SDL_RenderPresent(window->renderer);
    }

    return 0;
}
