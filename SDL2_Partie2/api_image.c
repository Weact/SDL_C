#include "api_image.h"
#include "sdl_manager.h"

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

SDL_Surface* img_surface(sdl_manager* p_manager, const char* img_path)
{

    p_manager->pSurface = IMG_Load(img_path);
    if(p_manager->pSurface == NULL){
        printf("Image non reconnu");
    }
}
