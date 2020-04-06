#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED

#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include "sdl_manager.h"
#include <stdio.h>
#include <stdlib.h>

//void afficherTileSet(SDL_manager * p_manager, char** Map)

void takeTileAtIndex(sdl_manager * p_manager, SDL_Surface * p_tileset_surface, SDL_Rect src_rect ,SDL_Rect * p_dstrect)
SDL_Surface * setTileset(const char * tileset_path);

#endif // TILESET_H_INCLUDED
