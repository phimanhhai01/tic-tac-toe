
#include "CApp.h"

bool CApp::onInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
    //----------------------------------
    window = SDL_CreateWindow(WINDOW_CAPTION,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        return false;
    }
    //----------------------------------
    screen = SDL_GetWindowSurface(window);
    if(screen == NULL)
        return false;
    //-----------------------------------
    SDL_SetSurfaceRLE(screen,1);
    //-----------------------------------
    background = CSurface::loadSurface("Backgrounds/Background.bmp",screen);
    stone_x = CSurface::loadSurface("Backgrounds/Stone1.bmp",screen,30,129,192);
    stone_o = CSurface::loadSurface("Backgrounds/Stone2.bmp",screen,30,129,192);

    if(background == NULL || stone_x == NULL || stone_o == NULL)
    {
        return false;
    }
    //-----------------------------------
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2,2048)== -1)
    {
        return false;
    }
    //-----------------------------------
    if(!loadMedia())
        return false;

    return true;
}
bool CApp::loadMedia()
{
    snd_draw = Mix_LoadWAV("Music/Draw.wav");
    snd_lose = Mix_LoadWAV("Music/Lose.wav");
    snd_place = Mix_LoadWAV("Music/Place.wav");
    snd_win = Mix_LoadWAV("Music/Win.wav");

    if(snd_draw == NULL || snd_lose == NULL || snd_place == NULL || snd_win == NULL)
        return false;

    //------------------------------------
    if(TTF_Init()== -1)
        return false;

    font = TTF_OpenFont("Fonts/RobotoCondensed-Italic.ttf",24);
    if(!font)
        return false;

    return true;
}
