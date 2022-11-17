#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_fichiers.h"
#include "fonctions_SDL.h"
#define NBPIECE 12
#define NBCOLONNES 6
#define NBLIGNES 2
#define NBCASES 8*8

//TODO
//- CLICS
//- CHERCHER TEXTURES POUR CLICS


//IDEES POUR FAIRE LES CLICS :
//  - DEUX FONCTIONS ANNEXES : UNE RETOURNANT UN BOOL AVEC EN ENTREE EVENTS ET UN INT, LE INT ETANT UN NUMERO DE CASE. RETOURNE VRAI SI LE CLIC EST DANS LA CASE, FAUX SINON
//  - UNE SEULE FONCTION ANNEXE : ELLE RETOURNERAIT UN INT AVEC LE NUMERO DE CASE CORRESPONDANT AU CLIC. EN ENTREE, EVENTS ET UN TABLEAU DE INT OU BIEN UNE MATRICE 2 DE INT AVEC DES COORDONNEES.


int clic_case(SDL_Event evenements, int case){
    for(int i = 0 ; i < NBCASES ; i++){
        if()
    }
}


int main(int argc, char *argv[])
{   
    int lignes = 0;
    int colonnes = 0;
    taille_fichier("fichierentree.txt",&lignes,&colonnes);
    printf("%d & %d\n",lignes, colonnes);
    char** mat = lire_fichier("fichierentree.txt");

    afficher_tab_2D(mat,lignes,colonnes);
    SDL_Window* fenetre; // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    bool terminer = false;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, NULL);
    // Initialisation du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if(fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
       return EXIT_FAILURE;
    }
    // Mettre en place un contexte de rendu de l’écran
    // Charger l’image
    SDL_Texture* plateau = charger_image( "board.bmp", renderer );
    SDL_Texture* pieces = charger_image("chesspieces.bmp", renderer);
    int piecesH, piecesW;
    int plateauH, plateauW;
    SDL_QueryTexture(pieces, NULL, NULL, &piecesW, &piecesH);
    SDL_QueryTexture(plateau, NULL, NULL, &plateauW, &plateauH);
    SDL_Rect SrcR_sprite[NBPIECE];
    for(int i = 0, x=0, y=0; i<NBPIECE; i++, x+=piecesW/NBCOLONNES){
        if(i%NBCOLONNES == 0 && i != 0){
            x=0;
            y+=piecesH/NBLIGNES;
        }
        SrcR_sprite[i].x = x;
        SrcR_sprite[i].y = y;
        SrcR_sprite[i].w = piecesW/NBCOLONNES;
        SrcR_sprite[i].h = piecesH/NBLIGNES;
    }

    for(int i = 0 ; i < NBPIECE ; i++){
        printf("Coordonées %i de SrcR : %d\n", i, SrcR_sprite[i].x);
    }

        /*for(int i = 0 ; i < lignes ; i++){
            for(int j = 0 ; j < colonnes ; j++){
                printf("\n%d", mat[i][j]);
            }
        }*/

    SDL_Rect DestR_sprite[NBCASES];
    for(int i=0, x=0, y=0; i<NBCASES ; i++, x+=plateauW/8)
    {
        if(i%8 == 0 && i != 0){
            x=0;
            y+=plateauH/8;
        }
        DestR_sprite[i].x = x;
        DestR_sprite[i].y = y;
        DestR_sprite[i].w = plateauW/8; // Largeur du sprite
        DestR_sprite[i].h = plateauH/8; // Hauteur du sprite
    }

    for(int i = 0 ; i < lignes ; i++){
            for(int j = 0 ; j < colonnes ; j++){
                printf("i*j : %d\n", i*j);
            }
        }

    for(int i = 0 ; i < NBCASES ; i++){
        printf("Coordonées %i de DestR : %d\n", i, DestR_sprite[i].y);
    }
    // Boucle principale
    while(!terminer){
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, plateau, NULL, NULL);
        SDL_PollEvent( &evenements );

        int dest = 0;
        for(int i = 0 ; i < lignes ; i++){
            for(int j = 0 ; j < colonnes ; j++){
                if(mat[i][j]!=46){
                    SDL_RenderCopy(renderer, pieces, &SrcR_sprite[mat[i][j]-48], &DestR_sprite[dest]);
                }
                dest++;
            }
        }

        /*for(int i = 0 ; i < lignes ; i++){
            for(int j = 0 ; j < colonnes ; j++){
                SDL_RenderCopy(renderer, pieces, &SrcR_sprite[mat[i][j]-48], &DestR_sprite[i+j]);
            }
        }*/

        switch(evenements.type)
        {
            case SDL_QUIT:
            terminer = true; break;
            case SDL_MOUSEBUTTONDOWN:
            if(evenements.button.x <= DestR_sprite[0].x  )
            printf("\ntest");
            case SDL_KEYDOWN:
            switch(evenements.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                case SDLK_q:
                terminer = true; break;
            }
        }
        SDL_RenderPresent(renderer);
    }
    // Libérer de la mémoire
    SDL_DestroyTexture(plateau);
    SDL_DestroyRenderer(renderer);
    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}