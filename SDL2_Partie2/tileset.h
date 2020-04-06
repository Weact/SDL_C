#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED

#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include "sdl_manager.h"
#include <stdio.h>
#include <stdlib.h>

//void afficherTileSet(SDL_manager * p_manager, char** Map)

void takeTileAtIndex(sdl_manager * p_manager, char* tileset_path, int index, SDL_Rect * p_dstrect);

#endif // TILESET_H_INCLUDED
