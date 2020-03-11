#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // SDL init
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
	// resizable 1280x720 centered window creation

	if(window == NULL) //errors management
	{
		printf("Error creating the window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Delay(1000); //1s break, so the window opens and doesn't close instantly. This method will be explained later.

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
