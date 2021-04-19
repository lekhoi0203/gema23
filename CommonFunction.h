#ifndef COMMONFUNCTION_H_INCLUDED
#define COMMONFUNCTION_H_INCLUDED

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<vector>

using namespace std;

class CommonFuntion
{
private:
    const int HEIGHT = 600;
    const int WIDTH = 800;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event1;
    double gravity;
    double speed;
    double speedFly;
    bool running = true;


    SDL_Rect playersrc, playerdest;
    SDL_Rect grasssrc, grassdest;


    SDL_Texture* player;
    SDL_Texture* background;
    SDL_Texture* grass;

public:
    CommonFuntion();
    void Initializer();
    void handleEvent();
    void Render();
    void clearUP();
    bool Running();
    void setrect();
};

class texture
{
public:
    static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};

#endif // COMMONFUNCTION_H_INCLUDED
