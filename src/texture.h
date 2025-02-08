#ifndef INCLUDE_MFTK_TEXTURE_H
#define INCLUDE_MFTK_TEXTURE_H

#include "common.h"

void mftk_init_textures(mftk_window *window);

void blit(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);

#endif
