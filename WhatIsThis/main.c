#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "sdl_manager.h"

int main(int argc, char *argv[])
{
    sdl_manager* Manage;
    sdl_manager_INIT(Manage->pWindow, Manage->pRenderer, Manage->p_RGB_Surface, Manage->p_BMP_Surface, "Vierbit4.bmp", Manage->pTexture);

    SDL_Rect rect = {100,100,100,100}; //Create rect x100 y100 w100 h100
    SDL_Rect rect2 = {300, 300, 600, 600}; //Create rect x300 y300 w600 h600

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // SDL init
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	//bmp_surface(pRenderer); Display the BMP image fonction

    //DrawFilledCircle(pRenderer, 200, 200, 30, SDL_MapRGB(base_surface->format, 255, 0, 0)); //Display Filled Circle
    //DrawCircle(pRenderer, 300, 300, 60, SDL_MapRGB(base_surface->format, 0, 255, 255)); //Display Empty Circle

    SDL_RenderDrawRect(Manage->pRenderer, &rect);
    SDL_FillRect(Manage->p_RGB_Surface, &rect, SDL_MapRGB(Manage->p_RGB_Surface->format, 0, 255, 0));
    SDL_RenderFillRect(Manage->pRenderer, &rect);
	SDL_RenderPresent(Manage->pRenderer);

	SDL_Delay(3000); //3s break, so the window opens and doesn't close instantly. This method will be explained later.

    SDL_DestroyTexture(Manage->pTexture);
	SDL_DestroyRenderer(Manage->pRenderer); //Destroy the pRenderer
	SDL_DestroyWindow(Manage->pWindow); //Destroy the window
	SDL_Quit();
	return 0;

	//This will display a red window, wait 3s and close.
}


