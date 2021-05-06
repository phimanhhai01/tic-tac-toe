
#include "CEvent.h"

CEvent::CEvent()
{

}
//****************************
CEvent::~CEvent()
{

}
//****************************
void CEvent::onEvent(SDL_Event* e)
{
   switch(e->type)
   {
   case SDL_QUIT:
    {
        onExit();
        break;
    }
    case SDL_MOUSEBUTTONDOWN:
        {
           switch(e->button.button)
           {
           case SDL_BUTTON_LEFT:
            {
                onLButtonDown(e->button.x,e->button.y);
                break;
            }
           }
           break;
        }
          default:
          {
            onUser(e->user.type,e->user.code,e->user.data1,e->user.data2);
            break;
          }

   }
}

void CEvent::onExit()
{

}


void CEvent::onKeyDown(SDL_Keycode sym,Uint16 mod,Uint16 scancode)
{
  switch(sym)
  {
  case SDLK_ESCAPE:
    {
        onExit();
        break;
    }
  }
}
void CEvent::onLButtonDown(int xm,int ym)
{

}

void CEvent::onUser(Uint8 type,int code,void* data1,void* data2)
{

}




