#include "ui0118.h"
#include <SDL2/SDL.h>

ui0118_window *ui0118_create_window(
    const char *title, unsigned int size_x, unsigned int size_y
)
{
    ui0118_window *window = malloc(sizeof(ui0118_window));

    unsigned int renderer_flags =
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    window->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        (int) size_x * UI0118_UNIT + 1,
        (int) size_y * UI0118_UNIT + 1,
        0
    );

    window->renderer = SDL_CreateRenderer(window->window, -1, renderer_flags);

    window->widget_top = NULL;
    window->widget_bottom = NULL;

    return window;
}

void redraw_widget(ui0118_widget *widget, int priority)
{
    if (priority < widget->redraw_priority) return;

    //TODO: actually write this function
}

void redraw_widget_subtree(ui0118_widget **current, int priority)
{
    ui0118_widget *subtree_start;

    redraw_widget(*current, priority);

    if ((*current)->type == UI0118_WIDGET_CONTAINER)
    {
        subtree_start = *current;

        do redraw_widget_subtree(current, priority);
        while (*current != subtree_start);
    }

    *current = (*current)->next;
}

void redraw_widget_tree(ui0118_widget *start, int priority)
{
    ui0118_widget *current = start;

    do redraw_widget_subtree(&current, priority);
    while (current != start);
}

int ui0118_redraw_window(ui0118_window *window, int priority)
{
    if (!window || !window->widget_top) return 1;



    return 0;
}

void ui0118_insert_widget(ui0118_widget *widget, ui0118_widget *prev)
{
    ui0118_widget *temp = prev->next;
    prev->next = widget;
    widget->next = temp;
}

