#include "header.h"

AVL* creerAVL(int x){
  AVL *a=malloc(sizeof(AVL));
  a->fg=NULL;
  a->fd=NULL;
  a->equilibre=0;
  a->valeur=x;
  return a;
}
void parcoursPrefixe(AVL* a){
  if(a==NULL){
    return;
  }
  printf("Noeud: %d\nEquilibre: %d\n",a->valeur,a->equilibre);
  parcoursPrefixe(a->fg);
  parcoursPrefixe(a->fd);
}

AVL* rechercheAVL(AVL* a, int e){
  if(a==NULL){
    return NULL;
  }
  else if(a->valeur==e){
    return a;
  }
  else if(a->valeur<e){
    return rechercheAVL(a->fg, e);
  }
  else{
    return rechercheAVL(a->fd, e);
  }
}
AVL* rotationGauche(AVL* a){
  AVL* pivot;
  int eq_a, eq_p;
  pivot=a->fd;
  a->fd=pivot->fg;
  pivot->fg=a;
  eq_a=a->equilibre;
  eq_p=pivot->equilibre;
  a->equilibre=eq_a-fmax(eq_p,0)-1;
  pivot->equilibre=fmin(eq_a-2,eq_a+eq_p-2);
  pivot->equilibre=fmin(pivot->equilibre,eq_p-1);
  a=pivot;
  return a;
}
AVL* rotationDroite(AVL* a){
  AVL* pivot;
  int eq_a, eq_p;
  pivot=a->fg;
  a->fg=pivot->fd;
  pivot->fd=a;
  eq_a=a->equilibre;
  eq_p=pivot->equilibre;
  a->equilibre=eq_a-fmin(eq_p,0)+1;
  pivot->equilibre=fmax(eq_a+2,eq_a+eq_p+2);
  pivot->equilibre=fmax(pivot->equilibre,eq_p+1);
  a=pivot;
  return a;
}
AVL* doubleRotationGauche(AVL* a){
  a->fd=rotationDroite(a->fd);
  return rotationGauche(a);
}
AVL* doubleRotationDroite(AVL* a){
  a->fg=rotationGauche(a->fg);
  return rotationDroite(a);
}
AVL* equilibrage(AVL* a){
  if(a->equilibre>=2){
    if(a->fd->equilibre>=0){
      return rotationGauche(a);
    }
    else{
      return doubleRotationGauche(a);
    }
  }
  else if(a->equilibre<=-2){
    if(a->fg->equilibre<=0){
      return rotationDroite(a);
    }
    else{
      return doubleRotationDroite(a);
    }
  }
  return a;
}
AVL* insertionAVL(AVL* a,int e,int* h){
  if(a==NULL){
    *h=1;
    return creerAVL(e);
  }
  else if(e<a->valeur){
    a->fg=insertionAVL(a->fg, e, h);
    *h=-*h;
  }
  else if(e>a->valeur){
    a->fd=insertionAVL(a->fd, e, h);
  }
  else{
    *h=0;
    return a;
  }
  if(*h!=0){
    a->equilibre=a->equilibre+*h;
    a=equilibrage(a);
    if(a->equilibre==0){
      *h=0;
    }
    else{
      *h=1;
    }
  }
  return a;
}
