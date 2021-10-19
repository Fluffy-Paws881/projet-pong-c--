#pragma once
#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDl_image.h>
#include "state.h"
#include <math.h>
#include "score.h"
#include "player.h"
#include "balle.h"
#include "cVue.h"
#define WIDTH 1500 //largeur du terrain
#define HEIGHT 900 //longueur du terrain

void initSDL();
void affichage(cVue rendu, balle ballePlayer, player Joueur1, player Joueur2, SDL_Rect rectMurHaut, SDL_Rect rectMurBas, SDL_Rect posiScr, score scrPlayer, TTF_Font* police, SDL_Color couleurNoire);