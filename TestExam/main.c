#include <stdio.h>
#include <stdlib.h>
#include "../SDL2/SDL.h"
#include "sdl_manager.h"
#include "data_structure.h"

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }else{
        printf("Hello World");

        sdl_manager manager; //New sdl manager
        sdl_manager * p_manager = &manager;
        sprite_list s_list;
        sprite_list * p_spritelist = &s_list;

        SDL_Manager_INIT(p_manager); //Init the sdl manager
        init_sprite_pile(p_spritelist);

        SDL_Delay(1000);
        SDL_Manager_FREE(p_manager); //FREE all sdl_manager instances before leaving the program
    }

    return 0;
}
