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
#include <iostream>                 // cout
#include <vector>                   // Utilisation des vecteurs
#include <cstdlib>                  // EXIT_SUCCESS
#include <limits>                   // numeric_limits
#include "manipulationVecteur.h"

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

int main() {

   Matrice m1 = {};
   Matrice m2 = {{4, 1, 2},
                 {1, 1, 6},
                 {2, 1, 2, 6},
                 {9, 4, 5}};
   Matrice m3 = {{5, 7, 2},
                 {1, 12, 4},
                 {7, 0, 1}};

   cout << boolalpha;
   cout << "1 : " << m1 << endl;
   cout << "M1 est carree : " << estCarree(m1) << endl;
   cout << "M1 est reguliere : " << estReguliere(m1) << endl;
   cout << "Longueure minimale des vecteurs de M1 : " << minCol(m1) << endl;
   cout << "Somme des lignes de M1 : " << sommeLigne(m1) << endl;
   cout << "Somme des colonnes : " << sommeColonne(m1) << endl;
   cout << "Vecteur dont la somme des valeurs est la plus faible : " << vectSommeMin
   (m1) << endl;
   shuffleMatrice(m1);
   cout << "Melange des vecteurs : " << m1 << endl;
   sortMatrice(m1);
   cout << "Trie croissant en fonction de la valeur min de chaque vecteur : " << m1
   << endl;

   cout << "----------------------" << endl;

   cout << "2 : " << m2 << endl;
   cout << "Est carree : " << estCarree(m2) << endl;
   cout << "Est reguliere : " << estReguliere(m2) << endl;
   cout << "Longueure minimale des vecteurs de M1 : " << minCol(m2) << endl;
   cout << "Somme des lignes : " << sommeLigne(m2) << endl;
   cout << "Somme des colonnes : " << sommeColonne(m2) << endl;
   cout << "Vecteur dont la somme des valeurs est la plus faible : " << vectSommeMin
      (m2) << endl;
   shuffleMatrice(m2);
   cout << "Melange des vecteurs : " << m2 << endl;
   sortMatrice(m2);
   cout << "Trie croissant en fonction de la valeur min de chaque vecteur : " << m2
        << endl;

   cout << "----------------------" << endl;

   cout << "3 : " << m3 << endl;
   cout << "Est carree : " << estCarree(m3) << endl;
   cout << "Est reguliere : " << estReguliere(m3) << endl;
   cout << "Longueure minimale des vecteurs de M1 : " << minCol(m3) << endl;
   cout << "Somme des lignes : " << sommeLigne(m3) << endl;
   cout << "Somme des colonnes : " << sommeColonne(m3) << endl;
   cout << "Vecteur dont la somme des valeurs est la plus faible : " << vectSommeMin
      (m3) << endl;
   shuffleMatrice(m3);
   cout << "Melange des vecteurs : " << m3 << endl;
   sortMatrice(m3);
   cout << "Trie croissant en fonction de la valeur min de chaque vecteur : " << m3
        << endl;



   cout << endl;
   cout << "Presser ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   return EXIT_SUCCESS;
}
 