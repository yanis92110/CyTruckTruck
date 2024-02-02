#!/bin/bash

executed="$0"

#compile_cmd=$(make)



echo Debut du programme



clear

echo -e "Bienvenue sur CY Truck\n"

sleep 1

clear



echo "Vérifications des prérequis"

sleep 1

echo "."

sleep 1

echo "."

sleep 1

if [ $# -ge 1 ]; then
    # vérifier si le premier argument est égal à "data.csv"
    if [ "$1" = "data/data.csv" ]; then
        echo "Data.csv détecté"
    else
        echo "Data.csv non détecté"
        sleep 1
        echo "Arrêt du programme"
        sleep 0.5
        exit
    fi
else
    echo "Aucun argument"
    sleep 1
    
    echo"Arrêt du programme"
    
    sleep 0.5
    exit
    
fi

if [[ -e "temp" ]] #vérifie si temp existe

then

	echo "temp existe"

else

	mkdir temp

	echo -e "création du dossier temp"

fi

if [[ -e "images" ]] #vérifie si images existe

then

	echo "images existe"

else

	mkdir images

	echo -e "création du dossier images"

fi



nombreElements=$(ls -A "temp") #compte le nombre d'éléments dans temp

if [ -z "$nombreElements" ] #si temp est vide

then

	echo "Le dossier temp est vide."

else

	echo "Le dossier temp n'est pas vide."

  	rm -rf temp/* #on vide temp
  	echo "Le dossier temp a été vidé"

fi

if [[ -e "progc/main" ]] #vérifie si l'exe du .c existe

then

	echo "L'exécutable du .c existe"

else

	echo "L'exécutable du .c n'existe pas"

	#$compile_cmd

	gcc -o main main.c

	echo "exécutable crée"

fi

run_cmd="./progc/main"

sleep 1

for arg in "$@"; do
    				# vérifie si l'argument est égal à -h
    if [ "$arg" = "-h" ]; then
        echo "L'argument -h a été détecté. Affichage de l'aide."
        sleep 1

	echo "TRAITEMENT [D1] : conducteurs avec le plus de trajets : option -d1"

	echo "TRAITEMENT [D2] : conducteurs et la plus grande distance: option -d2"

	echo "TRAITEMENT [L] : les 10 trajets les plus longs : option -l"

	echo "TRAITEMENT [T] : les 10 villes les plus traversées : option -t"

	echo "Traitement [S] : statistiques sur les étapes : option -s"
        exit 1
    fi
done

echo "vous avez choisi."

sleep 1

echo "."

sleep 1

echo "."

sleep 1

clear

echo ${2}

sleep 1

echo "C'est parti"

sleep 1


while [[ $# -gt 0 ]]; do
	case "${2}" in

	-d1)

		echo -e "Traitement -d1 en cours...\n"

		bash d1.sh #execution de -d1

	;;

	-d2)

		echo -e "Traitement -d2 en cours...\n"

		bash d2.sh #execution de -d2

	;;

	-l)

		echo -e "Traitement -l en cours...\n"

		bash l.sh #execution de -l

	;;

	-t)

		echo -e "Traitement -t en cours...\n"
		
		bash t.sh #execution de -t
	;;

	-s)

		echo -e "Traitement -s en cours...\n"

		bash s.sh #execution de -s

	;;

	-h)

		echo -e "-h, voici les aides \n"

		sleep 1

		echo "TRAITEMENT [D1] : conducteurs avec le plus de trajets : option -d1"

		echo "TRAITEMENT [D2] : conducteurs et la plus grande distance: option -d2"

		echo "TRAITEMENT [L] : les 10 trajets les plus longs : option -l"

		echo "TRAITEMENT [T] : les 10 villes les plus traversées : option -t"

		echo "Traitement [S] : statistiques sur les étapes : option -s"

	;;
	
	*)
		if [[ ${2} -eq ${9} ]]; then
		
                	echo "Argument vide. Arrêt de la boucle."
                	sleep 0.5
                	break
                fi
                
		echo -e "Arguments incorrects\n" 

		exit 2 #on quitte le programme car pas d'arguments valables

	;;

	esac
	shift
done


if (( $? == 0 )) #vérifie la valeur de sortie des traitements

then

	echo -e "Bonne execution du programme\n"

else

	echo -e "Mauvaise éxécution \n"

fi


echo Fin du programme


exit 0
