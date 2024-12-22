#include "text.h"

#include "../texture.h"
#include "../util.h"
#include <SDL2/SDL_render.h>

void draw_widget_text(ui0118_window *window, ui0118_widget *widget)
{
    int text_len = strlen(widget->data.text.text);
    int center_x = widget->x * UI0118_UNIT +
        (widget->data.text.width * UI0118_UNIT) / 2;
    int start_x = center_x - 2 - 3 * (text_len - 1);

    for (int i = 0; i < text_len; i++)
    {
        char c = widget->data.text.text[i];

        if (c < 0x20 || c > 0x7E) return;

        blit(
            window->renderer,
            window->texture_set.letter[c - 0x20],
            start_x + 6 * i,
            widget->y * UI0118_UNIT + 2
        );
    }

    if (widget->data.text.line)
    {
        int y_top = widget->y * UI0118_UNIT + 5;
        int y_bot = widget->y * UI0118_UNIT+ 9;
        int x_start1 = widget->x * UI0118_UNIT + 2;
        int x_end1 = start_x - 4;
        int x_start2 = start_x + 2 + 6 * text_len;
        int x_end2 =
            (widget->x + widget->data.text.width) * UI0118_UNIT - 2;

        SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(window->renderer, x_start1, y_bot, x_start1, y_top);
        SDL_RenderDrawLine(window->renderer, x_start1, y_top, x_end1,   y_top);
        SDL_RenderDrawLine(window->renderer, x_start2, y_top, x_end2,   y_top);
        SDL_RenderDrawLine(window->renderer, x_end2,   y_top, x_end2,   y_bot);
    }
}

void draw_widget_text_count(ui0118_window *window, ui0118_widget *widget)
{
    for (unsigned int i = 0; i < widget->data.text_count.count; i++)
    {
        int number = widget->data.text_count.start +
            i * widget->data.text_count.step;
        int text_len = get_number_digits(number);
        int center_x = (widget->x + 2 * i + 1) * UI0118_UNIT;
        int start_x = center_x - 2 - 3 * (text_len);

        for (int k = text_len; k >= 0; k--) 
        {
            blit(
                window->renderer,
                window->texture_set.letter[(number % 10) + '0' - 0x20],
                start_x + 6 * k,
                widget->y * UI0118_UNIT + 2
            );

            number /= 10;
        }
    }
}
