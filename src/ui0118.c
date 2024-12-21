#include "../include/ui0118.h"
#include "common.h"

void draw_widget_container(SDL_Renderer *renderer, int x, int y,
    int size_x, int size_y, SDL_Color color)
{
    //IMPLEMENTATION TEST, FIX LATER
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {
        x * UI0118_UNIT,
        y * UI0118_UNIT,
        (x + size_x - 1) * UI0118_UNIT + 1,
        (y + size_y - 1) * UI0118_UNIT + 1
    };
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

void do_input_toggle(ui0118_window *window, ui0118_widget *node,
    int mouse_x, int mouse_y, SDL_Event *event)
{
    if (event->type != SDL_MOUSEBUTTONDOWN && event->type != SDL_MOUSEWHEEL) 
        return;

    for (int i = 0; i < node->data.toggle.count; i++) {
        int dx = mouse_x - (node->x + 1 + 2 * i) * UI0118_UNIT;
        int dy = mouse_y - (node->y + 1) * UI0118_UNIT;

        if (dx * dx + dy * dy <= UI0118_TOGGLE_RADIUS2) {
            if (event->type == SDL_MOUSEBUTTONDOWN) {
                switch (event->button.button) {
                    case 0:
                    break;
                }
            }

            node->data.toggle.state ^= 1 << (node->data.toggle.count - i);
            node->data.toggle.transition_state |= 1 <<
                (node->data.toggle.count - i);

            window->transition_counter = TRANSITION_TIME;
        }
    }
}

void ui0118_do_input(ui0118_window *window)
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    SDL_Event event;
    ui0118_widget *node;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) exit(0);

        for (node = window->widget_top; node; node = node->next) {
            if (node->type == UI0118_TOGGLE) {
                do_input_toggle(window, node, mouse_x, mouse_y, &event);
            }
        }
    }
}
