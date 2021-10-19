#include "cVue.h"

cVue::cVue()
{
    win = nullptr;
    rend = nullptr;
    barPlayer = nullptr;
    laserWall = nullptr;
    image = nullptr;
    textP2 = nullptr;
    textP1 = nullptr;
}

cVue::cVue(int w, int h)
{
     win = SDL_CreateWindow("GAME", // creates a window
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w, h, 0);

    // creation du renderer
     rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
     barPlayer = nullptr;
     laserWall = nullptr;
     image = nullptr;
     textP2 = nullptr;
     textP1 = nullptr;
}

cVue::~cVue()
{
}

SDL_Renderer* cVue::getRenderer()
{
    return rend;
}

SDL_Texture* cVue::getImgPlayer()
{
    return barPlayer;
}

SDL_Texture* cVue::getImgMur()
{
    return laserWall;
}

SDL_Texture* cVue::getScrP1()
{
    return textP1;
}

SDL_Texture* cVue::getScrP2()
{
    return textP2;
}

SDL_Window* cVue::getWindow()
{
    return win;
}

void cVue::initBarPlayer()
{
    SDL_Surface* image = IMG_Load("./assets/stickpng.png");
    if (!image)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());   
    }
     barPlayer = SDL_CreateTextureFromSurface(rend, image);
    //free(image);
}

void cVue::initWall()
{
    SDL_Surface* image = IMG_Load("./assets/laserWall.jpg");
    if (!image)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
    }
    laserWall = SDL_CreateTextureFromSurface(rend, image);
    //SDL_FreeSurface(image);
}

void cVue::cleanRenderer()
{
    SDL_RenderClear(rend);
}

void cVue::afficheRenderer()
{
    SDL_RenderPresent(rend);
}

void cVue::destroyWindow()
{
    SDL_DestroyWindow(win);
}

void cVue::destroyRenderer()
{
    SDL_DestroyRenderer(rend);
}

void cVue::initScrP1(SDL_Surface* surf)
{
    if (surf == nullptr)
    {
        printf("Erreur de chargement de la surface : %s", SDL_GetError());
    }
    textP1 = SDL_CreateTextureFromSurface(rend, surf);
}

void cVue::initScrP2(SDL_Surface* surf)
{
    if (!surf)
    {
        printf("Erreur de chargement de la surface : %s", SDL_GetError());
    }
    textP2 = SDL_CreateTextureFromSurface(rend, surf);
}


