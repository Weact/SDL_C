# SDL_C
GITHUB Repository for every future projects in SDL C / C++

# WHAT_IS_THIS - Started on Monday 10 February 2020.
### Supervisor : LEHMANN Nicolas (https://github.com/nglconsulting)
### Student : DRUCKES Lucas (https://github.com/Weact)
#### SDL - C

# Questions Part

## Q.1
### What is SDL 2 ? (10 pts)
SDL2 *Simple DirectMedia Layer 2*, is a library under *zlib* license.
It means SDL2 is an open-source library which can be modified for free and commercialized. SDL2 is also useful for game development, obviously.


## Q.2
### What does SDL 2 do ? (10 pts)
As mentioned previously, SDL2 can allows its users to create games, applications  etc.
*Exemple :*
* Text editor
* Calculator
* Spreadsheat
* 2D Games
* [...]

## Q.3
### On what platform can we use SDL 2 ? (10 pts)
We can use SDL2 on Windows, MAC OSX and Linux.

## Q.4
### How to get and How to install SDL 2 on an Editor ? (10 pts)
#### Give each configuration step of a SDL 2 project with CodeBlocks (gcc)
1. Go to https://www.libsdl.org/download-2.0.php and download _SDL2-devel-2.0.10-mingw.tar.gz_ folder.
2. Extract the _i686-w64-mingw32_ folder on your desktop.
3. Copy the *SDL2* folder in _i686-w64-mingw32/include/_ in your project's folder.
	3. For exemple in this project, we have 4 cores folders :
		3. SDL2/ *SDL2 include library*
		3. WhatIsThis/ *.c and .h files*
		3. .gitignore *list of folders not to git*
		3. README.md *this file*
4. After copying the folder, open Code::Blocks.
5. Create a C Console Application project.
6. Click on Project
	6. Build properties
		6.Verify that you are in Debug on the left side of the new window that appeared.
	6. Linker settings
	6. __On Link libraries__ :
		6. Add
			6. Search for the _CodeBlcoks/MinGW/lib/libmingw32.a_ folder and click on OK
			6. Search for the _i686-w64-mingw32/lib/libSDL2main.a_ folder and click on OK
			6. Do the same for _i686-w64-mungw32/lib/libSDL2.dll.a_ folder and click on OK
	6. On __Other Linker Options__ :
		6. Write :
			6. -lmingw32
			6. -lSDL2main
			6. -lSDL2
	6. Go to Search Directories
	6. __On Compiler__
		6. Add
			6. Search for the _i686-w64-mingw32/include/_ folder and click on OK
	6. __On Linker__
		6. Add
			6. Search for the _i686-w64-mingw32/lib/_ folder and click on OK
7. Now that everything have been done, you can successfully include the SDL.h to your projects by using the following line code :
```c
#include <SDL2/SDL.h>
//or
#include "../SDL2/SDL.h"
//According to where your SDL.h is
```
		

## Q.5
### What are the differences between SDL 1 and SDL 2 ? (5 pts)
| __SDL1__                	| __SDL2__                            	|
|--------------------------	|---------------------------------	|
|                          	|                                 	|
|                          	| 3D Hardware Acceleration        	|
| OpenGL API 2-            	| OpenGL 3.0+ / OpenGL ES Support 	|
| No Android + iOs Support 	| Android + iOS Support           	|
|                          	| Better Fullscreen Support       	|
| LGPL license             	| zlib license                    	|
| 8/16 Bits  audio         	| 32 Bits audio                   	|
| Works on CPU             	| __Works on GPU__                    	|
|                          	| Performance has been improved   	|

## Q.6
### To use SDL 2 in your project, you have to initialize SDL 2.
#### What are these initializion steps to use SDL 2 library ? Give the code and explain each instructions with precision. (15 pts)
```c
//First, we have to include SDL2 library as following :
#include "SDL2/SDL.h"	//Replace the given path by your SDL location.
			//Exemple: If your SDL2 folder is located 2 folder before your projects, it should looks like this :
			//#include <../../SDL2/SDL.h> => the ../ redirect to the parent folder.

int main(int arc, char *argv[]) //We obviously need the main in our program.
{

//Secondly, we have now to *initialize* SDL2 by doing this way:

	if(SDL_Init(SDL_INIT_VIDEO) < 0) 	//SDL_Init initialize SDL Library.
						//Then we check if video subsystem events have been successfully initialized by
						//comparing SDL_INIT_VIDEO.
	{
		printf("Error initializing SDL : %s", SDL_GetError()); 	//Video events could not be initialized. We display it to the 										//user and display the ERROR Code
		return EXIT_FAILURE;
	}
	//If your program can now run without any message and the console and instantly close. SDL has been successfully initialized.
	//Congratulation !
	
	SDL_Quit();
	return 0;
}
```

## Q.7
### How to create a window with SDL 2 ? (10 pts)
#### Give and explain the code to do so.
__/!\ For this question, I decided to give the whole code of creating a window, destroying it and managing errors at the same time.
I also used SDL_Delay method that will be explained later in the document. /!\__
```c
#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0) // SDL init
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	
	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
	// resizable 1280x720 centered window creation
	
	if(window == NULL) //errors management
	{
		printf("Error creating the window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	
	SDL_Delay(1000); //1s break, so the window opens and doesn't close instantly. This method will be explained later.
	
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
```

## Q.8
### Management of a SDL 2 Window; Give the SDL 2 Window's primitives. (10 pts)
| SDL2 Window 	| Functions                                                                                                                 	| __GET Functions__         	| __SET Functions__         	|
|-------------	|---------------------------------------------------------------------------------------------------------------------------	|---------------------------	|---------------------------	|
|             	| SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)                                 	| SDL_GetWindowBordersSize  	| SDL_SetWindowBordered     	|
|             	| int SDL_CreateWindowAndRenderer(int width, int height, Uint32 window_flags, SDL_Window** window, SDL_Renderer** renderer) 	| SDL_GetWindowBrightness   	| SDL_SetWindowBrightness   	|
|             	| void SDL_DestroyWindow(SDL_Window* window)                                                                                	| SDL_GetWindowData         	| SDL_SetWindowData         	|
|             	|                                                                                                                           	| SDL_GetWindowDisplayIndex 	| SDL_SetWindowDisplayMode  	|
|             	|                                                                                                                           	| SDL_GetWindowDisplayMode  	| SDL_SetWindowFullscreen   	|
|             	|                                                                                                                           	| SDL_GetWindowFlags        	| SDL_SetWindowGammaRamp    	|
|             	|                                                                                                                           	| SDL_GetWindowFromID       	| SDL_SetWindowGrab         	|
|             	|                                                                                                                           	| SDL_GetWindowGammaRamp    	| SDL_SetWindowHitTest      	|
|             	|                                                                                                                           	| SDL_GetWindowGrab         	| SDL_SetWindowIcon         	|
|             	|                                                                                                                           	| SDL_GetWindowID           	| SDL_SetWindowInputFocus   	|
|             	|                                                                                                                           	| SDL_GetWindowMaximumSize  	| SDL_SetWindowMaximumSize  	|
|             	|                                                                                                                           	| SDL_GetWindowMinimumSize  	| SDL_SetWindowMinimumSize  	|
|             	|                                                                                                                           	| SDL_GetWindowOpacity      	| SDL_SetWindowModalFor     	|
|             	|                                                                                                                           	| SDL_GetWindowPixelFormat  	| SDL_SetWindowOpacity      	|
|             	|                                                                                                                           	| SDL_GetWindowPosition     	| SDL_SetWindowPosition     	|
|             	|                                                                                                                           	| SDL_GetWindowSize         	| SDL_SetWindowResizable    	|
|             	|                                                                                                                           	| SDL_GetWindowSurface      	| SDL_SetWindowSize         	|
|             	|                                                                                                                           	| SDL_GetWindowTitle        	| SDL_SetWindowTitle        	|
|             	|                                                                                                                           	| SDL_GetWindowWMInfo       	| SDL_SetWindowsMessageHook 	|

## Q.9
### Renderer: (15 pts)
#### What are a Renderer ? How is it associated to a SDL 2 Window ?
#### Give and explain the corresponding code to manage a Renderer, Creation, Display and Deletion.
* A renderer is a _Render Engine_ used for our windows.
	* Code and Explanation :

```c
#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration
	SDL_Renderer* renderer; //NEW LINE ! => This is how we declare the renderer.
	
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
	
	//Then clear the window by using SDL_RenderClear function
	SDL_RenderClear(renderer);
	
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
```

## Q.10
### SDL_Point and SDL_Rect : (5 pts)
#### Give and explain the code of SDL_Point and SDL_Rect
_SDL_Point_ :
```c
#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
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

	//We have now to display our render using SDL_RenderPresent function
	SDL_RenderPresent(renderer);

	SDL_Delay(3000); //3s break, so the window opens and doesn't close instantly. This method will be explained later.

	SDL_DestroyRenderer(renderer); //Destroy the renderer
	SDL_DestroyWindow(window); //Destroy the window
	SDL_Quit();
	return 0;
}
```
_SDL_Rect_ :
```c
typedef struct{
	Sint16 x, y;
	Sint16 w, h;
}SDL_Rect;

//Creating a rect :
SDL_Rect rectangle = {0,0,100,100};

```
## Q.11
### Colors with SDL 2 : (? pts)
#### Give the instructions to allow the color management in SDL 2.
```c
SDL_Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
//red, green, blue, alpha values for the color
```

## Q.12
### Give the code to display a red background. (? pts)
```c
#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	SDL_Window* window; //Window declaration
	SDL_Renderer* renderer; //Renderer declaration
	
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
	SDL_SetRenderDrawColor(renderer, 255,0,0,255);
	
	//Then clear the window by using SDL_RenderClear function
	SDL_RenderClear(renderer);
	
	//We have now to display our render using SDL_RenderPresent function
	SDL_RenderPresent(renderer);
	
	SDL_Delay(3000); //3s break, so the window opens and doesn't close instantly. This method will be explained later.
	
	SDL_DestroyRenderer(renderer); //Destroy the renderer
	SDL_DestroyWindow(window); //Destroy the window
	SDL_Quit();
	return 0;
	
	//This will display a red window, wait 3s and close.
}
```

## Q.13
### Draw in the renderer : (? pts)
#### Give the functions and their appropriated code to draw the shape renderer shown below (cf. PDF screenshot).
```c
#include <math.h>

int main(int argc, char* argv[])
{
	DrawCircle(renderer, 150, 300, 150); //Empty circle
    	DrawFilledCircle(renderer, 500, 300, 150); //Filled Circle
}
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
```

## Q.14
### What are the functions to draw dots and lines ?(10 pts)
As mentionned previously, those functions allow us to draw dots and lines :
```c
//Dots:
SDL_RenderDrawPoint(renderer, 100, 100);
```

## Q.15
### What is the point of SDL_RenderClear and SDL_RenderPresent functions ? (5 pts)
* SDL_RenderClear
	* This function is used to clear the current rendering target with the drawing color
* SDL_RenderPresent
	* This function is used to update the screen with any rendering performed since the previous call.

## Q.16
### Explain SDL_Delay ? (5 pts)
SDL_Delay makes the program waiting a specified number of milliseconds before returning.

## Q.17
### What is a surface in SDL 2 ? (5 pts)
A surface is a structure that contains a collection of pixels used in software blitting.

## Q.18
### Give the code to create a surface. (10 pts)
```c
SDL_Surface* surface;

surface = SDL_CreateRGBSurface (0, 100, 100, 32, 0, 0, 0, 0);

if(surface == NULL)
{
    printf("Error creating a surface : %s", SDL_GetError());
    return EXIT_FAILURE;
}
```

## Q.19
### Draw in a surface: (10 pts)
#### Give the function code of SDL_FillRect
```c
int SDL_FillRect(SDL_Surface* dst, const SDL_Rect* rect, Uint32 color)
```

## Q.20
### SDL_BlitSurface(..) : (5 pts)
#### Give the code to test this method
```c
int SDL_BlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect)
```

## Q.21
### Textures : (10 pts)
### What is a texture ?
#### Give the code allowing to create a texture
A texture is a structure that contains an efficient, driver-specific representation of pixel data.
```c
SDL_Texture *texture;

texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);
```

## Q.22
### Draw in a texture : SDL_RenderTarget (10 pts)
#### Give the code to test this method


## Q.23
### SDL_RenderCopy : (10 pts)
#### What is the point of this method ?
#### Give the code to test this method
SDL_RenderCopy is a function which copy a portion of a texture to the current rendering.
```c
int SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
```

## Q.24
### SDL_QueryTexture : (10 pts)
#### What is the point of this method ?
#### Give the code to test this method
SDL_QueryTexture is a function which query the attributes of a texture.
```c
int SDL_QueryTexture(SDL_Texture* texture, Uint32* format, int* access, int* w, int* h);
```

## Q.25
### Images : (10 pts)
#### SDL 2 only natively take bmp format, if you wish to use other format, you have to associate the corresponding library SDL2_image to your project.
#### SDL_LoadBMP is the method allowing to use bmp.
#### Give the code allowing to test this function

## Q.26
### Give the code allowing to create an image from a bmp image (10 pts)


## Q.27
### Take an image of your choice in bmp format and test the previous functions with the code allowing to display the image in the Renderer. (15 pts)


## Q.28
### Since the beginning, we are creating instances allowing use to manipulate SDL 2. However, we forgot an important step in its usage : **Instance Destructions**. (15 pts)
#### Make a statements of the previous created instances and identify the methodes you have to use to destroy them.
```c
SDL_DestroySurface(surface);
SDL_DestroyTexture(texture);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
```

## Q.29
```c

typedef struct sdl_manager{
	SDL_Window *pWindow;
	SDL_Renderer *pRenderer;
	SDL_Texture *pTexture;
	SDL_Surface *pSurface;
}

````
You have coded your program, functions and procedures so that you can test more precisely all methods. With the aid of the structured type written above, I ask you to improve your program and to make a more structured program with modular programmation and patterns (MVC) than the previous version
# 30 POINTS
