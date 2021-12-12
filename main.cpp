/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo 07 : Vecteur et Matrice
Auteur(s)      : Laetitia Guidetti et Dorian Gillioz
Date creation  : 08.12.2021
Description    : Ce programme permet de tester le fonctionnement de la librairie
                 manipulationVecteur.

Remarque(s)    : -

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>                 // cout
#include <vector>                   // Utilisation des vecteurs
#include <cstdlib>                  // EXIT_SUCCESS
#include <limits>                   // numeric_limits
#include "manipulationVecteur.h"

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

int main() {

   cout << "Programme montrant le bon fonctionnement de la librairie "
        << "manipulationVecteur" << endl << endl;
   cout << boolalpha;

   //--------------------------------------------------
   // Matrice 1
   //--------------------------------------------------
   Matrice m1 = {{4, 1, 2},
                 {1, 0, 6},
                 {9, 4, 5}};

   cout << "Matrice 1                                : " << m1               << endl;
   cout << "Est carree                               : " << estCarree(m1)    << endl;
   cout << "Est reguliere                            : " << estReguliere(m1) << endl;
   cout << "Longueur minimale des vecteurs           : " << minCol(m1)       << endl;
   cout << "Somme des valeurs de chaque ligne        : " << sommeLigne(m1)   << endl;
   cout << "Somme des valeurs de chaque colonne      : " << sommeColonne(m1) << endl;
   cout << "Vecteur avec la somme la plus faible     : " << vectSommeMin(m1) << endl;
   shuffleMatrice(m1);
   cout << "Melange des vecteurs                     : " << m1               << endl;
   sortMatrice(m1);
   cout << "Tri croissant selon les valeurs minimales: " << m1               << endl;

   cout << "------------------------------------------------------" << endl << endl;

   //--------------------------------------------------
   // Matrice 2
   //--------------------------------------------------
   Matrice m2 = {{5, 7, 2},
                 {1, 12},
                 {7, 0, 1},
                 {3, 5, 1, 8, 2},
                 {2, 0, 8}};

   cout << "Matrice 2                                 : " << m2               << endl;
   cout << "Est carree                                : " << estCarree(m2)    << endl;
   cout << "Est reguliere                             : " << estReguliere(m2) << endl;
   cout << "Longueur minimale des vecteurs            : " << minCol(m2)       << endl;
   cout << "Somme des valeurs de chaque ligne         : " << sommeLigne(m2)   << endl;
   cout << "Somme des valeurs de chaque colonne       : " << sommeColonne(m2) << endl;
   cout << "Vecteur avec la somme la plus faible      : " << vectSommeMin(m2) << endl;
   shuffleMatrice(m2);
   cout << "Melange des vecteurs                      : " << m2               << endl;
   sortMatrice(m2);
   cout << "Tri croissant selon les valeurs minimales : " << m2               << endl;

   cout << "-------------------------------------------------------" << endl << endl;

   //--------------------------------------------------
   // Quitter le programme
   //--------------------------------------------------
   cout << "Presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
 