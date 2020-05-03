#include "data_structure.h"

void init_sprite_pile(sprite_list *spritelist_to_init){
    spritelist_to_init->first_sprite = NULL;
    spritelist_to_init->taille_sprite_list = 0;
}

void insert_into_list(sprite_list * list_to_insert, sprite * sprite_to_insert){
    if(list_to_insert->taille_sprite_list < 1){
        list_to_insert->first_sprite  = sprite_to_insert;
        list_to_insert->taille_sprite_list = list_to_insert->taille_sprite_list+1;
        sprite_to_insert-> = sprite_to_insert->position+1;
    }
}

void init_sprite(sprite * sprite_to_init, SDL_Renderer * p_renderer, int srect_x, int srect_y, int drect_x, int drect_y){
    int format = 0;
    int access = 0;
    int width = 1280;
    int height = 720;
    int depth = 32;

    SDL_Rect s_rect;
    s_rect.x = srect_x;
    s_rect.y = srect_y;

    SDL_Rect d_rect;
    d_rect.x = drect_x;
    d_rect.y = drect_y;

    sprite_to_init->sRectangle = s_rect;
    sprite_to_init->dRectangle= d_rect;

    sprite_to_init->pTexture = SDL_CreateTexture(p_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    sprite_to_init->TempSurface = SDL_CreateRGBSurface(0, width, height, depth, 0,  0,  0, 0);
}
