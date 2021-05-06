
#include "CApp.h"

void CApp::onRender()
{

      CSurface::drawSurface(background,screen,0,0);
      field_draw();

      SDL_UpdateWindowSurface(window);
}
//************************************
void CApp::field_draw()
{
    for(int i = 0;i <= 2;++i)
    {
        for(int j = 0;j <= 2;++j)
        {
            if(field[i][j] == TYPE_X)
                CSurface::drawSurface(stone_x,screen,FIELD_LEFT + i*140,FIELD_TOP + j*140);

            if(field[i][j] == TYPE_O)
                CSurface::drawSurface(stone_o,screen,FIELD_LEFT + i*140,FIELD_TOP + j*140);
        }
    }
    //--------------------------------
    std::string szPlayer = "Player1 Wins: " + std::to_string(score_player_1);
    std::string szComp = "Player2 Wins: " + std::to_string(score_player_2);
    std::string szDraw = "Draws: " + std::to_string(score_draw);
    //--------------------------------
    CSurface::drawTextSurface(font,screen,szPlayer.c_str(),16,340,0,0,255);
    CSurface::drawTextSurface(font,screen,szComp.c_str(),16,375,255,0,0);
    CSurface::drawTextSurface(font,screen,szDraw.c_str(),16,410,0,0,0);

}
