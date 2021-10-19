#include "score.h"



score::score()
{
	scr_p1 = 0;
	scr_p2 = 0;
}

score::score(int p1, int p2)
{
	scr_p1 = p1;
	scr_p2 = p2;
}

score::~score()
{
}

int score::getScoreP1()
{
	return scr_p1;
}

int score::getScoreP2()
{
	return scr_p2;
}

void score::addScoreP1()
{
	scr_p1++;
}

void score::addScoreP2()
{
	scr_p2++;
}

bool score::verifVictoireP1()
{
	if (scr_p1 >= 10)
	{
		return true;
	}
	else {
		return false;
	}
}

bool score::verifVictoireP2()
{
	if (scr_p2 >= 10)
	{
		return true;
	}
	else {
		return false;
	}
}

//fonction qui affiche le score des 2 joueurs
SDL_Surface* score::afficheScore(SDL_Color couleur, TTF_Font* police, int player)
{
	SDL_Surface* surfTexte = nullptr;
	SDL_Rect posiScr;
	char cScr[10]="" ;
	

	if (player == 1)
	{
		sprintf_s(cScr, "%d", scr_p1);
		 
	}
	else {
		sprintf_s(cScr, "%d", scr_p2);
		
	}
	surfTexte = TTF_RenderText_Blended(police, cScr, couleur);

	return surfTexte;
}

void score::afficheVictoire(int player, SDL_Color couleur, TTF_Font* police, SDL_Renderer* renderer)
{
	SDL_Surface* surfTexte = NULL;
	char cScr[100] = "";
	SDL_Rect posi = { 450,365,600,50 };
	
	sprintf_s(cScr, "félicitations joueur %d , vous remportez cette partie!", player);
	surfTexte = TTF_RenderText_Blended(police, cScr, { 255, 0, 0 });

	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surfTexte);
	SDL_FreeSurface(surfTexte);
	
	SDL_RenderCopy(renderer, text, NULL, &posi);

	
}
