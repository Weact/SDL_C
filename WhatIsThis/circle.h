#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "../SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DrawCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color);
void DrawFilledCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color);

#endif // CIRCLE_H_INCLUDED
