#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL_main.h>
#include "../include/mftk.h"

char *read_file(const char *filename)
{
    FILE *fileptr = fopen(filename, "r");
    fseek(fileptr, 0L, SEEK_END);
    int filesize = ftell(fileptr);
    rewind(fileptr);
    char *buffer = malloc(filesize);
    fread(buffer, sizeof(char), filesize, fileptr);
    fclose(fileptr);
    return buffer;
}

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);

    char *ui_json = read_file("test.json");
    mftk_window *window = mftk_create_window_json(ui_json);
    free(ui_json);

    mftk_widget *sw_op_a     = mftk_get_widget(window, "switches_op_a");
    mftk_widget *sw_op_b     = mftk_get_widget(window, "switches_op_b");
    mftk_widget *sw_add_sub  = mftk_get_widget(window, "switch_add_sub");
    mftk_widget *led_carry   = mftk_get_widget(window, "led_carry");
    mftk_widget *leds_result = mftk_get_widget(window, "leds_result");
    mftk_widget *leds_op_a   = mftk_get_widget(window, "leds_op_a");
    mftk_widget *leds_op_b   = mftk_get_widget(window, "leds_op_b");
    mftk_widget *led_add     = mftk_get_widget(window, "led_add");
    mftk_widget *led_sub     = mftk_get_widget(window, "led_sub");

    mftk_widget *leds_rotary = mftk_get_widget(window, "leds_rotary");
    mftk_widget *rotary_test = mftk_get_widget(window, "rotary_test");

    sw_add_sub->data.toggle.state = 1;

    while (1)
    {
        mftk_do_input(window);

        led_add->data.led.state = sw_add_sub->data.toggle.state;
        led_sub->data.led.state = !sw_add_sub->data.toggle.state;

        leds_op_a->data.led.state = sw_op_a->data.toggle.state;
        leds_op_b->data.led.state = sw_op_b->data.toggle.state;

        int result = sw_add_sub->data.toggle.state
            ? sw_op_a->data.toggle.state + sw_op_b->data.toggle.state
            : sw_op_a->data.toggle.state - sw_op_b->data.toggle.state;

        leds_result->data.led.state = result;
        led_carry->data.led.state = result >> 8;

        leds_rotary->data.led.state = rotary_test->data.rotary.state;

        mftk_draw_window(window);
        SDL_RenderPresent(window->renderer);
    }

    return 0;
}
