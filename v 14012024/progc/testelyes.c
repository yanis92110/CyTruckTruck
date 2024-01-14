#include "header.h"


int verif_ID(Trajet *pID, int ID)
{
    // vérifie si l'ID du trajet a déjà été rencontré
    // en cherchant dans l'AVL chainée des ID rencontrés

    
}

void readCities()
{
  
    FILE* fichier = fopen("test.txt","r");
    char cityName[23];
    int current = 0;
    int nbComma = 0;
    int i = 0;

    if (fichier != NULL)
    {
        rewind(fichier);
        do 
        {
            if (nbComma == 2)
            {
              //mais la le getc ne bouge jamais nn ? sauf si getc efface le caractere YANIS
                current = getc(fichier);
                cityName[i] = current;
                i ++;
                
            }else if (nbComma == 3)
            {
                //prendre le contenu de cityName et le mettre dans une liste chainée des villes de départ
                i = 0;
                current = getc(fichier);
                cityName[i] = current;
                //ajouter à la liste chainée des villes d'arrivée rencontrées
                i ++;
                
            }else 
            {
                current = fgetc(fichier);
                if (current == ',')
                {
                    nbComma ++;
                }
            }
            
        }while(nbComma!=4);

        fclose(fichier);
    }
    else
    {
        printf("Error !\n");
    }

}

Trajet* create_list()
{
    Trajet *pID = malloc(sizeof(Trajet));

    return pID;
}

Trajet* add_ID(Trajet* pID)
{
    
    
    return pID;
}


int main()
{
    Trajet *pID = create_list();
    
    return 0;
}


