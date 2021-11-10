/**
 * \file input.cpp
 * \brief Gère les entrées utilisateur
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#include "input.hpp"

void gestion_evenements(SDL_Event *event)
{
    while(SDL_PollEvent(event)) 
    {
        switch(event->type)
        {
            case SDL_QUIT : // Si l'utilisateur a cliqué sur le X de la fenêtre
                exit(0);
            break;
            case SDL_KEYDOWN :  // Si une touche clavier est appuyée
                switch (event->key.keysym.sym)
                {
                    case SDLK_RIGHT :
                        break;
                    case SDLK_LEFT :
                        break;
                    case SDLK_UP :
                        break;
                    case SDLK_DOWN :
                        break;
                    case SDLK_SPACE :
                        break;
                    case SDLK_ESCAPE : 
                        break;
                    default:
                    break;
                }
            break;
            case SDL_MOUSEBUTTONDOWN: // Si une touche souris est appuyée
                switch(event->button.button)
                {
                    case SDL_BUTTON_LEFT:
                    break;
                    case SDL_BUTTON_RIGHT:
                    break;
                }
            default:
            break;
        }
    }
}