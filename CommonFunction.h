#ifndef COMMONFUNCTION_H_INCLUDED
#define COMMONFUNCTION_H_INCLUDED

#include<bits/stdc++.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<vector>
#include<fstream>
#include<SDL_mixer.h>


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
    bool check1;

    SDL_Rect playersrc, playerdest;
    SDL_Rect grasssrc, grassdest;
    SDL_Rect gameoversrc, gameoverdest;
    SDL_Rect buttonsrc, buttondest;
    SDL_Rect exitsrc, exitdest;
    int x,y;

    int blank;

    SDL_Texture* player;
    SDL_Texture* background;
    SDL_Texture* grass;
    SDL_Texture* gameover;
    SDL_Texture* mainmenu;
    SDL_Texture* buttonStart;
    SDL_Texture* exitButton;

    deque<SDL_Rect> pipes;
    int Score;
    bool checkAddScore;
    bool checkover;
    string state;


    Mix_Chunk* g_music;




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
    bool checkCollision(SDL_Rect a, SDL_Rect b);
    void game_Over();
    void setrectMenu();

    PipePair generate_pipe_pair();


};

class texture
{
public:
    static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};





#endif // COMMONFUNCTION_H_INCLUDED
