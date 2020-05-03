#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "../SDL2/SDL.h"
#include "player_platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum dir {LEFTUP = 1, RIGHTUP = 2, LEFTDOWN = 3, RIGHTDOWN = 4}dir;
typedef enum side {LEFT = 1, RIGHT = 2} side;
typedef struct ball{
    double origin_x;
    double origin_y;
    int radius;
    double speed;
    SDL_Color ball_color;

    dir direction;
    side ball_side;
}ball;

    //BALL CREATION
ball * new_ball(double origin_x, double origin_y, int radius, double speed, SDL_Color color, dir direction);

    //BALL MOVEMENTS
void move_ball(ball * ball_to_move, double speed_x, double speed_y);
void ball_bounce(ball * ball_to_bounce, pl_platform * p_player1, pl_platform * p_player2);
    //PLAYER DISPLAYER
void display_ball(ball * target);

//GLOBALS

    // SETTERS
void set_ball_origin_x(ball * target, double new_ball_x);
void set_ball_origin_y(ball * target, double new_ball_y);
void set_ball_speed(ball * target, double new_ball_speed);
void set_ball_radius(ball * target, int new_ball_radius);
void set_ball_direction(ball * target, int new_ball_direction);
void set_ball_side(ball * target, int new_ball_side);

    //GETTERS
double get_ball_x(ball * target);
double get_ball_y(ball * target);
double get_ball_speed(ball * target);
int get_ball_radius(ball * target);
dir get_ball_direction(ball * target);
side get_ball_side(ball * target);

//COLORS

    //SETTERS
void set_ball_color(ball * target, SDL_Color new_ball_color);

    //GETTERS
SDL_Color get_ball_color(ball * target);

#endif // CIRCLE_H_INCLUDED
