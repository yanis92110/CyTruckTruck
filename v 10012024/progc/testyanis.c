#include "header.h"

int caca(){
  AVL* a;
  int* h;
  a=creerAVL(10);
  a->fd=creerAVL(11);
  a->equilibre=2;
  a->fd->fd=creerAVL(13);
  a->fd->equilibre=1;
  printf("\n Equilibre de racine: %d\n",a->equilibre);
  parcoursPrefixe(a);
  printf("\nEquilibre de 11: %d\nEquilibre de 13:%d\n",a->fd->equilibre,a->fd->fd->equilibre);
  //rotationSimpleLeft(a);
  a=rotationGauche(a);
  printf("*************\n");
  parcoursPrefixe(a);
  printf("\nEquilibre racine: %d\nEquilibre fg: %d\nEquilibre fd: %d\n",a->equilibre,a->fg->equilibre,a->fd->equilibre);
  //parcoursPrefixe(a);
  return 0;
}

int main(){
  AVL* a=creerAVL(5);
  int* h=malloc(sizeof(int));
  *h=0;
  a=insertionAVL(a, 5, h);
  sleep(1);
  parcoursPrefixe(a);
  sleep(2);
  a=insertionAVL(a, 10, h);
  parcoursPrefixe(a);
  sleep(2);
  a=insertionAVL(a, 15, h);
  parcoursPrefixe(a);
  sleep(2);
  a=insertionAVL(a, 13, h);
  parcoursPrefixe(a);
  sleep(2);
  a=insertionAVL(a, 20, h);
  parcoursPrefixe(a);
  a=insertionAVL(a, 26, h);
  parcoursPrefixe(a);
  a=insertionAVL(a, 17, h);
  parcoursPrefixe(a);
  free(h);
  return 0;
}