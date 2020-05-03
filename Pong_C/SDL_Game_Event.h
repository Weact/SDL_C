#ifndef SDL_GAME_EVENT_H_INCLUDED
#define SDL_GAME_EVENT_H_INCLUDED

#include "../SDL2/SDL.h"
#include "player_platform.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum InputManager{
    UP_p1 = SDLK_z,
    DOWN_p1 = SDLK_s,

    UP_p2 = SDLK_UP,
    DOWN_p2 = SDLK_DOWN,

    CANCEL = SDLK_ESCAPE,
    CONFIRM = SDLK_RETURN
}InputManager;

int event_handling(pl_platform * p_player1, pl_platform * p_player2, int speed);
int wait_event();
void end_game();

#endif // SDL_GAME_EVENT_H_INCLUDED
