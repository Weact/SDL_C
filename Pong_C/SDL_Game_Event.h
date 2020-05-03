#ifndef SDL_GAME_EVENT_H_INCLUDED
#define SDL_GAME_EVENT_H_INCLUDED

#include "../SDL2/SDL.h"
#include "player_platform.h"
#include <stdio.h>
#include <stdlib.h>

int event_handling(pl_platform * p_player1, pl_platform * p_player2, int speed);
void end_game();

#endif // SDL_GAME_EVENT_H_INCLUDED