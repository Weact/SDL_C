#ifndef BMP_IMAGE_H_INCLUDED
#define BMP_IMAGE_H_INCLUDED

#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include "sdl_manager.h"
#include <stdio.h>
#include <stdlib.h>

int bmp_surface(SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture, int format, int access, int width, int height, const char* bmp_path);
SDL_Surface* img_surface(sdl_manager* p_manager, const char* img_path);

#endif // BMP_IMAGE_H_INCLUDED
