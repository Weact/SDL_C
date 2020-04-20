#include <string.h>
#include "sdl_manager.h"
#include "map.h"

#define CACHE_SIZE  5000

/*
SDL_Surface * LoadImage(const char * p_imagePath)
{
    SDL_Surface* p_imageResult;
    SDL_Surface* p_image = SDL_LoadBMP(p_imagePath);
    if(p_image == NULL)
    {
        printf("Error. Folder not Found.\n", p_imagePath);
        SDL_Quit();
    }
    p_imageResult = SDL_DisplayFormat(p_image);
    SDL_FreeSurface(p_image);
    return p_imageResult;
}

void LoadMap_Tileset(FILE* p_file, TMap * p_map)
{
    int n_tile, i, j;
    char buffer[CACHE_SIZE];
    char buffer2[CACHE_SIZE];
    fscanf(p_file, "%s", buffer);
    p_map->p_Tileset = LoadImage(buffer);
}
*/
