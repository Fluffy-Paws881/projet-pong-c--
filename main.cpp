#include "define.h"

using namespace std;

int main(int argc, char* argv[])
{

    //initialisation de la SDL
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    void initSDL();

    SDL_Rect posiScr = {0,0,0,0};
    cVue rendu(WIDTH,HEIGHT);

    // controls annimation loop
    int close = 0;

    //initialisation des images
    rendu.initBarPlayer();
    rendu.initWall();

    //rectangle contenant les dimension et la position des murs 
    SDL_Rect rectMurHaut = { 0, 0, WIDTH, 30 };
    SDL_Rect rectMurBas = { 0, HEIGHT - 30, WIDTH, 30 };


   //creation des joueurs 
   player Joueur1(0,320,20,200);
   player Joueur2(WIDTH - 20, 320, 20, 200);

   //creation de la balle
   balle ballePlayer(WIDTH / 2, HEIGHT / 2, 10, 10, -15, 0);


    //initialisation du score
    score scrPlayer;


    //test ttf
    SDL_Color couleurBlanche = { 255, 255, 255 };
    SDL_Color couleurNoire = { 255, 0, 0 };

    //initialisation de la police
    TTF_Font* police = nullptr ;
    police = TTF_OpenFont("./font/BAUHS93.ttf", 65);
    if (police == nullptr)
    {
        fprintf(stderr, "Erreur %s\n", SDL_GetError());
        return -1;
    }
    
    
    // annimation loop
    while (!close && (!scrPlayer.verifVictoireP1() && !scrPlayer.verifVictoireP2())) {
        SDL_Event event;

         //deplacement de la balle   
        ballePlayer.deplacementBalle(HEIGHT);

        //verification si colision avec un des joueurs et si oui modification du vecteur de deplacement
        ballePlayer.rebondPlayer(Joueur1, Joueur2);

        //verification si colision avec un mur et si oui modification du vecteur de deplacement
        ballePlayer.rebondMural(HEIGHT);

        //verification si la balle sort du terrain et si oui appelle de la fonction score pour ajouter un point
        ballePlayer.verifMarquagePoint(&Joueur1, &Joueur2, &scrPlayer, HEIGHT, WIDTH);




            // Events management
            while (SDL_PollEvent(&event)) 
            {
                switch (event.type) {

                case SDL_QUIT:
                    // handling of close button
                    close = 1;
                    break;

                case SDL_KEYDOWN:
                    // keyboard API for key pressed
                    switch (event.key.keysym.sym) {
                    case SDLK_z:
                        Joueur1.setPlayerState(state::up);
                        break;
                    case SDLK_s:
                        Joueur1.setPlayerState(state::down);
                        break;


                    case SDLK_UP:
                        Joueur2.setPlayerState(state::up);
                        break;
                    case SDLK_DOWN:
                        Joueur2.setPlayerState(state::down);
                        break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                    case SDLK_z:
                    case SDLK_s:
                        Joueur1.setPlayerState(state::idle);
                        break;
                    case SDLK_UP:
                    case SDLK_DOWN:
                        Joueur2.setPlayerState(state::idle);
                        break;

                    }
                    break;
                }
            }

            //deplacement des joueurs
            Joueur1.addPlayerPose();
            Joueur2.addPlayerPose(); 

            //procedure d'affichage
             affichage(rendu, ballePlayer, Joueur1, Joueur2, rectMurHaut, rectMurBas, posiScr, scrPlayer, police, couleurNoire);
            
            // calculates to 60 fps
            SDL_Delay(1000 / 60);
       
    }
        
    //verification du gagnant
    if (scrPlayer.verifVictoireP1())
    {
        scrPlayer.afficheVictoire(1,couleurNoire, police, rendu.getRenderer());
    }
    else if (scrPlayer.verifVictoireP2())
    {
        scrPlayer.afficheVictoire(2, couleurNoire, police, rendu.getRenderer());
    }

    if (!close)
    {
        
        rendu.afficheRenderer();
        SDL_Delay(5000);
    }
    // destroy renderer
    rendu.destroyRenderer();

    // destroy window
    rendu.destroyWindow();

    // close SDL
    SDL_Quit();

    return 0;
}









