/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo 07 : Vecteur et Matrice
Auteur(s)      : Laetitia Guidetti et Dorian Gillioz
Date creation  : 08.12.2021
Description    : Ce programme permet de tester des outils manipulant des matrices
                 (vector de vector) et des vecteurs de int.

Remarque(s)    : -

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>                   // Utilisation des vecteurs
#include <cstdlib>                  // EXIT_SUCCESS
#include <limits>                   // numeric_limits
#include "manipulationVecteur.h"

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

int main() {

   Matrice m1 = {{}};
   Matrice m2 = {{8, 9, 2},
                 {1, 1, 1},
                 {0, 3, 2}};

   Matrice m3 = {{5},
                 {1, 1},
                 {5, 7, 1},
                 {5, 7, 1},
                 {5, 7, 1}};




   cout << endl;
   cout << "Presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
 