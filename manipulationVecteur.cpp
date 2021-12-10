/*
-----------------------------------------------------------------------------------
Nom du fichier : manipulationVecteur.h
Nom du labo    : Labo 07 : Vecteur et Matrice
Auteur(s)      : Laetitia Guidetti et Dorian Gillioz
Date creation  : 08.12.2021
Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#include "manipulationVecteur.h"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using Vecteur = vector<int>;
using Matrice = vector<Vecteur>;

/**
 * Nom              minTaille
 * But              Déterminer le plus petite des vecteurs passé en paramètre
 * @param vecteur1  Le premier vecteur
 * @param vecteur2  Le deuxième vecteur
 * @return          Retourne vrai si vecteur1 est strictement plus petit que
 *                  vecteur2, faux dans le cas contraire
 */
bool minTaille(const Vecteur& vecteur1, const Vecteur& vecteur2);

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


//--------------------------------------------------
// Définition
//--------------------------------------------------

bool minTaille(const Vecteur& vecteur1, const Vecteur& vecteur2) {
   return vecteur1.size() < vecteur2.size();
}

size_t minCol(const Matrice& matrice) {
   Matrice::const_iterator resultat = min_element(matrice.begin(), matrice.end(),
                                                  minTaille);
   return (*resultat).size();

}

int sommeElement(const Vecteur& vecteur) {
   return accumulate(vecteur.begin(), vecteur.end(), 0);
}

Vecteur sommeLigne(const Matrice& matrice) {
   Vecteur vecteur(matrice.size());
   transform(matrice.begin(), matrice.end(), vecteur.begin(), sommeElement);
   return vecteur;
}

Vecteur vectSommeMin(const Matrice& matrice) {
   Vecteur vecteur(sommeLigne(matrice));
   Vecteur::iterator resultat = min_element(vecteur.begin(), vecteur.end());
   return matrice[(size_t)distance(vecteur.begin(), resultat)];
}

bool minElement(const Vecteur& vecteur1, const Vecteur& vecteur2) {

   return *min_element(vecteur1.begin(), vecteur1.end()) <
          *min_element(vecteur2.begin(), vecteur2.end());
}

void sortMatrice(Matrice& matrice) {
   sort(matrice.begin(), matrice.end(), minElement);

}

// C'est pas beau, mais ça marche -> il fraudra trouvé mieux
Vecteur vecteurSomme;

int sommetruc2(int valeur, int somme) {
   return valeur + somme;
}


void sommetruc(const Vecteur& vecteur) {

   transform(vecteur.begin(), vecteur.end(), vecteurSomme.begin(), vecteurSomme
   .begin(), sommetruc2);

}

Vecteur sommeColonne(const Matrice& matrice) {
   vecteurSomme.clear();
   vecteurSomme.resize(matrice.size());

   for_each(matrice.begin(), matrice.end(), sommetruc);

   return vecteurSomme;
}
