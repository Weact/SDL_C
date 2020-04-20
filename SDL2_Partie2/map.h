#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
/*
typedef unsigned char tileIndex;

typedef struct TProp{
    SDL_Rect Rect;
    int plein;
}TProp;

typedef struct TMap{
    int w_tile, h_tile;
    int nbTileX, nbTileY;
    SDL_Surface * p_Tileset;
    TProp * t_Props;
    tileIndex ** schema;
    int  widthMap, heightMap; //In tiles
}TMap;

TMap * LoadMap(const char* fic);
int DisplayMap(TMap* p_map, SDL_Surface * p_screen);
void LoadMap_Tileset(FILE* p_file, TMap* p_map);
int FreeMap(TMap * p_map);*/

#endif // MAP_H_INCLUDED
