#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include<SDL_image.h>
#include "CommonFunction.h"

CommonFuntion* g = new CommonFuntion();

int main(int argc, char* argv[])
{
    g->Initializer();
    while (g->Running())
    {
        g->run();
    }
    g->clearUP();
    return 0;
}
