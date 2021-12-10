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

   Matrice m1 = {};
   Matrice m2 = {{4, 1, 2, 6},
                 {1, 1, 6},
                 {2, 1, 2, 6},
                 {9, 4, 5}};
   Matrice m3 = {{5, 7, 2},
                 {1, 12, 4},
                 {7, 0, 1}};

   shuffleMatrice(m1);
   shuffleMatrice(m2);
   shuffleMatrice(m3);

   cout << boolalpha;
   cout << "1 : " << m1 << endl;
   cout << "2 : " << m2 << endl;
   cout << "3 : " << m3 << endl;
   cout << endl;
   cout << "Presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
 