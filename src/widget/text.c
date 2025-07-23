#include "text.h"

#include <string.h>
#include "../texture.h"
#include "../util.h"

void draw_widget_text(
    mftk_window *window,
    mftk_widget *widget
)
{
    int text_len = strlen(widget->data.text.text);
    int center_x = widget->x * MFTK_UNIT +
        (widget->data.text.width * MFTK_UNIT) / 2;
    int start_x = center_x - 2 - 3 * (text_len - 1);

    for (int i = 0; i < text_len; i++)
    {
        char c = widget->data.text.text[i];

        if (c < 0x20 || c > 0x7E) return;

        blit(
            window->renderer,
            window->texture_set.letter[c - 0x20],
            start_x + 6 * i,
            widget->y * MFTK_UNIT + 2
        );
    }

    if (widget->data.text.line)
    {
        int y_top = widget->y * MFTK_UNIT + 5;
        int y_bot = y_top + 4;  
        int x_start1 = widget->x * MFTK_UNIT + 2;
        int x_end1 = start_x - 4;
        int x_start2 = start_x + 2 + 6 * text_len;
        int x_end2 = (widget->x + widget->data.text.width) * MFTK_UNIT - 2;

        SDL_SetRenderDrawColor(window->renderer, 255, 255, 255, 255);
        SDL_RenderLine(window->renderer, x_start1, y_bot, x_start1, y_top);
        SDL_RenderLine(window->renderer, x_start1, y_top, x_end1,   y_top);
        SDL_RenderLine(window->renderer, x_start2, y_top, x_end2,   y_top);
        SDL_RenderLine(window->renderer, x_end2,   y_top, x_end2,   y_bot);
    }
}

void draw_widget_text_count(
    mftk_window *window,
    mftk_widget *widget
)
{
    for (unsigned int i = 0; i < widget->data.text_count.count; i++)
    {
        int number = widget->data.text_count.start +
            i * widget->data.text_count.step;
        int text_len = get_number_digits(number);
        int center_x = (widget->x + 2 * i + 1) * MFTK_UNIT;
        int start_x = center_x - 2 - 3 * (text_len);

        for (int k = text_len; k >= 0; k--) 
        {
            blit(
                window->renderer,
                window->texture_set.letter[(number % 10) + '0' - 0x20],
                start_x + 6 * k,
                widget->y * MFTK_UNIT + 2
            );

            number /= 10;
        }
    }
}
