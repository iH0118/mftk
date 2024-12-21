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

    ui0118_widget *switches = ui0118_get_widget(window, "switches_test");
    ui0118_widget *leds = ui0118_get_widget(window, "leds_result");

    while (1)
    {
        ui0118_do_input(window);

        leds->data.led.state = switches->data.toggle.state;

        ui0118_draw_window(window);
        SDL_RenderPresent(window->renderer);
    }

    return 0;
}
