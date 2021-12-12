/*
-----------------------------------------------------------------------------------
Nom du fichier : manipulationVecteur.cpp
Nom du labo    : Labo 07 : Vecteur et Matrice
Auteur(s)      : Laetitia Guidetti et Dorian Gillioz
Date creation  : 08.12.2021
Description    : Définition de fonctions permettant de réaliser divers
                 manipulations sur des matrices et vecteurs.
Remarque(s)    : -

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include <algorithm>            // min_element, max_element, transform, sort, ...
#include <vector>               // Utilisation des vecteurs
#include <numeric>              // accumulate
#include <chrono>               // chrono::system_clock
#include <random>               // default_random_engine
#include <iostream>             // cout, ostream

#include "manipulationVecteur.h"


using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

//--------------------------------------------------
// Déclaration
//--------------------------------------------------

/**
 * Nom              estPasEgale
 * But              Comparer si la taille de deux vecteurs est égale
 * @param vecteur1  Le premier vecteur
 * @param vecteur2  Le deuxième vecteur
 * @return          true s'ils ne sont pas égaux, false sinon
 */
bool estPasEgale(const Vecteur& vecteur1, const Vecteur& vecteur2);

/**
 * Nom              estPlusPetit
 * But              Déterminer le plus petit des vecteurs passé en paramètre
 * @param vecteur1  Le premier vecteur
 * @param vecteur2  Le deuxième vecteur
 * @return          Retourne true si vecteur1 est strictement plus petit que
 *                  vecteur2, false dans le cas contraire
 */
bool estPlusPetit(const Vecteur& vecteur1, const Vecteur& vecteur2);

/**
 * Nom              sommeElement
 * But              Calculer la somme de tous les éléments présents dans un vecteur
 * @param vecteur   Le vecteur contenant les éléments
 * @return          La somme calculée
 */
int sommeElement(const Vecteur& vecteur);

/**
 * Nom              additionValeurs
 * But              Additionner 2 valeurs
 * @param valeur1   La première valeur à additionner
 * @param valeur2   La deuxième valeur à additionner
 * @return          Le résultat de l'addition des deux valeurs
 */
int additionValeurs(int valeur1, int valeur2);

/**
 * Nom              minElement
 * But              Déterminer quel vecteur possède le plus petit élément
 * @param vecteur1  Le premier vecteur
 * @param vecteur2  Le deuxième vecteur
 * @return          true si vecteur1 possède l'élément le plus petit, false dans le
 *                  cas contraire
 */
bool minElement(const Vecteur& vecteur1, const Vecteur& vecteur2);

//--------------------------------------------------
// Définition
//--------------------------------------------------

ostream& operator<< (ostream& os, const Vecteur& vecteur) {
   os << "(";
   for (Vecteur::const_iterator i = vecteur.cbegin(); i != vecteur.cend(); ++i) {
      if (i != vecteur.cbegin()) {
         os << ", ";
      }
      os << *i;
   }
   os << ")";
   return os;
}

ostream& operator<< (ostream& os, const Matrice& matrice) {
   os << "[";
   for (Matrice::const_iterator i = matrice.cbegin(); i != matrice.cend(); ++i) {
      if (i != matrice.cbegin()) {
         os << ", ";
      }
      os << *i;
   }
   os << "]";
   return os;
}

bool estCarree(const Matrice& matrice) {
   if (matrice.empty()) {
      return true;
   }
   return estReguliere(matrice) && matrice.size() == matrice[0].size();
}

bool estPasEgale(const Vecteur& vecteur1, const Vecteur& vecteur2) {
   return vecteur1.size() != vecteur2.size();
}

bool estReguliere(const Matrice& matrice) {
   return matrice.end() == adjacent_find(matrice.begin(), matrice.end(), estPasEgale);
}

bool estPlusPetit(const Vecteur& vecteur1, const Vecteur& vecteur2) {
   return vecteur1.size() < vecteur2.size();
}

size_t minCol(const Matrice& matrice) {
   if(matrice.empty()) {
      return 0;
   }
   return (*min_element(matrice.cbegin(), matrice.cend(), estPlusPetit)).size();
}

int sommeElement(const Vecteur& vecteur) {
   return accumulate(vecteur.cbegin(), vecteur.cend(), 0);
}

Vecteur sommeLigne(const Matrice& matrice) {
   // Vecteur dont la taille est égale au nombre de ligne de matrice
   Vecteur vecteur(matrice.size());
   transform(matrice.cbegin(), matrice.cend(), vecteur.begin(), sommeElement);
   return vecteur;
}

int additionValeurs(int valeur1, int valeur2) {
   return valeur1 + valeur2;
}

Vecteur sommeColonne(const Matrice& matrice) {
   if(matrice.empty()) {
      return {};
   }
   // La taille du vecteur est égale à la ligne la plus longue de la matrice
   Vecteur vecteurSomme((*max_element(matrice.cbegin(), matrice.cend(),
                                      estPlusPetit)).size());
   // Addition de chaque ligne de matrice dans vecteurSomme
   for(Matrice::const_iterator i = matrice.cbegin(); i != matrice.cend(); ++i) {
      transform((*i).cbegin(), (*i).cend(), vecteurSomme.begin(),
                vecteurSomme.begin(), additionValeurs);
   }
   return vecteurSomme;
}

Vecteur vectSommeMin(const Matrice& matrice) {
   if(matrice.empty()) {
      return {};
   }
   // Vecteur contenant la somme de chaque ligne de la matrice
   const Vecteur vecteur(sommeLigne(matrice));
   const Vecteur::const_iterator resultat = min_element(vecteur.cbegin(),
                                                        vecteur.cend());

   return matrice[(size_t)distance(vecteur.cbegin(), resultat)];
}

void shuffleMatrice(Matrice& matrice) {
   // http://www.cplusplus.com/reference/algorithm/shuffle/?kw=shuffle
   unsigned seed = chrono::system_clock::now().time_since_epoch().count();
   shuffle(matrice.begin(), matrice.end(), default_random_engine(seed));
}

bool minElement(const Vecteur& vecteur1, const Vecteur& vecteur2) {

   // Vérifie si l'un des vecteurs est vide
   if (vecteur1.empty()) {
      return true;
   }
   if (vecteur2.empty()) {
      return false;
   }

   // Compare la valeur de l'élément le plus petit de chaque vecteur
   return *min_element(vecteur1.cbegin(), vecteur1.cend()) <
          *min_element(vecteur2.cbegin(), vecteur2.cend());
}

void sortMatrice(Matrice& matrice) {
   sort(matrice.begin(), matrice.end(), minElement);
}

