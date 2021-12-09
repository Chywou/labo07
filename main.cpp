/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo 07 : Vecteur et Matrice
Auteur(s)      : Laetitia Guidetti et Dorian Gillioz
Date creation  : 08.12.2021
Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include "manipulationVecteur.h"

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

int main() {

   Matrice m1 = {{}};
   Matrice m2 = {{4, 1, 2},
                 {1, 1, 2},
                 {2, 1, 2}};
   Matrice m3 = {{5, 7, 2},
                 {1, 12},
                 {5, 7, 1}};



   cout << endl;
   cout << "Presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
 