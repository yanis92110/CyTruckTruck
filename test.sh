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

if [[ -e "temp" ]]
then
	echo "temp existe"
else
	mkdir temp
	echo -e "création du dossier temp"
fi
if [[ -e "images" ]]
then
	echo "images existe"
else
	mkdir images
	echo -e "création du dossier images"
fi

nombreElements=$(ls -A "temp")
if [ -z "$nombreElements" ]
then
	echo "Le dossier temp est vide."
else
	echo "Le dossier temp n'est pas vide."
	find /home/vboxuser/shell/temp -mindepth 1 -delete
fi
if [[ -e "test" ]]
then
	echo "L'exécutable du .c existe"
else
	echo "L'exécutable du .c n'existe pas"
	#$compile_cmd
	gcc -o test test.c
	echo "exécutable crée"
fi
run_cmd="./test"
sleep 1

echo "vous avez choisi."
sleep 1
echo "."
sleep 1
echo "."
sleep 1
clear
echo ${1}
sleep 1
echo "Zé parti"
sleep 1

a='56'
b='56'

argv1="Salut la compagnie"
argv2="Mon gaté"
argv3="wsh neg"

case "${1}" in
-d1)
	echo -e "d1\n"
	bash d1.sh
;;
-d2)
	echo -e "d2\n"
	bash d2.sh
;;
-l)
	echo -e "-l\n"
;;
-t)
	echo -e "-t\n"
;;
-s)
	echo -e "-s\n"
;;
-h)
	echo -e "-h, voici les aides \n"
;;
*)
	echo -e "Arguments incorrects\n"
	exit 2
;;
esac

if (( $a != $b )) 
then 
	echo -e "Les deux variables sont differentes\n"

else
	echo -e "C'est les mêmes variables lets goooo\n"

fi

$run_cmd "$argv1" "$argv2" "$argv3"
if (( $? == 0 ))
then
	echo -e "Bonne execution du programme C\n"
else
	echo -e "Mauvaise éxécution \n"
fi
echo Fin du programme

exit 0