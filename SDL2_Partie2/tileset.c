#include "api_image.h"
#include "sdl_manager.h"

SDL_Surface * setTileset(const char * tileset_path)
{
    SDL_Surface * p_tileset_surface = malloc(sizeof(SDL_Surface));
    p_tileset_surface = IMG_Load(tileset_path);

    return p_tileset_surface;
}
/*
void takeTileAtIndex(sdl_manager * p_manager, SDL_Surface * p_tileset_surface, int index, SDL_Rect src_rect ,SDL_Rect * p_dstrect)
{
    SDL_BlitSurface(p_tileset_surface, &tile, p_manager->pSurface, p_dstrect);
}
*/
/*
SDL_Surface * initTileSet(sdl_manager * p_manager, const char* tileset_path, int start_index, int end_index, SDL_Rect * p_dstrect)
{
    int width = 16;
    int height = 16;

    SDL_Surface * p_tileset_surface = malloc(sizeof(SDL_Surface));
    p_tileset_surface = IMG_Load(tileset_path);
}

void loopDisplayTile(sdl_manager * p_manager, int end_index, int current_index, SDL_Surface * p_srcSurface, SDL_Rect srcRect, SDL_Rect * dst_rect)
{
    for(int i = 1; i < end_index; i++)
    {
        SDL_BlitSurface(p_tileset_surface, &tile, p_manager->pSurface, p_dstrect);
        tile.x = ((current_index-1)*i) * width;
    }

    printf("\nAnimation is finished\n");
}

*/
