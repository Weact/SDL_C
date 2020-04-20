#include "sdl_manager.h"

sdl_manager * SDL_Manager_INIT()
{
    int format = 0;
    int access = 0;
    int width = 1024;
    int height = 512;
    int depth = 32;
    char* bmp_path = "Vierbit4.bmp";

    sdl_manager * p_manager = malloc(sizeof(sdl_manager));

    p_manager->pWindow = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE); //Create window
    p_manager->pRenderer = SDL_CreateRenderer(p_manager->pWindow, -1, SDL_RENDERER_ACCELERATED);
    p_manager->pSurface = SDL_CreateRGBSurface(0, width, height, depth, 0,  0,  0, 0);
	p_manager->pTexture = SDL_CreateTexture(p_manager->pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	if(p_manager->pWindow == NULL) //errors management
	{
		printf("Error creating the window : %s", SDL_GetError());
		return NULL;
	}
	if(p_manager->pRenderer == NULL) //errors management
	{
		printf("Error creating the renderer : %s", SDL_GetError());
		return NULL;
	}

	return p_manager;
}

void SDL_Manager_FREE(sdl_manager* p_manager)
{
    SDL_DestroyRenderer(p_manager->pRenderer);
    SDL_DestroyTexture(p_manager->pTexture);
    SDL_DestroyWindow(p_manager->pWindow);
    SDL_FreeSurface(p_manager->pSurface);
}

void SDL_ManagerRend(sdl_manager* p_manager)
{
    //Fonction de rendu complète
    p_manager->pTexture = SDL_CreateTextureFromSurface(p_manager->pRenderer, p_manager->pSurface);
    SDL_SetRenderTarget(p_manager->pRenderer, p_manager->pTexture);
    SDL_RenderCopy(p_manager->pRenderer, p_manager->pTexture, NULL, NULL);
    SDL_RenderPresent(p_manager->pRenderer);
    SDL_RenderClear(p_manager->pRenderer);
}
