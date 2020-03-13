#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

SDL_Surface* bmp_surface(SDL_Renderer* renderer)
{
    const char* godotimage = "Vierbit4.bmp";
    SDL_Surface* pSurface = SDL_LoadBMP(godotimage);
    if(pSurface == NULL){
        printf("Image non reconnu");
    }

    SDL_Texture* text_surface = SDL_CreateTextureFromSurface(renderer, pSurface);

    int format = 0;
    int access = 0;
    int width = 0;
    int height = 0;

    if(SDL_QueryTexture(text_surface, &format, &access, &width, &height) != 0){
        printf("Erreur");
    }else{
        printf("Texture Width: %d / Texture Height: %d", width, height);
    }

    //We have now to display our render using SDL_RenderPresent function
	SDL_SetRenderTarget(renderer, text_surface);
	SDL_RenderCopy(renderer, text_surface, NULL, NULL);
}
