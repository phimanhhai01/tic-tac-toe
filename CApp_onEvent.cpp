#include "CApp.h"
bool current_player_x =  true;
void CApp::onEvent(SDL_Event* e)
{
    CEvent::onEvent(e);
}
//*******************************
void CApp::onExit()
{
    running = false;
}
//*********************************
void CApp::onLButtonDown(int xm,int ym)
{
   int i = floor((xm - FIELD_LEFT) / 140);
   int j = floor((ym - FIELD_TOP) / 140);

   //- check whether it exists and is empty
   if(i < 0 || i > 2 || j < 0 || j > 2)
    return;

   if(field[i][j] != 0)
    return;

   // set the stone
   if(current_player_x){
    field[i][j] = TYPE_X;
    current_player_x = false;
    Mix_PlayChannel(-1,snd_place,0);
    check_end();
   }
   //---------------------------------
   //find_move();
   else{
    field[i][j] = TYPE_O;
    current_player_x = true;
    Mix_PlayChannel(-1,snd_place,0);
   //----------------------------------
   check_end();
   }
}
