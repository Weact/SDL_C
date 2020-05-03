#include "sdl_manager.h"

int SDL_Manager_INIT(sdl_manager* p_manager)
{
    int format = 0;
    int access = 0;
    int width = 1280;
    int height = 720;
    int depth = 32;

    p_manager->pWindow = SDL_CreateWindow("SDL Window", 100, 100, 1280, 720, 0);//Create window
    p_manager->pRenderer = SDL_CreateRenderer(p_manager->pWindow, -1, SDL_RENDERER_ACCELERATED);
    p_manager->pSurface = SDL_CreateRGBSurface(0, width, height, depth, 0,  0,  0, 0);
	p_manager->pTexture = SDL_CreateTexture(p_manager->pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	if(p_manager->pWindow == NULL) //errors management
	{
		printf("Error creating the window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	if(p_manager->pRenderer == NULL) //errors management
	{
		printf("Error creating the renderer : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SDL_Manager_FREE(sdl_manager* p_manager)
{
    SDL_DestroyRenderer(p_manager->pRenderer);
    SDL_DestroyTexture(p_manager->pTexture);
    SDL_DestroyWindow(p_manager->pWindow);
    SDL_FreeSurface(p_manager->pSurface);
}
