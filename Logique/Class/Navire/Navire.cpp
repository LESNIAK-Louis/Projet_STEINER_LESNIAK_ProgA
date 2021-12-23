/**
 * \file Navire.cpp
 * \brief Definition des diffferent types de bateaux/vehicules
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

//TODO : Pathfinding à faire

#include "Navire.hpp"

Navire::Navire(int idFlotte, int id, Point* pos, Point* dest, int vitesse, int pvMax, int degatArme, int cdArme, int portee){
    this->idFlotte = idFlotte;
    this->id = id;
    this->centre = new Point(pos);
    this->destination = new Point(dest);
    this->wayPoint = new Point(dest);
    //this->setChemin();
    this->angle = 0;
    this->pvMax = pvMax;
    this->setPv(pvMax);
    this->vitesse = vitesse;
    this->degatArme = degatArme;
    this->cdArme = cdArme;
    this->portee = portee;    
    this->calculerVitesseHorVert();
    this->chemin = new std::vector<Point*>();
}

Navire::Navire(){
    this->setMove(false);
    this->setAngle(0);
}

Navire::~Navire()
{
    delete this->centre;
    delete this->destination;
    delete this->wayPoint;
    delete this->cible;
}


//Getter

int Navire::getIdFlotte(){
    return this->idFlotte;
}

int Navire::getId(){
    return this->id;
}

Point* Navire::getCentre(){
    return this->centre;
}

int Navire::getAbscisse(){
    return this->getCentre()->getAbscisse();
}

int Navire::getOrdonnee(){
    return this->getCentre()->getOrdonnee();
}

int Navire::getTaille(){
    return this->taille;
}

bool Navire::isMoving(){
    return this->move;
}

int Navire::getAngle() {
    return this->angle;
}

int Navire::getVitesse(){
    return this->vitesse;
}

int Navire::getVitesseHorizontale(){
    return this->vitesseHorizontale;
}

int Navire::getVitesseVerticale(){
    return this->vitesseVerticale;
}

Point* Navire::getWayPoint(){
    return this->wayPoint;
}

Point* Navire::getDestination(){
    return this->destination;
}

int Navire::getPv(){
    return this->pv;
}

int Navire::getPvMax(){
    return this->pvMax;
}

int Navire::getDegatArme(){
    return this->degatArme;
}

int Navire::getCdArme(){
    return this->cdArme;
}

int Navire::getPortee(){
    return this->portee;
}


Navire* Navire::getCible(){
    return this->cible;
}



//Setter

void Navire::setIdFlotte(int idFlotte){
    this->idFlotte = idFlotte;
}

void Navire::setId(int id){
    this->idFlotte = id;
}

void Navire::reduireId(){
    this->setId(this->getId() - 1);
}

void Navire::setCentre(Point* point){
    if(point == NULL) error("Point NULL en param | setCentre - Navire");
    if (this->centre != NULL) delete this->centre;
    this->centre = point;
}

void Navire::setAbscisse(int abs){
    this->getCentre()->setAbscisse(abs);
}

void Navire::setOrdonnee(int ord){
    this->getCentre()->setOrdonnee(ord);
}

void Navire::deplacer(int delta_abs, int delta_ord){
    this->centre->deplacer(delta_abs, delta_ord);
}

void Navire::setMove(bool b) {
    this->move = b;
}

void Navire::setAngle(int angle){
    angle%=360;
    this->angle = angle;
    this->calculerVitesseHorVert();
}

void Navire::modifierAngle(int deltaAngle){
    deltaAngle%=360;
    this->setAngle(this->getAngle() + deltaAngle);
}

void Navire::setPv(int pv){
    this->pv = pv;
}

void Navire::ajouterPV(int pv){
    this->setPv(this->getPv() + pv);
    if (this->pv > this->pvMax) {
        this->setPv(this->getPvMax());
    }
}

void Navire::setVitesse(int vitesse) {
    this->vitesse = vitesse;
    this->calculerVitesseHorVert();
}

void Navire::setVitesseHorizontale(int vh){
    this->vitesseHorizontale = vh;
}

void Navire::setVitesseVerticale(int vv){
    this->vitesseVerticale = vv;
}

void Navire::calculerVitesseHorVert(){
    int vh, vv;
    int angle = this->getAngle();
    float a = angle * (PI/180);
    switch (angle/(90)) {
        case 0:
        case 4: 
            vh = round( this->getVitesse() * std::sin(a)  );
            vv = - round( this->getVitesse() * std::cos(a)  );
        break;
        case 1:
           
            vh = round( this->getVitesse() * std::sin(a)  );
            vv = -round( this->getVitesse() * std::cos(a)  );
        break;
        case 2:
           
            vh = round( this->getVitesse() * std::sin(a)  );
            vv = -round( this->getVitesse() * std::cos(a)  );
        break;
        case 3:
            
            vh = round( this->getVitesse() * std::sin(a)  );
            vv = -round( this->getVitesse() * std::cos(a)  );
        break;
        default:
        break;
    }
    this->setVitesseHorizontale(vh);
    this->setVitesseVerticale(vv);
}

void Navire::setDestination(Point* point){
    this->getDestination()->copierPoint(point);
    this->setWayPoint(this->getDestination());
}

void Navire::setWayPoint(Point* point){
    this->getWayPoint()->copierPoint(point);
    this->setMove(!(this->estEnCollisionAvec(-this->getTaille()/2, this->getDestination())));
    setAngle(this->getCentre()->trouverAngle(this->destination));
}


void Navire::setPvMax(int pvMax){
    this->pvMax = pvMax;
}

void Navire::setDegatArme(int degat){
    this->degatArme = degat;
}

void Navire::setCdArme(int cd){
    this->cdArme = cd;
}

void Navire::setPortee(int por){
    this->portee = por;
}

void Navire::setCible(Navire* navire){
    if(navire == NULL) error("Navire NULL en param | setCible - Navire");
    this->cible = navire;
}


//Pathfinding

bool Navire::estEnCollisionAvec(int taille, Point* ctr){
    return (this->getCentre()->distance(ctr) < (this->getTaille() + taille)/2);
}

void Navire::avancer(int deltaAngle){
    this->modifierAngle(deltaAngle);
    if ( this->estEnCollisionAvec(-this->getTaille()/2, this->getWayPoint()) && !this->getWayPoint()->isEqual(this->getDestination()) ){
        this->setWayPoint(this->getDestination());
    }
    setAngle(this->getCentre()->trouverAngle(this->getWayPoint()));
    this->getCentre()->deplacer(this->getVitesseHorizontale(), this->getVitesseVerticale());
    if (this->getAbscisse() < 0) { this->setAbscisse(0);}
    if (this->getAbscisse() > LARGEUR_ECRAN) {this->setAbscisse(LARGEUR_ECRAN);}
    if (this->getOrdonnee() < 0){ this->setOrdonnee(0);}
    if (this->getOrdonnee() > HAUTEUR_ECRAN) { this->setOrdonnee(HAUTEUR_ECRAN);}
    //Si le navire a atteint le point de passage, alors le point de passage devient la destination
    
    this->setMove(!(this->estEnCollisionAvec(-this->getTaille()/2, this->getDestination() )));
}

std::string Navire::formattedInfo()
{
    std::string info = this->getCentre()->formattedInfo() + ";" +
    this->getDestination()->formattedInfo() + ";" +
    std::to_string(this->getVitesse()) + ";" + 
    std::to_string(this->getPvMax()) + ";" + 
    std::to_string(this->getDegatArme()) + ";" + 
    std::to_string(this->getCdArme()) + ";" + 
    std::to_string(this->getPortee()) + ";" + 
    std::to_string(this->getPv());
    return info;
}