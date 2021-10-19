#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>

class score
{
	int scr_p1 , scr_p2;

public:

	//constructeur 
	score();
	score(int p1, int p2);

	//destructeur
	~score();

	//accesseurs
	int getScoreP1();
	int getScoreP2();

	//mutateurs
	void addScoreP1();
	void addScoreP2();

	// verification de victoire
	bool verifVictoireP1();
	bool verifVictoireP2();

	//fonction qui affiche le score des 2 joueurs
	SDL_Surface* afficheScore(SDL_Color couleur, TTF_Font* police, int player);

	//fonction qui affiche qui est le vainqueur
	void afficheVictoire(int player, SDL_Color couleur, TTF_Font* police, SDL_Renderer* renderer);
};
