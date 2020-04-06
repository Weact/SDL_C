#include <stdio.h>
#include <stdlib.h>
#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include "sdl_manager.h"

int main(int argc, char * argv[])
{
    printf("Hello world!\n");
    if(SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    sdl_manager * p_myManager = SDL_Manager_INIT();
    SDL_Rect * p_dsttile = {100, 100, 100, 100};

    //img_surface(p_myManager, "sdllogo.png");
    takeTileAtIndex(p_myManager, "tileset.png", 0, p_dsttile);

    SDL_ManagerRend(p_myManager);
    SDL_Delay(2500);
    SDL_Manager_FREE(p_myManager);
    return 0;
}
