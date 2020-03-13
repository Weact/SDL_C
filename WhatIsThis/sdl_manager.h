#ifndef SDL_MANAGER_H_INCLUDED
#define SDL_MANAGER_H_INCLUDED

typedef struct sdl_manager{
	SDL_Window *pWindow;
	SDL_Renderer *pRenderer;
	SDL_Texture *pTexture;
	SDL_Surface *p_RGB_Surface;
	SDL_Surface *p_BMP_Surface;
}sdl_manager;

#endif // SDL_MANAGER_H_INCLUDED
