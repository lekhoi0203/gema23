#include "CommonFunction.h"

CommonFuntion::CommonFuntion()
{
    window = NULL;
    renderer = NULL;
    gravity = 0.05;
    speed = 1;
    speedFly = -2;
}

bool CommonFuntion::Running()
{
    return running;
}

void CommonFuntion::Initializer()
{
    SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("My game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if (window)
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer)
            {
                cout<<"sucessed"<<endl;
                running = true;
                player = texture::Texture("Image/Flappybird.png", renderer);
                background = texture::Texture("Image/BackgroundFlappyBird.png", renderer);
                grass = texture::Texture("Image/base.png", renderer);


            }
            else
            {
                cout<<"failed created renderer"<<endl;
            }
        }
        else
        {
            cout<<"window not created"<<endl;
        }
         int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                   cout<<"SDL_image could not initialize! SDL_image Error: %s\n"<<IMG_GetError()<<endl;
                    running = false;
                }

}

void CommonFuntion::setrect()
{
    playersrc.h = 445;
    playersrc.w = 512;
    playersrc.x = playersrc.y = 0;

    playerdest.h = 45;
    playerdest.w = 60;
    playerdest.x = 100;
    speed += gravity;
     if (playerdest.y > 700)
     {
         running = false;
     }
     else
     {
         playerdest.y += speed + 0.5 * (gravity);
     }

    grasssrc.x = 0;
    grasssrc.y = 0;
    grasssrc.h = 112;
    grasssrc.w = 336;

    grassdest.h = 100;
    grassdest.w = WIDTH;
    grassdest.x = 0;
    grassdest.y = HEIGHT - grassdest.h;
}

void CommonFuntion::handleEvent()
{
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT)
    {
        running = false;
    }
    if (event1.type == SDL_MOUSEBUTTONDOWN)
    {
        cout<<"pressed"<<endl;
    }
    if (event1.type == SDL_KEYDOWN)
    {
        if (event1.key.keysym.sym == SDLK_SPACE)
        {
            speed = speedFly;

        }
    }
}



SDL_Texture* texture::Texture(const char* filelocation, SDL_Renderer* ren)
{
    SDL_Surface* surface;
    surface = IMG_Load(filelocation);
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(ren, surface);
    return tex;
}

void CommonFuntion::Render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderCopy(renderer, player, &playersrc, &playerdest);
    SDL_RenderCopy(renderer, grass, &grasssrc, &grassdest);
    SDL_RenderPresent(renderer);
}

void CommonFuntion::clearUP()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(player);
    SDL_DestroyTexture(grass);
}

