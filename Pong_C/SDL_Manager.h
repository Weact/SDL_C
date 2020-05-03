#ifndef SDL_MANAGER_H_INCLUDED
#define SDL_MANAGER_H_INCLUDED

#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct sdl_manager{
	SDL_Window *pWindow;
	SDL_Renderer *pRenderer;
	SDL_Texture *pTexture;
	SDL_Surface *pSurface;
}sdl_manager;

sdl_manager * SDL_Manager_INIT();
void SDL_Manager_FREE(sdl_manager* p_manager);
void SDL_ManagerRend(sdl_manager* p_manager);

#endif // SDL_MANAGER_H_INCLUDED
