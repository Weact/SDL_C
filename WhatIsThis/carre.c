#include "carre.h"

void DrawFilledSquare(SDL_Renderer* renderer, SDL_Surface* surface, SDL_Rect* rect, Uint8 colorR, Uint8 colorG, Uint8 colorB, Uint8 colorA)
{
        SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, colorA);
        SDL_RenderDrawRect(renderer, rect);
        SDL_FillRect(surface, rect, SDL_MapRGB(surface->format, colorR, colorG, colorB));
        SDL_RenderFillRect(renderer, rect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
void DrawEmptySquare(SDL_Renderer* renderer, SDL_Rect* rect, Uint8 colorR, Uint8 colorG, Uint8 colorB, Uint8 colorA)
{
     SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, colorA);
     SDL_RenderDrawRect(renderer, rect);
     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
