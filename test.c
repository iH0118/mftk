#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "ui0118.h"

int main(void)
{
    FILE *stream_ui_json = fopen("test.json", "r");
    fseek(stream_ui_json, 0L, SEEK_END);
    int filesize = ftell(stream_ui_json);
    rewind(stream_ui_json);
    char *ui_json = malloc(filesize);
    fread(ui_json, sizeof(char), filesize, stream_ui_json);
    fclose(stream_ui_json);

    ui0118_window *window = ui0118_create_window_json(ui_json);

    free(ui_json);

    while (1)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;

                default: 
                    break;
            }
        }
    }

    return 0;
}
