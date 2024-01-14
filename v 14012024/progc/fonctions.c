#include "header.h"

AVL* creerAVL(int x){
  //Fonction qui prend en paramètre un entier et renvoie un AVL
  AVL *a=malloc(sizeof(AVL));
  a->fg=NULL;
  a->fd=NULL;
  a->equilibre=0;
  a->valeur=x;
  return a;
}
void parcoursPrefixe(AVL* a){
  //Fonction qui prend en paramètre un AVL et affiche son parcous préfixe
  if(a==NULL){
    return;
  }
  printf("Noeud: %d\nEquilibre: %d\n",a->valeur,a->equilibre);
  parcoursPrefixe(a->fg);
  parcoursPrefixe(a->fd);
}

AVL* rechercheAVL(AVL* a, int e){
  //Fonction qui prend en paramètres un AVL et un entier qui renvoie l'adresse du noeud ou se trouve l'entier, renvoie NULL sinon
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
  //Fonction qui prend en paramètre un AVL et effectue une rotation gauche
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
  //Fonction qui prend en paramètre un AVL et effectue une rotation droite
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
  //Fonction qui prend en paramètre un AVL et effectue une double rotation gauche
  a->fd=rotationDroite(a->fd);
  return rotationGauche(a);
}
AVL* doubleRotationDroite(AVL* a){
  //Fonction qui prend en paramètre un AVL et effectue une double rotatiob droite
  a->fg=rotationGauche(a->fg);
  return rotationDroite(a);
}
AVL* equilibrage(AVL* a){
  //Fonction qui prend en paramètre un AVL et qui equilibre si besoin cet AVL
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
  //Fonction qui prend en paramètres un AVL un entier et un pointeur sur un entier, qui insert un element dans l'AVL passé en parametre et renvoie l'AVL
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

void viderAVL(AVL* a)
{
  if (a == NULL)
    return;

  //Aide pour le développeur
  printf("Suppression de %d\n", a->valeur);


  viderAVL(a->fg);
  viderAVL(a->fd);

  free(a);

}