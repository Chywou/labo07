/*
-----------------------------------------------------------------------------------
Nom du fichier : manipulationVecteur.h
Nom du labo    : Labo 07 : Vecteur et Matrice
Auteur(s)      : Laetitia Guidetti et Dorian Gillioz
Date creation  : 08.12.2021
Description    : Déclaration de fonctions permettant de réaliser divers
                 manipulation sur des matrices.
Remarque(s)    : -

Compilateur    : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO07_MANIPULATIONVECTEUR_H
#define LABO07_MANIPULATIONVECTEUR_H

#include <vector>
#include <iostream>

/**
 * Nom             operator
 * But             Permet de formatter l'affichage d'un vecteur
 * @param os       Le flux
 * @param vecteur  Le vecteur à afficher au format
 * @return         Une référence au flux qui avec le formattage du vecteur
 */
std::ostream& operator<< (std::ostream& os, const std::vector<int>& vecteur);

/**
 * Nom              operator
 * But              Permet de formatter l'affichage d'une matrice (vecteur 2d)
 * @param os        Le flux
 * @param matrice   La matrice à afficher au format
 * @return          Une référence au flux qui avec le formattage de la matrice
 */
std::ostream& operator<< (std::ostream& os, const std::vector<std::vector<int>>& matrice);

/**
 * Nom              estCarree
 * But              Permet de déterminer si une matric est carrée, c'est-à-dire le même
 *                  nombre de lignes que de colonnes et qui est régulière
 * @param matrice   La matrice qu'on veut controler
 * @return          true si la matrice est carrée et false si elle ne l'est pas
 */
bool estCarree(const std::vector<std::vector<int>>& matrice);

/**
 * Nom              estReguliere
 * But              Permet de déterminer si une matrice est régulière, c'est-à-dire
 *                  que toutes les lignes ont la même longueur
 * @param matrice   La matrice qu'on veut controler
 * @return          true si elle est régulière et false si elle ne l'est pas
 */
bool estReguliere(const std::vector<std::vector<int>>& matrice);

/**
 * Nom              shuffleMatrice
 * But              Mélanger les vecteurs de la matrice sans modifier les vecteurs.
 * @param matrice   La matrice a mélangé
 */
void shuffleMatrice(std::vector<std::vector<int>>& matrice);

/**
 * Nom              minCol
 * But              Déterminer la longueur minimum des vecteurs d'une matrice
 * @param matrice   Matrice dans la quelle le vecteur est cherché
 * @return          La longueur du vecteur le plus petit trouvé
 */
size_t minCol(const std::vector<std::vector<int>>& matrice);

/**
 * Nom              sommeLigne
 * But              Calcule la somme des valeurs de chacune des lignes
 * @param matrice   Matrice contenant les lignes à calculer
 * @return          Un vecteur contenant la somme de chaque ligne
 */
std::vector<int> sommeLigne(const std::vector<std::vector<int>>& matrice);

/**
 * Nom              vectSommeMin
 * But              Trouve le vecteur d'une matrice dont la somme des valeurs est
 *                  la plus petite
 * @param matrice   Matrice dans la quelle le vecteur est cherché
 * @return          Vecteur dont la somme est la plus faible
 */
std::vector<int> vectSommeMin(const std::vector<std::vector<int>>& matrice);

/**
 * Nom              sortMatrice
 * But              Trier dans l'ordre croissant une matrice en fonction de
 *                  l'élément minimum de chaque vecteur
 * @param matrice   Matrice à trier
 */
void sortMatrice(std::vector<std::vector<int>>& matrice);

/**
 * Nom              sommeColonne
 * But              Calculer la somme de chaque colonne de la matrice
 * @param matrice   Matrice contenant les lignes à calculer
 * @return
 */
std::vector<int> sommeColonne(const std::vector<std::vector<int>>& matrice);


#endif //LABO07_MANIPULATIONVECTEUR_H
