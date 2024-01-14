#include "header.h"


int testyanis(){
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