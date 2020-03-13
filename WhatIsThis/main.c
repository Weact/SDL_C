#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Want to merge, pls..
int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration
	SDL_Renderer* renderer; //Renderer declaration
    SDL_Surface* surface = SDL_CreateRGBSurface(0, 100, 100, 32, 0, 0, 0, 0);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,100);

    SDL_Rect rect = {100,100,100,100};
    SDL_Rect rect2 = {300, 300, 600, 600};

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // SDL init
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);

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

	//Red color
   	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
   	SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, texture);
    SDL_RenderDrawLine(renderer, 0, 0, 250, 25);
    SDL_SetRenderTarget(renderer, NULL);

    SDL_Rect t_Position;
    t_Position.x = 100;
    t_Position.y = 200;
    SDL_QueryTexture(texture, NULL, NULL, &t_Position.w, &t_Position.h);
    SDL_RenderCopy(renderer, texture, NULL, &t_Position);

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 255, 0, 0));
    SDL_RenderFillRect(renderer, &rect2);
	DrawCircle(renderer, 150, 300, 150);
    DrawFilledCircle(renderer, 500, 300, 150);

	//We have now to display our render using SDL_RenderPresent function
	SDL_RenderPresent(renderer);

	SDL_Delay(3000); //3s break, so the window opens and doesn't close instantly. This method will be explained later.

	SDL_DestroyRenderer(renderer); //Destroy the renderer
	SDL_DestroyWindow(window); //Destroy the window
	SDL_Quit();
	return 0;

	//This will display a red window, wait 3s and close.
}

// Dessine le cercle donn�
void DrawCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    int new_x = 0;
    int new_y = 0;
    int old_x =  origin_x + radius;
    int old_y = origin_y;
    float step = (M_PI * 2) / 50;

    SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, 255);

    for(float theta = 0; theta <= (M_PI * 2); theta += step){
        new_x = origin_x + (radius * cos(theta));
        new_y = origin_y - (radius * sin(theta));

        SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);

        old_x = new_x;
        old_y = new_y;
    }

    new_x = origin_x + radius;
    new_y = origin_y;
    SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);

}
// Dessine le cercle donn�, rempli
void DrawFilledCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    for(double dy = 1; dy <= radius; dy += 1.0){

        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));

        SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y + dy - radius, origin_x + dx, origin_y + dy - radius);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y - dy + radius, origin_x + dx, origin_y - dy + radius);

    }
}
