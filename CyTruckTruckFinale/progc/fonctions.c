#include "header.h"

AVL* creerAVL(struct Ville* ville){
  //Fonction qui prend en paramètre une ville et renvoie un AVL
  AVL *a=malloc(sizeof(AVL));
  a->fg=NULL;
  a->fd=NULL;
  a->ville=ville;
  a->equilibre=0;
  return a;
}
void parcoursPrefixe(AVL* a){
  //Fonction qui prend en paramètre un AVL et affiche son parcous préfixe
  if(a==NULL){
    return;
  }
  printf("Ville: %s\nParcouru: %d fois\n",a->ville->nom,a->ville->comptT);
  parcoursPrefixe(a->fg);
  parcoursPrefixe(a->fd);
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
AVL* insertionAVL(AVL* a,struct Ville* v,int* h){
  //Fonction qui prend en paramètres un AVL une ville et un pointeur sur un entier, qui insert un element dans l'AVL passé en parametre et renvoie l'AVL
  if(a==NULL){
    *h=1;
    return creerAVL(v);
  }
  else if(v->comptT<a->ville->comptT){
    a->fg=insertionAVL(a->fg, v, h);
    *h=-*h;
  }
  else if(v->comptT>=a->ville->comptT){
    a->fd=insertionAVL(a->fd, v, h);
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
//Fonction qui vide un AVL
{
  if (a == NULL)
    return;

  //Aide pour le développeur
  printf("Suppression de %s\n", a->ville->nom);


  viderAVL(a->fg);
  viderAVL(a->fd);

  free(a);

}

void lire_resultats(AVL** a) {
    // Fonction qui lit les résultats de t.sh pour créer les noeuds de l'AVL et les insérer.
    FILE* fichier = fopen("resultats.csv", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[TAILLE];
    int h = 0;

    while (fgets(ligne, TAILLE, fichier) != NULL) {
        Ville* v = malloc(sizeof(Ville));
        assignation_ville(*a,ligne, v);
        *a = insertionAVL(*a, v, &h);
    }

    fclose(fichier);
}

void plus_visitees(AVL* a, int* compt, char villes[TOP10][TAILLE]) {
    // Fonction censée récolter et ranger dans un tableau 2D les 10 villes les plus traversées
    if (a == NULL || *compt >= TOP10) return;

    plus_visitees(a->fd, compt, villes);

    if (*compt < TOP10) {
        strcpy(villes[*compt], a->ville->nom);
        (*compt)++;
    }

    plus_visitees(a->fg, compt, villes);
}

void assignation_ville (AVL* a,char nom[], Ville* v){
    // Fonction qui sert à donner ses caractéristiques à chaque ville 
    int verif = 0;

    verif = sscanf(nom,"%[^;];%d;%d",v->nom,&v->comptT,&v->comptD);
    if (verif == 3){
        a->ville = v;
        a->fg = NULL;
        a->fd = NULL;
        return;
    }
    else{
        printf("Problème de lecture du fichier.\n");
        exit(4);
    }

}