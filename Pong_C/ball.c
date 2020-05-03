#include "ball.h"

ball * new_ball(double origin_x, double origin_y, int radius, double speed, SDL_Color color){
    ball * game_ball = malloc(sizeof(ball));

    set_ball_origin_x(game_ball, origin_x);
    set_ball_origin_y(game_ball, origin_y);
    set_ball_speed(game_ball, speed);
    set_ball_radius(game_ball, radius);
    set_ball_color(game_ball, color);

    return game_ball;
}

void move_ball(ball * ball_to_move, double speed_x, double speed_y){
    ball_to_move->origin_x += speed_x;
    ball_to_move->origin_y += speed_y;
}

    //PLAYER SETTERS
void set_ball_origin_x(ball * target, double new_ball_x){
    target->origin_x = new_ball_x;
}
void set_ball_origin_y(ball * target, double new_ball_y){
    target->origin_y = new_ball_y;
}
void set_ball_speed(ball * target, double new_ball_speed){
    target->speed = new_ball_speed;
}
void set_ball_radius(ball * target, int new_ball_radius){
    target->radius = new_ball_radius;
}
    //BALL GETTERS
double get_ball_x(ball * target){
    return target->origin_x;
}
double get_ball_y(ball * target){
    return target->origin_y;
}
double get_ball_speed(ball * target){
    return target->speed;
}
int get_ball_radius(ball * target){
    return target->radius;
}

    //COLOR SETTERS
void set_ball_color(ball * target, SDL_Color new_ball_color){
    target->ball_color = new_ball_color;
}
    //COLOR GETTERS
SDL_Color get_ball_color(ball * target){
    return target->ball_color;
}

    //PLAYER DISPLAYER
void display_ball(ball * target){
    printf("=========== BALL INFORMATIONS  ===========\n");
    printf("Ball X: %f.\n",target->origin_x);
    printf("Ball Y: %f.\n",target->origin_y);
    printf("Ball Radius: %d.\n", target->radius);
    printf("Ball Speed: %f.\n", target->speed);
    printf("Ball COLOR: RGBA(%d, %d, %d, %d).\n", target->ball_color.r, target->ball_color.g, target->ball_color.b, target->ball_color.a);
    printf("=============================================\n");
}


// Dessine le cercle donné, rempli
void DrawFilledCircle(SDL_Renderer *p_renderer, double origin_x, double origin_y, int radius, SDL_Color color)
{
    for(double dy = 1; dy <= radius; dy += 1.0){

        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));

        SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y + dy - radius, origin_x + dx, origin_y + dy - radius);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y - dy + radius, origin_x + dx, origin_y - dy + radius);
    }
    SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 0);
}
