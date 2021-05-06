#ifndef CEVENT_H
#define CEVENT_H

#include <SDL.h>

class CEvent
{
public:
    CEvent();
    virtual ~CEvent();
    virtual void onEvent(SDL_Event* e);
    virtual void onExit();
    virtual void onKeyDown(SDL_Keycode sym,Uint16 mod,Uint16 scancode);
    virtual void onLButtonDown(int xm,int ym);
    virtual void onUser(Uint8 type,int code,void* data1,void* data2);


private:



};
#endif // CEVENT_H
