#ifndef CAPP_H
#define CAPP_H

//#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "CEvent.h"
#include "CSurface.h"
#include "Defines.h"
#include <math.h>
#include <stdlib.h>
#include <string>

class CApp:public CEvent
{
public:
    CApp();
    virtual ~CApp();

    int onExecute();

    void onEvent(SDL_Event* e);
    virtual void onExit();
    virtual void onLButtonDown(int xm,int ym);

private:
    enum{TYPE_X = 1,TYPE_O};

    bool running;

    SDL_Window *window;
    SDL_Surface* screen;
    SDL_Surface* background;
    SDL_Surface* stone_x;
    SDL_Surface* stone_o;

    Mix_Chunk* snd_draw;
    Mix_Chunk* snd_lose;
    Mix_Chunk* snd_win;
    Mix_Chunk* snd_place;

    TTF_Font* font;

    int field[3][3];
    int score_player_1;
    int score_player_2;
    int score_draw;

    bool onInit();
    void onRender();
    void onQuit();

    void field_init();
    void reset();
    void field_draw();
    void check_end();
    bool check_player_1_win();
    bool check_player_2_win();
    bool check_draw();

    bool loadMedia();

};
#endif // CAPP_H
