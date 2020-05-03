#include "player_platform.h"

    //PLAYER CREATION
pl_platform * new_player(int player_x, int player_y, int player_w, int player_h, int player_speed, SDL_Color player_color){
    pl_platform * player = malloc(sizeof(pl_platform));
    player->p_player_dimension = malloc(sizeof(SDL_Rect));

    set_player_x(player, player_x);
    set_player_y(player, player_y);
    set_player_w(player, player_w);
    set_player_h(player, player_h);
    set_player_speed(player, player_speed);
    set_player_color(player, player_color);

    return player;
}

    //PLAYER MOVEMENT
int move_player(pl_platform * player_to_move, int speed){
    /*if(player_to_move->p_player_dimension->y > (512 - player_to_move->p_player_dimension->h)){
        return player_to_move->p_player_dimension->y = (512 - player_to_move->p_player_dimension->h*1.1);
    }
    if(player_to_move->p_player_dimension->y > (0 + player_to_move->p_player_dimension->h)){
        return player_to_move->p_player_dimension->y += speed;
    }else{
        return player_to_move->p_player_dimension->y = player_to_move->p_player_dimension->h;
    }*/

    if(player_to_move->p_player_dimension->y < 0)
    {
        return player_to_move->p_player_dimension->y = 0;
    }
    else if(player_to_move->p_player_dimension->y > (512 - player_to_move->p_player_dimension->h)){
        return player_to_move->p_player_dimension->y = 512 - player_to_move->p_player_dimension->h;
    }
    else{
        return player_to_move->p_player_dimension->y += speed;
    }
}

    //PLAYER DISPLAYER
void display_player(pl_platform * target){
    printf("=========== PLAYER INFORMATIONS  ===========\n");
    printf("Player X: %d.\n",target->p_player_dimension->x);
    printf("Player Y: %d.\n",target->p_player_dimension->y);
    printf("Player W: %d.\n",target->p_player_dimension->w);
    printf("Player H: %d.\n",target->p_player_dimension->h);
    printf("Player Speed: %d.\n", target->player_speed);
    printf("Player COLOR: RGBA(%d, %d, %d, %d).\n", target->player_color.r, target->player_color.g, target->player_color.b, target->player_color.a);
    printf("=============================================\n");
}

    //PLAYER SETTERS
void set_player_x(pl_platform * target, int new_player_x){
    target->p_player_dimension->x = new_player_x;
}
void set_player_y(pl_platform * target, int new_player_y){
    target->p_player_dimension->y = new_player_y;
}
void set_player_w(pl_platform * target, int new_player_w){
    target->p_player_dimension->w = new_player_w;
}
void set_player_h(pl_platform * target, int new_player_h){
    target->p_player_dimension->h = new_player_h;
}
void set_player_speed(pl_platform * target, int new_player_speed){
    target->player_speed = new_player_speed;
}

    //PLAYER GETTERS
int get_player_x(pl_platform * target){
    return target->p_player_dimension->x;
}
int get_player_y(pl_platform * target){
    return target->p_player_dimension->y;
}
int get_player_w(pl_platform * target){
    return target->p_player_dimension->w;
}
int get_player_h(pl_platform * target){
    return target->p_player_dimension->h;
}
int get_player_speed(pl_platform * target){
    return target->player_speed;
}

    //COLOR SETTERS
void set_player_color(pl_platform * target, SDL_Color new_player_color){
    target->player_color = new_player_color;
}
    //COLOR GETTERS
SDL_Color get_player_color(pl_platform * target){
    return target->player_color;
}
