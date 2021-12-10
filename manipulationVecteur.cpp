/*
-----------------------------------------------------------------------------------
Nom du fichier : manipulationVecteur.h
Nom du labo    : Labo 07 : Vecteur et Matrice
Auteur(s)      : Laetitia Guidetti et Dorian Gillioz
Date creation  : 08.12.2021
Description    : Définition de fonctions permettant de réaliser divers
                 manipulation sur des matrices.
Remarque(s)    : -

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include <algorithm>            // min_element, max_element, transform, sort
#include <vector>               // Utilisation des vecteurs
#include <numeric>              // accumulate

#include "manipulationVecteur.h"

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

//--------------------------------------------------
// Déclaration
//--------------------------------------------------

/**
 * Nom              estPlusPetit
 * But              Déterminer le plus petite des vecteurs passé en paramètre
 * @param vecteur1  Le premier vecteur
 * @param vecteur2  Le deuxième vecteur
 * @return          Retourne vrai si vecteur1 est strictement plus petit que
 *                  vecteur2, faux dans le cas contraire
 */
bool estPlusPetit(const Vecteur& vecteur1, const Vecteur& vecteur2);

/**
 * Nom              sommeElement
 * But              Calculer la somme de tout les éléments présent dans un vecteur
 * @param vecteur   Le vecteur contenant les éléments
 * @return          La somme calculée
 */
int sommeElement(const Vecteur& vecteur);

/**
 * Nom              minElement
 * But              Détérmine quel vecteur possède le plus petit élément
 * @param vecteur1  Le premier vecteur
 * @param vecteur2  Le deuxième vecteur
 * @return          Vrai si vecteur1 possède l'élément le plus petit, faux dans le
 *                  cas contraire
 */
bool minElement(const Vecteur& vecteur1, const Vecteur& vecteur2);

/**
 * Nom              additionValeurs
 * But              Additionner 2 valeurs
 * @param valeur1   La première valeur à additionner
 * @param valeur2   La deuxième valeur à additionner
 * @return          Le résultat de l'addition des deux valeur
 */
int additionValeurs(int valeur1, int valeur2);


//--------------------------------------------------
// Définition
//--------------------------------------------------

bool estPlusPetit(const Vecteur& vecteur1, const Vecteur& vecteur2) {
   return vecteur1.size() < vecteur2.size();
}

size_t minCol(const Matrice& matrice) {
   return (*min_element(matrice.cbegin(), matrice.cend(), estPlusPetit)).size();

}

int sommeElement(const Vecteur& vecteur) {
   return accumulate(vecteur.cbegin(), vecteur.cend(), 0);
}

Vecteur sommeLigne(const Matrice& matrice) {
   Vecteur vecteur(matrice.size());
   transform(matrice.cbegin(), matrice.cend(), vecteur.begin(), sommeElement);
   return vecteur;
}

Vecteur vectSommeMin(const Matrice& matrice) {
   // Vecteur contenant la somme de chaque ligne de la matrice
   const Vecteur vecteur(sommeLigne(matrice));
   const Vecteur::const_iterator resultat = min_element(vecteur.cbegin(),
                                                        vecteur.cend());

   return matrice[(size_t)distance(vecteur.cbegin(), resultat)];
}

bool minElement(const Vecteur& vecteur1, const Vecteur& vecteur2) {

   // Vérifie si l'un des vecteurs est vide
   if (vecteur1.empty()) {
      return true;
   }
   if (vecteur2.empty()) {
      return false;
   }

   return *min_element(vecteur1.cbegin(), vecteur1.cend()) <
          *min_element(vecteur2.cbegin(), vecteur2.cend());
}

void sortMatrice(Matrice& matrice) {
   sort(matrice.begin(), matrice.end(), minElement);
}


int additionValeurs(int valeur1, int valeur2) {
   return valeur1 + valeur2;
}


Vecteur sommeColonne(const Matrice& matrice) {
   // La taille du vecteur est égale à la plus longue des lignes de matrice
   Vecteur vecteurSomme((*max_element(matrice.cbegin(), matrice.cend(),
                                      estPlusPetit)).size());

   for(Matrice::const_iterator i = matrice.cbegin(); i != matrice.cend(); ++i) {
      transform((*i).cbegin(), (*i).cend(), vecteurSomme.begin(),
                vecteurSomme.begin(), additionValeurs);
   }
   return vecteurSomme;
}