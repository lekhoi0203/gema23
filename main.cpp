#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include "CommonFunction.h"

CommonFuntion* g = new CommonFuntion();

int main(int argc, char* argv[])
{
    double frameStart;
    double lastFrame = 0;

    g->Initializer();
    while (g->Running())
    {

        frameStart = SDL_GetTicks();
        g->setrect();
        g->handleEvent();
        g->Render();
        if ((frameStart - lastFrame) < (1000/60))
        {
            SDL_Delay((1000/60) - (frameStart - lastFrame));
        }
        lastFrame = frameStart;
    }
    g->clearUP();
    return 0;
}

