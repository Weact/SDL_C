# SDL_C
GITHUB Repository for every future projects in SDL C / C++. 

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
__LAPTOP REQUIRED FOR THIS QUESTION__

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
__LAPTOP REQUIRED FOR THIS QUESTION__

## Q.7
### How to create a window with SDL 2 ? (10 pts)
#### Give and explain the code to do so.
__/!\ For this question, I decided to give the whole code of creating a window, destroying it and managing errors at the same time.
I also used SDL_Delay method that will be explained later in the document. /!\__
```c
#include <SDL2/SDL.h>
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
	
	window = SDL_CreateWindow("A SDL Window"); // window creation
	
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


## Q.10
### SDL_Point and SDL_Rect : (5 pts)
#### Give and explain the code of SDL_Point and SDL_Rect


## Q.11
### Colors with SDL 2 : (? pts)
#### Give the instructions to allow the color management in SDL 2.


## Q.12
### Give the code to display a red square. (? pts)


## Q.13
### Draw in the renderer : (? pts)
#### Give the functions and their appropriated code to draw the shape renderer shown below (cf. PDF screenshot).


## Q.14
### What are the functions to draw dots and lines ?(10 pts)


## Q.15
### What is the point of SDL_RenderClear and SDL_RenderPresent functions ? (5 pts)


## Q.16
### Explain SDL_Delay ? (5 pts)


## Q.17
### What is a surface in SDL 2 ? (5 pts)


## Q.18
### Give the code to create a surface. (10 pts)


## Q.19
### Draw in a surface: (10 pts)
#### Give the function code of SDL_FillRect


## Q.20
### SDL_BlitSurface(..) : (5 pts)
#### Give the code to test this method


## Q.21
### Textures : (10 pts)
### What is a texture ?
#### Give the code allowing to create a texture


## Q.22
### Draw in a texture : SDL_RenderTarget (10 pts)
#### Give the code to test this method


## Q.23
### SDL_RenderCopy : (10 pts)
#### What is the point of this method ?
#### Give the code to test this method

## Q.24
### SDL_QueryTexture : (10 pts)
#### What is the point of this method ?
#### Give the code to test this method

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
