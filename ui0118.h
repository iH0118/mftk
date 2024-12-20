#ifndef INCLUDE_UI0118_H
#define INCLUDE_UI0118_H

#include <SDL2/SDL.h>
#include "ui0118_types.h"

ui0118_window *ui0118_create_window(const char *title, unsigned int size_x,
    unsigned int size_y, SDL_Color bg);

ui0118_window *ui0118_create_window_json(const char *ui_json);

ui0118_widget *ui0118_get_widget(ui0118_window *window, const char *label);

void ui0118_draw_widget(ui0118_window *window, ui0118_widget *widget);

void ui0118_draw_window(ui0118_window *window);

void ui0118_do_input(ui0118_window *window);

//void ui0118_init_textures(ui0118_window *window);

//void blit(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);

void draw_widget_container(SDL_Renderer *renderer, int x, int y,
    int size_x, int size_y, SDL_Color color);

#endif
