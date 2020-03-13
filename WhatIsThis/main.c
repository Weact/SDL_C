#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration
	SDL_Renderer* renderer; //Renderer declaration
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,100); //Create basic texture

    SDL_Rect rect = {100,100,100,100}; //Create rect x100 y100 w100 h100
    SDL_Rect rect2 = {300, 300, 600, 600}; //Create rect x300 y300 w600 h600

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // SDL init
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE); //Create window

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



    //Create two surface: source and destination
    SDL_Surface* f = SDL_CreateRGBSurface(0, 1280, 720, 32, 0, 0, 0, 0);
    SDL_Surface* dst_surface = SDL_CreateRGBSurface(0, 1280, 720, 32, 0, 0, 0,0);
    const char* godotimage = "Vierbit4.bmp";
    SDL_Surface* src_surface = SDL_LoadBMP(godotimage);
    if(src_surface == NULL){
        printf("Image non reconnu");
    }
	//Red color
   	//SDL_SetRenderDrawColor(renderer, 255,0,0,255); //Set background to white

   	//SDL_FillRect(src_surface, &rect, SDL_MapRGB(src_surface->format, 255, 0, 255)); //Fill a rectangle on a surface
   	SDL_BlitSurface(src_surface, NULL, dst_surface, NULL);
    SDL_Texture* text_surface = SDL_CreateTextureFromSurface(renderer, src_surface);
   	//SDL_RenderClear(renderer); //Clear the renderer

    int format = 0;
    int access = 0;
    int width = 0;
    int height = 0;

    if(SDL_QueryTexture(text_surface, &format, &access, &width, &height) != 0){
        return EXIT_FAILURE;
    }else{
        printf("Texture Width: %d / Texture Height: %d", width, height);
    }

	//We have now to display our render using SDL_RenderPresent function
	SDL_SetRenderTarget(renderer, text_surface);
	SDL_RenderCopy(renderer, text_surface, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000); //3s break, so the window opens and doesn't close instantly. This method will be explained later.

	SDL_DestroyRenderer(renderer); //Destroy the renderer
	SDL_DestroyWindow(window); //Destroy the window
	SDL_Quit();
	return 0;

	//This will display a red window, wait 3s and close.
}

// Dessine le cercle donné
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
// Dessine le cercle donné, rempli
void DrawFilledCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    for(double dy = 1; dy <= radius; dy += 1.0){

        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));

        SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y + dy - radius, origin_x + dx, origin_y + dy - radius);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y - dy + radius, origin_x + dx, origin_y - dy + radius);

    }
}
