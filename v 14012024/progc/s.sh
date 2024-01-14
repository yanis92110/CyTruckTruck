#!/bin/bash

if [[ -e "s" ]]
then
  echo "L'exécutable du .c existe"
else
  echo "L'exécutable du .c n'existe pas"
  #$compile_cmd
  gcc -o s s.c
  echo "exécutable crée"
fi
run_cmds="./s"


temps_debut=$(date +%s.%N)
data="data.csv"
temp="temp"
colonne="$temp/colonnes.txt"
touch "$colonne"
tail -n +2 "$data" > "$colonne"
argv4="$colonne"
$run_cmds"argv4"

