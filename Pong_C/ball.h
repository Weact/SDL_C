#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ball{
    double origin_x;
    double origin_y;
    int radius;
    double speed;
    SDL_Color ball_color;
}ball;

    //BALL CREATION
ball * new_ball(double origin_x, double origin_y, int radius, double speed, SDL_Color color);

    //BALL MOVEMENTS
void move_ball(ball * ball_to_move, double speed_x, double speed_y);

    //PLAYER DISPLAYER
void display_ball(ball * target);

//GLOBALS

    // SETTERS
void set_ball_origin_x(ball * target, double new_ball_x);
void set_ball_origin_y(ball * target, double new_ball_y);
void set_ball_speed(ball * target, double new_ball_speed);
void set_ball_radius(ball * target, int new_ball_radius);

    //GETTERS
double get_ball_x(ball * target);
double get_ball_y(ball * target);
double get_ball_speed(ball * target);
int get_ball_radius(ball * target);

//COLORS

    //SETTERS
void set_ball_color(ball * target, SDL_Color new_ball_color);

    //GETTERS
SDL_Color get_ball_color(ball * target);

#endif // CIRCLE_H_INCLUDED
