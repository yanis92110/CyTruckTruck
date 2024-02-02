#include "header.h"

int main() {
    AVL* a = malloc(sizeof(AVL));
    int compt = 0; 

    char villes[TOP10][TAILLE];

    lire_resultats(&a);
    plus_visitees(a, &compt, villes); 

    printf("Les 10 villes les plus visitées sont :\n");
    for (int i = 0; i < compt; i++) { 
        printf("%s\n", villes[i]);
    }

    viderAVL(a);

    return 0;
}