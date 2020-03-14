#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "sdl_manager.h"
#include "carre.h"
#include "circle.h"
#include "color_list.h"

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }else
    {
        //IF SDL SUCCESS
        sdl_manager manager;
        sdl_manager* p_sdl_manager = &manager;
        SDL_Manager_INIT(p_sdl_manager);

        //Display BMP image
        bmp_surface(p_sdl_manager->pRenderer, p_sdl_manager->pSurface, p_sdl_manager->pTexture, 0, 0, 1280, 720, "Vierbit4.bmp");

        SDL_Rect rect = {500,300,50,50}; //Create rect x100 y100 w100 h100
        SDL_Rect rect2 = {700, 300, 100, 100}; //Create rect x300 y300 w600 h600

        DrawFilledCircle(p_sdl_manager->pRenderer, 100, 300, 50, rouge); //Display Filled Circle
        DrawCircle(p_sdl_manager->pRenderer, 300, 300, 100, bleu); //Display Empty Circle

        DrawFilledSquare(p_sdl_manager->pRenderer, p_sdl_manager->pSurface, &rect, 0, 255, 0, 0);
        DrawEmptySquare(p_sdl_manager->pRenderer, &rect2, 255, 0, 255, 0);

        SDL_RenderPresent(p_sdl_manager->pRenderer);

        SDL_Delay(2000);

        SDL_Manager_FREE(p_sdl_manager);
    }

	SDL_Quit();
	return 0;
}


