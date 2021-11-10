/** 
* \file Point.hpp
* \brief Représentation d'un Point
* \author Louis Lesniak & Hugues Steiner
* \date 10 Nov. 2021
*/

#ifndef POINT
#define POINT

#include <string>
#include <cmath>
#include "../../definitions.hpp"

class Point
{
    public:
        Point(int abs, int ord);
        Point(Point* point);
        void deplacer(int abs, int ord);
        int getOrdonnee();
        int getAbscisse();

        void setOrdonnee(int ord);
        void setAbscisse(int abs);

        int distance(Point* pt);
        bool isEqual(Point* pt);
        
        std::string toString();

    private:
        int abs;
        int ord;

};

#endif