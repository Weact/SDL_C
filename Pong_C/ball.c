#include "ball.h"

ball * new_ball(double origin_x, double origin_y, int radius, double speed, SDL_Color color, dir direction){
    ball * game_ball = malloc(sizeof(ball));

    set_ball_origin_x(game_ball, origin_x);
    set_ball_origin_y(game_ball, origin_y);
    set_ball_speed(game_ball, speed);
    set_ball_radius(game_ball, radius);
    set_ball_color(game_ball, color);
    set_ball_direction(game_ball, direction);

    return game_ball;
}

void move_ball(ball * ball_to_move, double speed_x, double speed_y){
    if(ball_to_move->direction == RIGHTUP)
    {
        ball_to_move->ball_side = RIGHT;
        ball_to_move->origin_x += speed_x;
        ball_to_move->origin_y -= speed_y;
    }
    else if(ball_to_move->direction == LEFTUP){
        ball_to_move->ball_side = LEFT;
        ball_to_move->origin_x -= speed_x;
        ball_to_move->origin_y -= speed_y;
    }
    if(ball_to_move->direction == LEFTDOWN){
        ball_to_move->ball_side = LEFT;
        ball_to_move->origin_x -= speed_y;
        ball_to_move->origin_y += speed_y;
    }
    else if(ball_to_move->direction == RIGHTDOWN){
        ball_to_move->ball_side = RIGHT;
        ball_to_move->origin_x += speed_y;
        ball_to_move->origin_y += speed_y;
    }
}

void ball_bounce(ball * ball_to_bounce, pl_platform * p_player1, pl_platform * p_player2)
{
    if( (ball_to_bounce->ball_side == LEFT) //If the ball is going to the left
       && (ball_to_bounce->origin_y > p_player1->p_player_dimension->y) //And the ball_y is superior to player1_y
       && (ball_to_bounce->origin_y < (p_player1->p_player_dimension->y + p_player1->p_player_dimension->h) ) //And the ball_y is inferior to player1_y+player1_height
       && (ball_to_bounce->origin_x < p_player1->p_player_dimension->x + p_player1->p_player_dimension->w) //And the ball is colliding with the player1
    )
    {
        if(ball_to_bounce->direction == LEFTUP){
            ball_to_bounce->direction = RIGHTUP;
        }
        else if(ball_to_bounce->direction == LEFTDOWN){
            ball_to_bounce->direction = RIGHTDOWN;
        }
    }
    if( (ball_to_bounce->ball_side == RIGHT)
       && (ball_to_bounce->origin_y > p_player2->p_player_dimension->y)
       && (ball_to_bounce->origin_y < (p_player2->p_player_dimension->y + p_player2->p_player_dimension->h) )
       && (ball_to_bounce->origin_x > p_player2->p_player_dimension->x - p_player2->p_player_dimension->w)
    )
    {
        if(ball_to_bounce->direction == RIGHTUP){
            ball_to_bounce->direction = LEFTUP;
        }
        else if(ball_to_bounce->direction == RIGHTDOWN){
            ball_to_bounce->direction = LEFTDOWN;
        }
    }
    else if(ball_to_bounce->origin_x > 1024)
    {
        while(!wait_event()){}
        ball_to_bounce->origin_x = 1024/2;
        ball_to_bounce->origin_y = 512/2;
        p_player1->p_player_dimension->y = 512/2;
        p_player2->p_player_dimension->y = 512/2;
    }
    else if(ball_to_bounce->origin_x < 0){
        while(!wait_event()){}
        ball_to_bounce->origin_x = 1024/2;
        ball_to_bounce->origin_y = 512/2;
        p_player1->p_player_dimension->y = 512/2;
        p_player2->p_player_dimension->y = 512/2;
    }
    else if( (ball_to_bounce->origin_y > 512) && (ball_to_bounce->ball_side == LEFT) ){
        ball_to_bounce->direction = LEFTUP;
    }
    else if( (ball_to_bounce->origin_y < 0) && (ball_to_bounce->ball_side == LEFT) ){
        ball_to_bounce->direction = LEFTDOWN;
    }
    else if( (ball_to_bounce->origin_y > 512) && (ball_to_bounce->ball_side == RIGHT) ){
        ball_to_bounce->direction = RIGHTUP;
    }
    else if( (ball_to_bounce->origin_y < 0) && (ball_to_bounce->ball_side == RIGHT) ){
        ball_to_bounce->direction = RIGHTDOWN;
    }
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
void set_ball_direction(ball * target, int new_ball_direction){
    target->direction = new_ball_direction;
}
void set_ball_side(ball * target, int new_ball_side){
    target->ball_side = new_ball_side;
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
dir get_ball_direction(ball * target){
    return target->direction;
}
side get_ball_side(ball * target){
    return target->ball_side;
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
