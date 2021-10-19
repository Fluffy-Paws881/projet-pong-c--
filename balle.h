#pragma once
#include <SDL.h>
#include "player.h"
#include "score.h"

class balle
{
	SDL_Rect rectBalle;
	int vX, vY, paddleCenter, d;
	


public:

	//constructeur
	balle(int x, int y, int w, int h, int vx, int vy);

	//destructeur
	~balle();

	//accesseur 
	SDL_Rect getRectBalle();

	//mutateurs
	void setRectBalle(int x, int y, int w, int h);
	void deplacementBalle(int h);
	void rebondPlayer(player p1, player p2);
	void rebondMural(int h);
	void verifMarquagePoint(player* p1, player* p2, score* scr, int h, int w);

};
