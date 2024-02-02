#ifndef HEADER_H
#define HEADER_H
//Verifier la bonne definition du header

//Bibliotheques necessaires
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <unistd.h>
#include <string.h>

//Constantes générales
#define TAILLE 35
#define TOP10 10

//Declarations des structures et prototypes des fonctions
typedef struct Ville{
    int comptT;
    int comptD;
    char nom[TAILLE];
}Ville;

typedef struct AVL{
  struct AVL* fg;
  struct AVL* fd;
  struct Ville* ville;
  int equilibre;
}AVL;

AVL* creerAVL(struct Ville* ville);
void parcoursPrefixe(AVL* a);
AVL* rotationGauche(AVL* a);
AVL* rotationDroite(AVL* a);
AVL* doubleRotationGauche(AVL* a);
AVL* doubleRotationDroite(AVL* a);
AVL* equilibrageAVL(AVL* a);
AVL* insertionAVL(AVL* a,struct Ville* v,int* h);
void viderAVL(AVL* a);
Ville* creerVille(char nom[]);
void lireResultats(AVL* a);
void plus_visitees(AVL* a, int* compt, char villes[TOP10][TAILLE]);
void lire_resultats(AVL** a);
void assignation_ville (AVL* a,char nom[], Ville* v);


#endif