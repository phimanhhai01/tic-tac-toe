
#include "CSurface.h"

CSurface::CSurface()
{

}
//*********************************
SDL_Surface* CSurface::loadSurface(char*  fname,SDL_Surface* screen)
{
    SDL_Surface* temp = SDL_LoadBMP(fname);
    if(temp == NULL)
    {
        return NULL;
    }
    //-------------------------------------
    SDL_Surface* newSurface = SDL_ConvertSurface(temp,screen->format,0);
    //-------------------------------------
    SDL_FreeSurface(temp);

    return newSurface;
}
//************************************
SDL_Surface* CSurface::loadSurface(char*  fname,SDL_Surface* screen,int r,int g,int b)
{
    SDL_Surface* temp = SDL_LoadBMP(fname);
    if(temp == NULL)
    {
        return NULL;
    }
    //-------------------------------------
    SDL_Surface* newSurface = SDL_ConvertSurface(temp,screen->format,0);
    SDL_SetColorKey(newSurface,SDL_TRUE,SDL_MapRGB(newSurface->format,r,g,b));
    //-------------------------------------
    SDL_FreeSurface(temp);

    return newSurface;
}
//************************************
void CSurface::drawSurface(SDL_Surface* src,SDL_Surface* dst,int x,int y)
{
    if(src == NULL || dst == NULL)
        return;

    SDL_Rect rcDest;
    rcDest.x = x;
    rcDest.y = y;

    SDL_BlitSurface(src,NULL,dst,&rcDest);
}
//************************************
void CSurface::drawSurface(SDL_Surface* src,SDL_Surface* dst,SDL_Rect* clip,int x,int y)
{
    if(src == NULL || dst == NULL)
        return;

    SDL_Rect rcDest;
    rcDest.x = x;
    rcDest.y = y;

    SDL_BlitSurface(src,clip,dst,&rcDest);
}
//************************************
void CSurface::drawSurface(SDL_Surface* src,SDL_Surface* dst,SDL_Rect* clip,SDL_Rect* scale)
{
    if(src == NULL || dst == NULL)
        return;

    SDL_BlitSurface(src,clip,dst,scale);
}
//************************************
void CSurface::drawTextSurface(TTF_Font* font,SDL_Surface* screen,const char* str,int x,int y,int r,int g,int b)
{
    if(font == NULL || screen == NULL)
        return;

    SDL_Color color = {r,g,b};

    SDL_Rect rcDest;
    rcDest.x = x;
    rcDest.y = y;

    SDL_Surface* txtSurface = TTF_RenderText_Solid(font,str,color);
    if(txtSurface == NULL)
        return;

    SDL_BlitSurface(txtSurface,NULL,screen,&rcDest);

    SDL_FreeSurface(txtSurface);

}

