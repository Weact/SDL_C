#include "SDL_Game_Event.h"
#include "InputManager.h"
#include "player_platform.h"

int event_handling(pl_platform * p_player1, pl_platform * p_player2,int speed){
    SDL_Event event;
    int keydown;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                return 1;
                break;
            case SDL_KEYDOWN:
                keydown = event.key.keysym.sym;
                if(keydown == CONFIRM){
                    printf("\n===========================================\n");
                    printf("CONFIRM HAS BEEN PRESSED BY GAME EVENT HANDLER\n");
                    printf("===========================================\n");
                    break;
                }
                else if(keydown == CANCEL){
                    printf("\n===========================================\n");
                    printf("CANCEL HAS BEEN PRESSED BY GAME EVENT HANDLER\n");
                    printf("===========================================\n");

                    return 0;
                }
                else if(keydown == UP_p1){
                    printf("\n===========================================\n");
                    printf("UP 1 HAS BEEN PRESSED BY GAME EVENT HANDLER\n");
                    printf("===========================================\n");
                    p_player1->p_player_dimension->y = move_player(p_player1, -p_player1->player_speed);
                }
                else if(keydown == UP_p2){
                    printf("\n===========================================\n");
                    printf("UP 2 HAS BEEN PRESSED BY GAME EVENT HANDLER\n");
                    printf("===========================================\n");
                    p_player2->p_player_dimension->y = move_player(p_player2, -p_player2->player_speed);
                }
                else if(keydown == DOWN_p1){
                    printf("\n=============================================\n");
                    printf("DOWN 1 HAS BEEN PRESSED BY GAME EVENT HANDLER\n");
                    printf("=============================================\n");
                    p_player1->p_player_dimension->y = move_player(p_player1, p_player1->player_speed);
                }
                else if(keydown == DOWN_p2){
                    printf("\n=============================================\n");
                    printf("DOWN 2 HAS BEEN PRESSED BY GAME EVENT HANDLER\n");
                    printf("=============================================\n");
                    p_player2->p_player_dimension->y = move_player(p_player2, p_player2->player_speed);
                }
                break;
        }
    }
    return 1;
}

void end_game(){
    printf("\n===============================\n");
    printf("Program will end in 3seconds.\n");
    SDL_Delay(1000);
    printf("Program will end in 2seconds.\n");
    SDL_Delay(1000);
    printf("Program will end in 1seconds.\n");
    SDL_Delay(1000);
    printf("===============================\n");
    SDL_Quit(); //QUIT
}
