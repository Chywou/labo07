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

bool minVecteur(Vecteur vecteur1, Vecteur vecteur2);
int somme(const Vecteur& vecteur);
bool minElement(Vecteur vecteur1, Vecteur vecteur2);


bool minVecteur(Vecteur vecteur1, Vecteur vecteur2) {
   return vecteur1.size() < vecteur2.size();
}

size_t minCol(const Matrice& matrice) {
   Matrice::const_iterator resultat = min_element(matrice.begin(),matrice.end(),
                                                  minVecteur);
   return (*resultat).size();

}

int somme(const Vecteur& vecteur) {
   return accumulate(vecteur.begin(), vecteur.end(), 0);
}

Vecteur sommeLigne(const Matrice& matrice) {
   Vecteur vecteur(matrice.size());
   transform(matrice.begin(), matrice.end(), vecteur.begin(), somme);
   return vecteur;
}

Vecteur vectSommeMin(const Matrice& matrice) {
   Vecteur vecteur(sommeLigne(matrice));
   Vecteur::iterator resultat = min_element(vecteur.begin(), vecteur.end());
   return matrice[(size_t)distance(vecteur.begin(), resultat)];
}

bool minElement(Vecteur vecteur1, Vecteur vecteur2) {

   return *min_element(vecteur1.begin(), vecteur1.end()) <
          *min_element(vecteur2.begin(), vecteur2.end());
}

void sortMatrice(Matrice& matrice) {
   sort(matrice.begin(), matrice.end(), minElement);

}


// Recherche en cours sur la réalisation de sommeColonne
/*
void sommetruc(const Vecteur& vecteur1, Vecteur& vecteur2) {

   vecteur2 =

}

Vecteur sommeColonne(const Matrice& matrice) {
   Vecteur vecteur(matrice.size(), 0);

   transform(matrice.begin(), matrice.end(), vecteur.begin(), sommetruc);

   return v1;
}
*/