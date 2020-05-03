#ifndef PLAYER_PLATFORM_H_INCLUDED
#define PLAYER_PLATFORM_H_INCLUDED

#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pl_platform{
    int player_speed;
    SDL_Rect * p_player_dimension;
    SDL_Color player_color;
}pl_platform;

//METHODS

    //PLAYER CREATION
pl_platform * new_player(int player_x, int player_y, int player_w, int player_h, int player_speed, SDL_Color player_color);

    //PLAYER DISPLAYER
void display_player(pl_platform * target);

    //PLAYER MOVEMENT
int move_player(pl_platform * player_to_move, int speed);

//GLOBALS

    // SETTERS
void set_player_x(pl_platform * target, int new_player_x);
void set_player_y(pl_platform * target, int new_player_y);
void set_player_w(pl_platform * target, int new_player_w);
void set_player_h(pl_platform * target, int new_player_h);
void set_player_speed(pl_platform * target, int new_player_speed);

    //GETTERS
int get_player_x(pl_platform * target);
int get_player_y(pl_platform * target);
int get_player_w(pl_platform * target);
int get_player_h(pl_platform * target);
int get_player_speed(pl_platform * target);

//COLORS

    //SETTERS
void set_player_color(pl_platform * target, SDL_Color new_player_color);

    //GETTERS
SDL_Color get_player_color(pl_platform * target);

#endif // PLAYER_PLATFORM_H_INCLUDED
