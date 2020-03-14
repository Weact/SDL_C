#ifndef CARRE_H_INCLUDED
#define CARRE_H_INCLUDED

#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DrawFilledSquare(SDL_Renderer* renderer, SDL_Surface* surface, SDL_Rect* rect, Uint8 colorR, Uint8 colorG, Uint8 colorB, Uint8 colorA);
void DrawEmptySquare(SDL_Renderer* renderer, SDL_Rect* rect, Uint8 colorR, Uint8 colorG, Uint8 colorB, Uint8 colorA);
#endif // CARRE_H_INCLUDED
