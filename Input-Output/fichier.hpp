/**
 * \file fichier.hpp
 * \brief Définitions des fonctions qui gèrent la communication les fichiers
 * \author Louis Lesniak & Hugues Steiner
 * \date 10 Nov. 2021
*/

#ifndef FICHIER_HPP
#define FICHIER_HPP


#include <iostream>
#include <fstream>
#include <string>
#include "../definitions.hpp"
#include "../Logique/Class/Monde.hpp"


unsigned int getNombreLignesFichier(char* path);
unsigned int getLongueurMaxColonne(char* path);
Monde* lireSauvegarde(std::string path);
char** allouerTab2D(int n, int m);
void desallouerTab2D(char** tab, int n);
void afficherTab2D(char** tab, int n, int m);
void ecrireMonde(std::string fileName, Monde* monde);
bool isFileExist(std::string fileName);
void sauvegarder(std::string path, Monde* monde);

#endif