#ifndef INCLUDE_UI0118_TEXTURE_H
#define INCLUDE_UI0118_TEXTURE_H

#include "ui0118_common.h"

void ui0118_init_textures(ui0118_window *window);

void ui0118_blit(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);

#endif
