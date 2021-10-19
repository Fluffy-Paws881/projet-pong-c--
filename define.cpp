#include "define.h"
void affichage(cVue rendu, balle ballePlayer, player Joueur1, player Joueur2, SDL_Rect rectMurHaut, SDL_Rect rectMurBas, SDL_Rect posiScr, score scrPlayer, TTF_Font* police, SDL_Color couleurNoire)
{

    rendu.cleanRenderer();

    //remplissage du terrain
    SDL_SetRenderDrawColor(rendu.getRenderer(), 255, 255, 255, 255);
    rendu.cleanRenderer();

    //affichage de la balle
    SDL_SetRenderDrawColor(rendu.getRenderer(), 255, 0, 0, 255);
    SDL_RenderFillRect(rendu.getRenderer(), &ballePlayer.getRectBalle());


    // affichage des joueurs et des murs
    SDL_RenderCopy(rendu.getRenderer(), rendu.getImgPlayer(), NULL, &Joueur1.rectPosPlayer());
    SDL_RenderCopy(rendu.getRenderer(), rendu.getImgPlayer(), NULL, &Joueur2.rectPosPlayer());
    SDL_RenderCopy(rendu.getRenderer(), rendu.getImgMur(), NULL, &rectMurHaut);
    SDL_RenderCopy(rendu.getRenderer(), rendu.getImgMur(), NULL, &rectMurBas);

    //affichage score
    posiScr = { 300,100,50,100 };
    rendu.initScrP1(scrPlayer.afficheScore(couleurNoire, police, 1));
    SDL_RenderCopy(rendu.getRenderer(), rendu.getScrP1(), NULL, &posiScr);

    posiScr = { 1200,100,50,100 };
    rendu.initScrP2(scrPlayer.afficheScore(couleurNoire, police, 2));
    SDL_RenderCopy(rendu.getRenderer(), rendu.getScrP2(), NULL, &posiScr);



    // triggers the double buffers
    // for multiple rendering
    rendu.afficheRenderer();
}

void initSDL()
{
    // retourne une erreur si probleme lors de l'initialisation 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "error initializing SDL: %s\n" << SDL_GetError();
    }
}