#include "CApp.h"
//Make it myself
CApp::CApp()
{
   running = true;
   window = NULL;
   screen = NULL;
   background = NULL;
   stone_x = NULL;
   stone_o = NULL;
   snd_draw = NULL;
   snd_lose = NULL;
   snd_place = NULL;
   snd_win = NULL;

   reset();
}
//****************************
CApp::~CApp()
{

}
//****************************
int CApp::onExecute()
{
    if(!onInit())
        return -1;

    SDL_Event e;

    while(running)
    {
        while(SDL_PollEvent(&e))
        {
            onEvent(&e);
        }

        onRender();
    }

    onQuit();

    return 0;
}
//****************************
void CApp::field_init()
{
    for(int i = 0;i <= 2;++i)
    {
        for(int j = 0;j <= 2;++j)
        {
            field[i][j] = 0;
        }
    }
}
//****************************
void CApp::reset()
{
    score_player_1 = 0;
    score_player_2 = 0;
    score_draw = 0;

    field_init();
}
//****************************
void CApp::check_end()
{
    if(check_player_1_win())
    {
        ++score_player_1;
        //-- Play music
        Mix_PlayChannel(-1,snd_win,0);

        onRender();
        SDL_Delay(1000);

        field_init();
    }
    //-----------------------
    if(check_player_2_win())
    {
        ++score_player_2;
        //-- Play music
        Mix_PlayChannel(-1,snd_lose,0);

        onRender();
        SDL_Delay(1000);

        field_init();
    }
    //-----------------------
    if(check_draw())
    {
        ++score_draw;
        //PLay music;
        Mix_PlayChannel(-1,snd_draw,0);
        onRender();
        SDL_Delay(1000);

        field_init();
    }
}
//****************************
bool CApp::check_player_1_win()
{
   if(field[0][0] == TYPE_X && field[0][1] == TYPE_X && field[0][2]  == TYPE_X)
       return true;

   if(field[1][0] == TYPE_X && field[1][1] == TYPE_X && field[1][2] == TYPE_X)
       return true;

   if(field[2][0] == TYPE_X && field[2][1] == TYPE_X && field[2][2] == TYPE_X)
       return true;

   if(field[0][0] == TYPE_X && field[1][0] == TYPE_X && field[2][0] == TYPE_X)
       return true;

   //if(field[1][0] == TYPE_X && field[1][1] == TYPE_X && field[2][1] == TYPE_X)
    if(field[0][1] == TYPE_X && field[1][1] == TYPE_X && field[2][1] == TYPE_X)
       return true;

   if(field[0][2] == TYPE_X && field[1][2] == TYPE_X && field[2][2] == TYPE_X)
       return true;

   if(field[0][0] == TYPE_X && field[1][1] == TYPE_X && field[2][2] == TYPE_X)
       return true;

   if(field[0][2] == TYPE_X && field[1][1] == TYPE_X && field[2][0] == TYPE_X)
      return true;

    return false;
}
//******************************
bool CApp::check_player_2_win()
{
    if(field[0][0] == TYPE_O && field[0][1] == TYPE_O && field[0][2]  == TYPE_O)
       return true;

   if(field[1][0] == TYPE_O && field[1][1] == TYPE_O && field[1][2] == TYPE_O)
       return true;

   if(field[2][0] == TYPE_O && field[2][1] == TYPE_O && field[2][2] == TYPE_O)
       return true;

   if(field[0][0] == TYPE_O && field[1][0] == TYPE_O && field[2][0] == TYPE_O)
       return true;

   if(field[0][1] == TYPE_O && field[1][1] == TYPE_O && field[2][1] == TYPE_O)
       return true;

   if(field[0][2] == TYPE_O && field[1][2] == TYPE_O && field[2][2] == TYPE_O)
       return true;

   if(field[0][0] == TYPE_O && field[1][1] == TYPE_O && field[2][2] == TYPE_O)
       return true;

   if(field[0][2] == TYPE_O && field[1][1] == TYPE_O && field[2][0] == TYPE_O)
      return true;

    return false;
}

bool CApp::check_draw()
{
    for(int i = 0;i <= 2;++i)
    {
        for(int j = 0;j <= 2;++j)
        {
            if(field[i][j] == 0)
                return false;
        }
    }
    return true;
}
