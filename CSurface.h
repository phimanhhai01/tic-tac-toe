#ifndef CSURFACE_H
#define CSURFACE_H

#include <SDL.h>
#include <SDL_ttf.h>

class CSurface
{
public:
    CSurface();

    static SDL_Surface* loadSurface(char* fname,SDL_Surface* screen);
    static SDL_Surface* loadSurface(char* fname,SDL_Surface* screen,int r,int g,int b);

    static void drawSurface(SDL_Surface* src,SDL_Surface* dst,SDL_Rect* clip,int x,int y);
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst,int x,int y);
    static void drawSurface(SDL_Surface* src,SDL_Surface* dst,SDL_Rect* clip,SDL_Rect* scale);
    static void drawTextSurface(TTF_Font* font,SDL_Surface* screen,const char* str,int x,int y,int r,int g,int b);

private:


};
#endif // CSURFACE_H
