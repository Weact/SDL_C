# SDL_C
REPOSITORY GITHUB POUR PROJECTS C/C++

# SDL2 PARTIE 2 - Commencé le Lundi 06 Avril 2020
### Superviseur du Projet : LEHMANN Nicolas (https://github.com/nglconsulting)
### Étudiant : DRUCKES Lucas (https://github.com/Weact)
#### SDL - C - PARTIE 2

# Partie Question

## Q.1
Quel Api faut-il ajouter à votre projet de développement afin de pouvoir prendre en charge les images au format (JPG, PNG….), que fait cet API?
10 points

SDL2_image est l'API qu'il faut ajouter pour pouvoir prendre en charge les images au format JPG, PNG...
Cette API convertit les .jpg et .png en .bmp car la SDL ne prend en charge uniquement les .bmp (bitmap), d'où la conversion par l'api.

## Q.2
Donnez les étapes de configuration pour l’utilisation de ce nouvel API.
10 points
Afin de configurer correctement l'API, nous avons d'abord besoin de télécharger l'API à l'adresse suivante : https://www.libsdl.org/projects/SDL_image/
1. SDL2_image-devel-2.0.5-mingw.taz.gz (MinGW 32/64-bit)
Puis extraire le contenu de *lib*, *include* ainsi que les dll à l'intérieur de *bin*.
Ainsi, nous pouvons maintenant inclure l'api SDL2_image dans notre projet codeblocks de cette manière : `#include "../SDL2/SDL2_image.h"`.
C'est comme cela que je l'ai déclaré dans mon projet.
La manière d'inclure l'API dépend évidemment de la localisation de votre SDL2_image.h .
## Important : Ne pas oublier de rajouter -lSDL2_image dans Project>Build Options>Linker Settings

## Q.3
Donnez un exemple de code en c chargeant une image au format png dans la fenêtre (image de votre choix). Commentez et expliquez ce code.
10 points

#### main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include "sdl_manager.h"

int main(int argc, char * argv[])
{
    printf("Hello world!\n");
    if(SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    sdl_manager * p_myManager = SDL_Manager_INIT(); //Initialisation du SDL_Manager, donc de la fenêtre, du renderer, texture et surface

    img_surface(p_myManager, "sdllogo.png"); //Chargement de l'image .png et conversion en .bmp pour l'affichage

    SDL_ManagerRend(p_myManager); //Fonction de rendu complet
    SDL_Delay(2500); // Attente 2.5s
    SDL_Manager_FREE(p_myManager); //Détruit tout
    return 0;
}
```

#### sdl_manager.c
```c
#include "sdl_manager.h"

sdl_manager * SDL_Manager_INIT()
{
    int format = 0;
    int access = 0;
    int width = 1280;
    int height = 720;
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
```
#### sdl_manager.h
```c
#ifndef SDL_MANAGER_H_INCLUDED
#define SDL_MANAGER_H_INCLUDED

#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
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
```
#### api_image.c
```c
#include "api_image.h"
#include "sdl_manager.h"

//Cette fonction est celle qui nous intéresse pour charger une image en se servant de l'api SDL2_image
SDL_Surface* img_surface(sdl_manager* p_manager, const char* img_path)
{
    //On se sert de IMG_Load() afin de charger l'image .png/.jpg/[...] afin de l'afficher avec un rendu plus tard
    p_manager->pSurface = IMG_Load(img_path);
    if(p_manager->pSurface == NULL){
        printf("Image non reconnu");
    }
}
```
#### api_image.h
```c
#ifndef BMP_IMAGE_H_INCLUDED
#define BMP_IMAGE_H_INCLUDED

#include "../SDL2/SDL.h"
#include "../SDL2/SDL_image.h"
#include "sdl_manager.h"
#include <stdio.h>
#include <stdlib.h>

int bmp_surface(SDL_Renderer* renderer, SDL_Surface* surface, SDL_Texture* texture, int format, int access, int width, int height, const char* bmp_path);
SDL_Surface* img_surface(sdl_manager* p_manager, const char* img_path);

#endif // BMP_IMAGE_H_INCLUDED
```
