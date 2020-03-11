#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration
	SDL_Renderer* renderer; //Renderer declaration

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // SDL init
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);

	if(window == NULL) //errors management
	{
		printf("Error creating the window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	//RENDERER CREATION
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL) //errors management
	{
		printf("Error creating the renderer : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

//Red color
	SDL_SetRenderDrawColor(renderer, 255,0,0,255);
	//Then clear the window by using SDL_RenderClear function
	SDL_RenderClear(renderer);
	//We have now to display our render using SDL_RenderPresent function
	SDL_RenderPresent(renderer);

	SDL_Delay(3000); //3s break, so the window opens and doesn't close instantly. This method will be explained later.

	SDL_DestroyRenderer(renderer); //Destroy the renderer
	SDL_DestroyWindow(window); //Destroy the window
	SDL_Quit();
	return 0;

	//This will display a red window, wait 3s and close.
}
