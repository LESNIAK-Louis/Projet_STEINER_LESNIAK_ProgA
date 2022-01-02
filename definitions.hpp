/** 
* \file definitions.hpp
* \brief Definition des constantes du programme
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#define error(s) {\
        perror(s);\
        exit(EXIT_FAILURE); }

#endif


#define PI 3.14159


#define HAUTEUR_ECRAN 800
#define LARGEUR_ECRAN 800

#define HAUTEUR_INTERFACE 90
#define ABSCISSE_INITIALE 100
#define TAILLE_BOUTON 30
#define NB_CLASSE_NAVIRE 2

#define TAILLE_ILE1 64

#define PV_CONT_WIDTH 32
#define PV_CONT_HEIGHT 6
#define PV_REMP_WIDTH 30
#define PV_REMP_HEIGHT 4

//Flotte
#define OR_INITIAL 200
#define GAIN_INITIAL 2
#define OR_MAX 9999
#define PV_MAX_FLOTTE 5000
#define NB_AMELIO_MAX 3

//Bateau
#define NB_CARAC_PATROUILLEUR 6 
#define COUT_PATROUILLEUR 20
#define COUT_AMELIORATION_PATROUILLEUR 100
#define TAILLE_PATROUILLEUR 24
#define VITESSE_PATROUILLEUR 2
#define AMELIO_VITESSE_PATROUILLEUR 1
#define PV_MAX_PATROUILLEUR 20
#define AMELIO_PV_MAX_PATROUILLEUR 5
#define DEGATS_PATROUILLEUR 4
#define AMELIO_DEGATS_PATROUILLEUR 2
#define CADENCE_TIR_PATROUILLEUR 2
#define AMELIO_CADENCE_PATROUILLEUR 1
#define PORTEE_PATROUILLEUR 60
#define AMELIO_PORTEE_PATROUILLEUR 15