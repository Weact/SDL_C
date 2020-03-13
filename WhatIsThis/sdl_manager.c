#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "sdl_manager.h"

void sdl_manager_INIT(SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* rgb_surface, SDL_Surface* bmp_surface, char* bmp_path, SDL_Texture* texture)
{
    int format = 0;
    int access = 0;
    int width = 1280;
    int height = 720;

    int depth = 32;

    window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE); //Create window
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

	rgb_surface = SDL_CreateRGBSurface(0, width, height, depth, 0, 0, 0, 0);
	bmp_surface = SDL_LoadBMP(bmp_path);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, &width, &height);
}
