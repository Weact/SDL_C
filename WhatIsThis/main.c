#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration
	SDL_Renderer* renderer; //NEW LINE ! => This is how we declare the renderer.
	SDL_Rect rect = {100, 100, 200, 200};

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // SDL init
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
	//NEW LINE ! => Here, we create a new window using the following parameters:
	//Title, X position, Y position, Width, Height, Flag.
	// SDL_WINDOWPOS_CENTERED as X and Y position will make the window appearing at the center of the screen.
	// 1280 x 720 will be the size of our window.
	// SDL_WIDNDOW_RESIZABLE will allow the user to resize the window as he wishes.

	if(window == NULL) //errors management
	{
		printf("Error creating the window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	//RENDERER CREATION
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//NEW LINE! => We create the Renderer of the Window using 3 parameters :
	//Window where rendering is displayed
	//SDL_RENDERER_ACCELERATED to use hardware acceleration

	if(renderer == NULL) //errors management
	{
		printf("Error creating the renderer : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	//To test the renderer, we will want to display something in our window.
	//First, Select a color by using the following function :
	SDL_SetRenderDrawColor(renderer, 255,0,255,255);
			//PARAMETERS: renderer, red, green, blue, alpha (0>255)

    //Here, we are going to create a table that have 10 points.
    SDL_Point points[500];
    for(int i = 0; i<499; i++)
    {
        points[i].x = i+4;
        points[i].y = 500;
        //This for loop will initialize the x and y position of the points in our table named points.
    }

	//Then clear the window by using SDL_RenderClear function
	//SDL_RenderClear(renderer); We make this as commentary so it will display a purple line.

    //We can also draw a line using SDL_RenderDrawLine function, this way :
    //	SDL_RenderDrawLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2);
    //EX:	SDL_RenderDrawLine(renderer, 100, 100, 300, 300);
    SDL_RenderDrawPoints(renderer, points, 500); //Initialize and create the points on the screen
    SDL_RenderDrawLine(renderer, 200, 200, 500, 500); //Draw a line

	//We have now to display our render using SDL_RenderPresent function
	SDL_RenderPresent(renderer);

	//We can also create a renderer and a window at the same time this way :
	/*
			// PARAMETERS : width, height, flag, &window, &renderer
	if(SDL_CreateWindowAndRenderer(1280,720, SDL_WINDOW_RESIZABLE,&window,&renderer) < 0)
	{
		printf("Error creating renderer and window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	*/

	SDL_Delay(3000); //3s break, so the window opens and doesn't close instantly. This method will be explained later.

	SDL_DestroyRenderer(renderer); //Destroy the renderer
	SDL_DestroyWindow(window); //Destroy the window
	SDL_Quit();
	return 0;
}
