#include "Graphique/fonctions_SDL.hpp"
#include "Logique/Class/Monde.hpp"
#include "Input-Output/input.hpp"
#include "Logique/logique.hpp"
#include "Input-Output/fichier.hpp"
#include "Game.hpp"
/*
#define objW 640
#define objH 192

#define chatW 285/3
#define chatH 250/2

#define texteW 300
#define texteH 35
*/

#include <iostream>

int main()
{
    Monde* monde;
    //monde = readSave("Save.txt");
    monde = new Monde(1,0,1,1);
    monde->addFlotte(new Flotte(0, new Point(50,50), new Point(200,200), 0,10,500));
    monde->addFlotte(new Flotte(1, new Point(400,400), new Point(400,400), 0,10,500));
    monde->setIle(0, new Ile(new Point(300, 300), TAILLE_ILE1 , 1));
    monde->getFlotte(0)->newPatrouilleur();
    //monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(1)->newPatrouilleur();
    /*monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(0)->newPatrouilleur();
    monde->getFlotte(1)->newPatrouilleur();*/

    //monde->getFlotte(1)->getPatrouilleur(0)->setCentre(new Point(150, 250));
    /*monde->getFlotte(0)->getPatrouilleur(4)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(2)->setCentre(new Point(80-32, 150));
    monde->getFlotte(0)->getPatrouilleur(2)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(3)->setCentre(new Point(80-32, 150+32));
    monde->getFlotte(0)->getPatrouilleur(3)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(5)->setCentre(new Point(80+32, 150-32));
    monde->getFlotte(0)->getPatrouilleur(5)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(6)->setCentre(new Point(80+32, 150));
    monde->getFlotte(0)->getPatrouilleur(6)->setAngle(90);

    monde->getFlotte(0)->getPatrouilleur(7)->setCentre(new Point(80+32, 150+32));
    monde->getFlotte(0)->getPatrouilleur(7)->setAngle(90);*/

    monde->getFlotte(0)->getPatrouilleur(0)->setDestination(new Point(400,420));
    monde->getFlotte(0)->getPatrouilleur(0)->ajouterPV(-5);
    /*monde->getFlotte(0)->getPatrouilleur(1)->setDestination(new Point(222,222));
    monde->getFlotte(0)->getPatrouilleur(1)->setDestination(new Point(250, 150));
    monde->getFlotte(0)->getPatrouilleur(2)->setDestination(new Point(150, 150));
    monde->getFlotte(0)->getPatrouilleur(3)->setDestination(new Point(150, 250));
    monde->getFlotte(1)->getPatrouilleur(0)->setDestination(new Point(300,300));*/

    Game* jeu = new Game(monde);
    SDL_Texture* fond = charger_image("Ressources/fond.bmp", jeu->getEcran());
    SDL_Texture* textureIle = charger_image("Ressources/ile.bmp", jeu->getEcran());
    SDL_Texture* texturePatrouilleur = charger_image("Ressources/test_bateau.bmp", jeu->getEcran());
    SDL_Texture* texturePoint = charger_image("Ressources/point.bmp", jeu->getEcran());
    SDL_Texture* textureContourPV = charger_image("Ressources/contourBarrePV.bmp", jeu->getEcran());
    SDL_Texture* textureRemplissagePV = charger_image("Ressources/remplissageBarrePV.bmp", jeu->getEcran());

    while(!jeu->getTerminer()){
        SDL_RenderClear(jeu->getEcran());
        SDL_RenderCopy(jeu->getEcran(), fond, NULL, NULL);
        afficherMonde(jeu->getEcran(), monde, textureIle, texturePatrouilleur, textureContourPV, textureRemplissagePV);
        SDL_Rect DestR = {monde->getIle(0)->getAbscisse()-(TAILLE_ILE1/2), monde->getIle(0)->getOrdonnee()-(TAILLE_ILE1/2),TAILLE_ILE1, TAILLE_ILE1};
        SDL_RenderCopy(jeu->getEcran(), textureIle, NULL, &DestR);
        moveShips(monde);
        //std::cout << "Pat 0 angle : " << monde->getFlotte(0)->getPatrouilleur(0)->getAngle()<< "\n";
        //std::cout << "Pat 0" + monde->getFlotte(0)->getPatrouilleur(0)->getCentre()->toString()<< "\n";
        /*std::cout << "Pat 0 dest : " + monde->getFlotte(0)->getPatrouilleur(0)->getDestination()->toString()<< "\n";
        std::cout << "Pat 1" + monde->getFlotte(0)->getPatrouilleur(1)->getCentre()->toString()<< "\n";
        std::cout << "Pat 1 dest : " + monde->getFlotte(0)->getPatrouilleur(1)->getDestination()->toString()<< "\n";*/
        gestion_evenements(jeu);
        SDL_RenderPresent(jeu->getEcran());
        SDL_Delay(50);
    }


    save("Save.txt", jeu->getMonde());
    delete jeu;


    return 0;
}