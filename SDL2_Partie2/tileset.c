#include "api_image.h"
#include "sdl_manager.h"

void takeTileAtIndex(sdl_manager * p_manager, const char* tileset_path, int _index, SDL_Rect * p_dstrect)
{
    int width = 16;
    int height = 16;

    SDL_Surface * p_tileset_surface = malloc(sizeof(SDL_Surface));
    p_tileset_surface = IMG_Load(tileset_path);

    SDL_Rect tile = {16, 0, 16, 16};

    SDL_BlitSurface(p_tileset_surface, &tile, p_manager->pSurface, p_dstrect);

}
