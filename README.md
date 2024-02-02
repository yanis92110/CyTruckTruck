# CyTruckTruck

Notre programme CyTruckTruck permet de lire les données d'un fichier 'data.csv" de 5 manières différentes:

## -d1

Le traitement d1 affiche les 10 conducteurs qui ont effectué le plus de trajets.

## -d2

Le traitement d2 affiche les 10 conducteurs qui ont parcouru le plus de distance.

## -l

Le traitement l affiche les 10 trajets les plus longs.

## -t

Le traitement t affiche les 10 villes les plus traversées.

## -s

Le traitement s affiche les différentes statistiques sur les étapes.

## -h

Le traitement h affiche tous les différents traitements existants, c'est la fonction -help du programme.

# Utilisation

0. Le dossier racine du projet qui est à utiliser est le dossier 'CyTruckTruckFinale'

1. Compilation des fichiers .c et .h

Ouvrir un terminal dans le dossier 'progc' puis executer la comande 'make'.

2. Lancement de l'application

Ouvrir un terminal dans le dossier racine et écrire la commande 'bash main.sh data/data.csv -OPTIONS', ou OPTIONS prend les différents traitements. (d1, d2, l, s, t, h)

Par exemple pour lancer le traitement l qui affiche les 10 trajets les plus longs, écrire la commande:

'bash main.sh data/data.csv -l'
