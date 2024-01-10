#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>


typedef struct AVL{
  struct AVL* fg;
  struct AVL* fd;
  int valeur;
  int equilibre;
}AVL;

AVL* creerAVL(int e);
void parcoursPrefixe(AVL* a);
AVL* rechercheAVL(AVL* a,int e);
void rotationSimpleLeft(AVL *a);
AVL* rotationGauche(AVL* a);
AVL* rotationDroite(AVL* a);
AVL* doubleRotationGauche(AVL* a);
AVL* doubleRotationDroite(AVL* a);
AVL* equilibrageAVL(AVL* a);
AVL* insertionAVL(AVL* a,int e,int* h);



#endif