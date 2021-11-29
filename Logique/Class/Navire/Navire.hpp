/**
 * \file Navire.hpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef NAVIRE_HPP
#define NAVIRE_HPP

#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include "../Point.hpp"
#include "../../../definitions.hpp"


class Navire
{
    protected :
       
        int idFlotte;
        int id;
        Point* centre;
        Point* destination;
        Point* wayPoint;
        std::vector<Point*> chemin;
        Navire* cible;
        bool move;
        int angle;
        int pv;
        int vitesse;
        int vitesseVerticale;
        int vitesseHorizontale;
        int pvMax;
        int degatArme;
        int cdArme; //cool down pour le tir
        int portee;
        

    public : 
        Navire();
        Navire(int idFlotte, int id, Point* pos, Point* dest, int pvMax, int vitesse, int degatArme, int cdArme, int portee);

        ~Navire();

        int getIdFlotte();
        int getId();
        Point* getCentre();
        Point* getDestination();
        Point* getNextWayPoint();
        int getAbscisse();
        int getOrdonnee();
        bool isMoving();
        int getAngle();
        int getPv();
        int getVitesse();
        int getPvMax();
        int getDegatArme();
        int getCdArme();
        int getPortee();
        Navire* getCible();

        void setIdFlotte(int idFlotte);
        void setId(int i);
        void setCentre(Point* centre);
        void deplacer(int abs, int ord);
        void setMove(bool b);
        void setAngle(int angle);
        void setPv(int pv);
        void setVitesse(int vitesse);
        void setDestination(Point* dest);
        void setChemin();
        void setPvMax(int pvMax);
        void setDegatArme(int degat);
        void setCdArme(int cd);
        void setPortee(int p);
        void setCible(Navire* navire);

        void reduireId();
};


#endif