#ifndef DATA_STRUCTURE_H_INCLUDED
#define DATA_STRUCTURE_H_INCLUDED

#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct sprite{
    SDL_Texture *pTexture;
    SDL_Surface *TempSurface;
    SDL_Rect sRectangle; //first rectangle
    SDL_Rect dRectangle; // another rectangle, which* stocks texture result
}sprite, *pSprite;

typedef struct sprite_elem{
    sprite* p_spriteElement;
    sprite * next_sprite;
    int position;
}sprite_elem;

typedef struct sprite_list{
    sprite_elem * first_sprite;
    int taille_sprite_list;
}sprite_list;

void init_sprite(sprite * sprite_to_init, int srect_x, int srect_y, int drect_x, int drect_y);
void init_sprite_pile(sprite_list *spritelist_to_init);
void insert_into_list(sprite_list * list_to_insert, sprite * sprite_to_insert);
#endif // DATA_STRUCTURE_H_INCLUDED
