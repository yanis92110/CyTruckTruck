#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct City{
    int count;
    char Name[23];
    struct City* next;
}City;

typedef struct Trajet{
    int ID;
    struct Trajet* next;
}Trajet;

typedef struct AVL{
  struct AVL* fg;
  struct AVL* fd;
  int valeur;
  int equilibre;
}AVL;

AVL* creerAVL(int e);
void parcoursPrefixe(AVL* a);
AVL* rechercheAVL(AVL* a,int e);
AVL* rotationGauche(AVL* a);
AVL* rotationDroite(AVL* a);
AVL* doubleRotationGauche(AVL* a);
AVL* doubleRotationDroite(AVL* a);
AVL* equilibrageAVL(AVL* a);
AVL* insertionAVL(AVL* a,int e,int* h);
void viderAVL(AVL* a);


#endif