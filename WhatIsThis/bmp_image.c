#include "bmp_image.h"

int bmp_surface(SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture, int format, int access, int width, int height, const char* bmp_path)
{
    surface = SDL_LoadBMP(bmp_path);
    if(surface == NULL){
        printf("Image non reconnu");
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(SDL_QueryTexture(texture, &format, &access, &width, &height) != 0){
        printf("Erreur");
        return EXIT_FAILURE;
    }else{
        printf("Texture Width: %d / Texture Height: %d", width, height);
    }

    //We have now to display our render using SDL_RenderPresent function
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}
