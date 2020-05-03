#include <stdio.h>
#include <stdlib.h>
#include "../SDL2/SDL.h"
#include "SDL_Manager.h"
#include "player_platform.h"
#include "ball.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != EXIT_SUCCESS)
    {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }else{
        printf("SDL2 Initialized\n");
    }

    //GAME IS RUNNING
    int running = TRUE;

    //SDL Manager Creation and Initialization
    sdl_manager * p_manager = SDL_Manager_INIT();

    //SDL Manager Display Properties
        //incoming

    //Colors Declaration
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color blue = {0, 0, 255, 255};
    SDL_Color red = {255, 0, 0, 255};

    //Declaration of Players and Creation
    pl_platform * p_player1 = new_player(10, 512/2, 10, 100, 64, blue);
    pl_platform * p_player2 = new_player(1004, 512/2, 10, 100, 64, red);

    //Players Infos Displayer [DEBUG]
    display_player(p_player1);
    display_player(p_player2);

    //Declaration of the Ball and Creation
    ball * p_ball = new_ball(1024/2, 512/2, 10, 10, white, RIGHTUP);

    //Ball Infos Displayer [DEBUG]
    display_ball(p_ball);
    while(running){
        //Background To Black
        SDL_SetRenderDrawColor(p_manager->pRenderer, black.r, black.g, black.b, black.a);

        //SDL Renderer Clear
        SDL_RenderClear(p_manager->pRenderer);

        //Display Players On Screen
        SDL_SetRenderDrawColor(p_manager->pRenderer, blue.r, blue.g, blue.b, blue.a);
        SDL_RenderFillRect(p_manager->pRenderer, p_player1->p_player_dimension);
        SDL_SetRenderDrawColor(p_manager->pRenderer, red.r, red.g, red.g, red.r);
        SDL_RenderFillRect(p_manager->pRenderer, p_player2->p_player_dimension);

        //Display Ball On Screen
        DrawFilledCircle(p_manager->pRenderer, p_ball->origin_x, p_ball->origin_y, p_ball->radius, p_ball->ball_color);

        //Make the Renderer
        SDL_RenderPresent(p_manager->pRenderer);
        running = event_handling(p_player1, p_player2);
        move_ball(p_ball, 0.1, 0.1);
        ball_bounce(p_ball, p_player1, p_player2);
    }

    SDL_Manager_FREE(p_manager); //Destroy SDL Manager
    end_game();
    return 0; //return
}
