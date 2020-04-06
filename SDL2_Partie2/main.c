#include <stdio.h>
#include <stdlib.h>
#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include "sdl_manager.h"

int main(int argc, char * argv[])
{
    int quit = 0;
    SDL_Event e;
    printf("Hello world!\n");
    if(SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    //SDL MANAGER
    sdl_manager * p_myManager = SDL_Manager_INIT();

    //INDEX
    int index_start = 1;
    int index_end = 6;
    int current_index = index_start;

    //RECTANGLE SOURCE
    SDL_Rect tile;
    int width = 16;
    tile.x = (index_start-1) * width; //Le -1 sert à pouvoir écrire la tile précise que l'on veut. Sans ça, 0 correspondrait a la 1ère, 1 à la 2ème, etc..
                                // Avec le -1, le 0 correspond à rien, le 1 correspond à la 1ère, etc..
    tile.y = 0;
    tile.w = 16;
    tile.h = 16;

    //RECTANGLE DESTINATION
    SDL_Rect * p_dsttile;
    p_dsttile->x = 100;
    p_dsttile->y = 100;


/*
    img_surface(p_myManager, "sdllogo.png");
    int index_tile = 6;
    takeTileAtIndex(p_myManager, "tileset.png", index_tile, p_dsttile);


    printf("\nTile selectionnee: %d\n", index_tile);
    printf("Correspondance:\n");
    printf("1 : Terre\n");
    printf("2 : Sable\n");
    printf("3 : Eau\n");
    printf("4 : Lave\n");
    printf("5 : Herbe\n");
    printf("6 : Pierre\n");
*/

    SDL_Surface * p_myTileset = setTileset("tileset.png"); //function that return a sdl_surface

    while(quit != 1){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){ //Si la croix est appuyer, alors on quitte
                quit = 1;
                break;
            }
        }

        //Copie la surface donnée dans une autre surface donnée
        SDL_BlitSurface(p_myTileset, &tile, p_myManager->pSurface, p_dsttile);

        //Applique le rendu complet
        SDL_ManagerRend(p_myManager);

        //Si l'index actuel est plus grand que le dernier index (dernière tile du tileset)
        //On remet l'index actual au premier tile. Sinon, on l'incrémente de 1 à chaque nouveau tile affiché
        if(current_index > index_end)
        {
            current_index = index_start;
        }else{
            current_index += 1;
        }

        //On modifie l'origine x du rectangle source par rapport à l'index séléctionné
        tile.x = (current_index-1) * width;
        SDL_Delay(200); //On attend 200ms avant d'afficher le prochain tile
    }
    SDL_Delay(2500);
    SDL_Manager_FREE(p_myManager);
    return 0;
}
