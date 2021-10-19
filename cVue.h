#pragma once
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

class cVue
{
	SDL_Window* win;
	SDL_Renderer* rend;
	SDL_Texture* barPlayer;
	SDL_Texture* laserWall;
	SDL_Texture* textP1;
	SDL_Texture* textP2;
	SDL_Surface* image;

public:

	//constructeur
	cVue();
	cVue(int w, int h);

	//destructeur
	~cVue();

	//accesseur
	SDL_Renderer* getRenderer();
	SDL_Texture* getImgPlayer();
	SDL_Texture* getImgMur();
	SDL_Texture* getScrP1();
	SDL_Texture* getScrP2();
	SDL_Window* getWindow();

	void initBarPlayer();
	void initWall();
	void cleanRenderer();
	void afficheRenderer();
	void destroyWindow();
	void destroyRenderer();
	void initScrP1(SDL_Surface* surf);
	void initScrP2(SDL_Surface* surf);



};
