#include <stdio.h>
#include <stdlib.h>

//First, we have to include SDL2 library as following :
#include "../SDL2/SDL.h"	//Replace the given path by your SDL location.
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
