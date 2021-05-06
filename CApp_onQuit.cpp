
#include "CApp.h"

void CApp::onQuit()
{
    TTF_CloseFont(font);
    font = NULL;

    Mix_FreeChunk(snd_draw);
    snd_draw = NULL;

    Mix_FreeChunk(snd_lose);
    snd_lose = NULL;

    Mix_FreeChunk(snd_place);
    snd_place = NULL;

    Mix_FreeChunk(snd_win);
    snd_win = NULL;

    SDL_FreeSurface(screen);
    screen = NULL;

    SDL_FreeSurface(background);
    background = NULL;

    SDL_FreeSurface(stone_x);
    stone_x = NULL;

    SDL_FreeSurface(stone_o);
    stone_o = NULL;

    SDL_DestroyWindow(window);
    window = NULL;


    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}
