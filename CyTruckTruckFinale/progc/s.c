#include"header.h"
#define MAX 50

typedef struct AVLs{
//structure d'AVL pour le traitement s
  struct AVLs *fg;
  struct AVLs *fd;
  int equilibre;
  float valeur;
}AVLs;

int max(int a, int b) {
  //fonction qui renvoie le plus grand entier entre 2 entiers passés en parametres
    return a > b ? a : b;
}

int min(int a, int b) {
  //fonction qui renvoie le plus petit entier entre 2 entiers passés en parametres
    return a <= b ? a : b;
}

float moyenne(AVLs* tr) {
  //fonction qui renvoie la moyenne de toutes les valeurs d'un AVLs
    if (tr == NULL)
        return 0.0;

    
    float moy = tr->valeur;

    moy += moyenne(tr->fg);
    moy += moyenne(tr->fd);

    return moy;
}
AVLs* creerAVLs(float x){
  //Fonction qui prend en paramètre un entier et renvoie un AVLs
  AVLs *a=malloc(sizeof(AVL));
  a->fg=NULL;
  a->fd=NULL;
  a->equilibre=0;
  a->valeur=x;
  return a;
}

AVLs* rotationGaucheS(AVLs* a){
  //Fonction qui prend en paramètre un AVLs et effectue une rotation gauche
  AVLs* pivot;
  int eq_a, eq_p;
  pivot=a->fd;
  a->fd=pivot->fg;
  pivot->fg=a;
  eq_a=a->equilibre;
  eq_p=pivot->equilibre;
  a->equilibre=eq_a-max(eq_p,0)-1;
  pivot->equilibre=min(eq_a-2,eq_a+eq_p-2);
  pivot->equilibre=min(pivot->equilibre,eq_p-1);
  a=pivot;
  return a;
}
AVLs* rotationDroiteS(AVLs* a){
  //Fonction qui prend en paramètre un AVLs et effectue une rotation droite
  AVLs* pivot;
  int eq_a, eq_p;
  pivot=a->fg;
  a->fg=pivot->fd;
  pivot->fd=a;
  eq_a=a->equilibre;
  eq_p=pivot->equilibre;
  a->equilibre=eq_a-min(eq_p,0)+1;
  pivot->equilibre=max(eq_a+2,eq_a+eq_p+2);
  pivot->equilibre=max(pivot->equilibre,eq_p+1);
  a=pivot;
  return a;
}
AVLs* doubleRotationGaucheS(AVLs* a){
  //Fonction qui prend en paramètre un AVLs et effectue une double rotation gauche
  a->fd=rotationDroiteS(a->fd);
  return rotationGaucheS(a);
}
AVLs* doubleRotationDroiteS(AVLs* a){
  //Fonction qui prend en paramètre un AVLs et effectue une double rotation droite
  a->fg=rotationGaucheS(a->fg);
  return rotationDroiteS(a);
}
AVLs* equilibrageS(AVLs* a){
  //Fonction qui prend en paramètre un AVLs et qui equilibre si besoin cet AVLs
  if(a->equilibre>=2){
    if(a->fd->equilibre>=0){
      return rotationGaucheS(a);
    }
    else{
      return doubleRotationGaucheS(a);
    }
  }
  else if(a->equilibre<=-2){
    if(a->fg->equilibre<=0){
      return rotationDroiteS(a);
    }
    else{
      return doubleRotationDroiteS(a);
    }
  }
  return a;
}
AVLs* insertionAVLS(AVLs* a,float e,int* h){
  //Fonction qui prend en paramètres un AVLs un float et un pointeur sur un entier, qui insert un element dans l'AVLs passé en parametre et renvoie l'AVLs
  if(a==NULL){
    *h=1;
    return creerAVLs(e);
  }
  else if(e<a->valeur){
    a->fg=insertionAVLS(a->fg, e, h);
    *h=-*h;
  }
  else if(e>a->valeur){
    a->fd=insertionAVLS(a->fd, e, h);
  }
  else{
    *h=0;
    return a;
  }
  if(*h!=0){
    a->equilibre=a->equilibre+*h;
    a=equilibrageS(a);
    if(a->equilibre==0){
      *h=0;
    }
    else{
      *h=1;
    }
  }
  return a;
}

int main(int argc, char *argv[]){
  	 FILE *data = fopen("trajet.txt", "rwx");
  	 if (data == NULL) {
       //Si le fichier s'est mal ouvert/ pas ouvert
         	perror("Erreur lors de l'ouverture du fichier");
        	return 1;
    }
    	 char ligne[256];
    	 float tab[MAX];
    	 int nb = 0;
    	  while (fgets(ligne, sizeof(ligne), data) != NULL) {
          //Tant que le fichier n'est pas vide, transforme chaque chaine de caracteres en float
    	  	tab[nb] = atof(ligne);
    	  	nb++;
    	  }
          int h = 0;
          float maxAVL, minAVL, moyenneAVL;
          AVLs* tr = creerAVLs(tab[0]);
          for ( int i = 1; i < nb; i++) {
          	tr = insertionAVLS(tr, tab[i], &h); //insertion des données dans l'avl
          }
          AVLs* tmp1 = tr;
          AVLs* tmp2 = tr;
          while(tmp1->fg != NULL) //recupération du min
          	tmp1 = tmp1->fg;
          
          minAVL = tmp1->valeur;
          while(tmp2->fd != NULL) // max
          	tmp2 = tmp2->fd;
          	
          maxAVL = tmp2->valeur;
          
          moyenneAVL = moyenne(tr);
	  
	  FILE* fichierTemp = fopen("valeurs_temp.txt", "w");
    	  if (fichierTemp == NULL) {
          	perror("Erreur lors de la création du fichier temporaire");
          	exit(EXIT_FAILURE);
      	  }
      	  fprintf(fichierTemp, "%.2f %.2f %.2f", minAVL, maxAVL, moyenneAVL); //mit dans un fichier les valeurs de min max et moyenne
          fclose(fichierTemp);
    	  fclose(data);

    return 0;
  	
}
