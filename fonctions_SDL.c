#include <SDL2/SDL.h>
#include "fonctions_SDL.h"

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer){
    SDL_Surface* image = SDL_LoadBMP(nomfichier);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    return texture;
}

SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b){
    SDL_Surface* Surface = SDL_LoadBMP(nomfichier);
    Uint32 key = SDL_MapRGB(Surface->format, r, g, b);  
    SDL_SetColorKey(Surface, SDL_TRUE, key);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Surface);
    return texture;
}