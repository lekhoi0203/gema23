#ifndef COMMONFUNCTION_H_INCLUDED
#define COMMONFUNCTION_H_INCLUDED

#include<bits/stdc++.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<vector>


using namespace std;

typedef pair<SDL_Rect, SDL_Rect> PipePair;

class CommonFuntion
{
private:
    const int HEIGHT = 600;
    const int WIDTH = 800;
    SDL_Window* window;
    SDL_Renderer* renderer;
    double gravity;
    double speed;
    double speedFly;
    bool running = true;
    double frameStart;
    double lastFrame = 0;
    SDL_Event event1;
    bool check1=false;

    SDL_Rect playersrc, playerdest;
    SDL_Rect grasssrc, grassdest;
    SDL_Rect gameoversrc, gameoverdest;
    SDL_Rect buttonsrc, buttondest={0,0,0,0};
    int x,y;

    int blank;

    SDL_Texture* player;
    SDL_Texture* background;
    SDL_Texture* grass;
    SDL_Texture* gameover;
    SDL_Texture* mainmenu;
    SDL_Texture* buttonStart;

    deque<SDL_Rect> pipes;


public:
    CommonFuntion();
    bool getcheck();
    void Initializer();
    void handleEvent();
    void Render();
    void clearUP();
    bool Running();
    void setrect();
    void menu();
    void Game();
    void changeState();
    void draw_pipes();
    void handle_pipes();
    bool game_over();
    void run();

    PipePair generate_pipe_pair();


};

class texture
{
public:
    static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};

#endif // COMMONFUNCTION_H_INCLUDED
