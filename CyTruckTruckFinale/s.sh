#!/bin/bash





if [[ -e "progc/s" ]]

then

  echo "L'exécutable du .c existe"

else

  echo "L'exécutable du .c n'existe pas"

  #$compile_cmd

  cd progc

  gcc -o s s.c

  echo "exécutable crée"

  cd ..

fi

run_cmds="./progc/s"





temps_debut=$(date +%s.%N)

data="data/data.csv"

temp="temp"

colonne="$temp/colonnes.txt"

ids="$temp/ids.txt"

touch "$colonne"

touch "$ids"

valeurs="$temp/valeurs.csv"



cut -d ';' -f 1,5 "$data" > $colonne

cut -d ';' -f 1 "$data" > $ids

awk '!seen[$0]' $ids > /dev/null

sed -i '1d' "$colonne"

sed -i '1d' "$ids"


while [ -s "$ids" ]; do

	id_trajet=$(head -n 1 "$ids")

	awk -F';' -v id_trajet="$id_trajet" '$1 == id_trajet' "$colonne" > "temp/trajet_$id_trajet.txt"

	trajet="temp/trajet_$id_trajet.txt"

	cut -d ';' -f 2 "$trajet" > "temp/trajet.txt"

	$run_cmds "temp/trajet.txt"

	cat "valeurs_temp.txt" >> "$valeurs"

	echo "" >> "$valeurs"

	rm "valeurs_temp.txt"

	rm "temp/trajet_$id_trajet.txt"

	rm "temp/trajet.txt"

	sed -i '1d' "$ids"

done



gnuplot <<EOF

	set terminal png size 800,600

	set output 'images/s.png'

	set title "Statistiques des distances par trajet"

	set xlabel "Identifiants"

	set ylabel "distances"

	set key left top

	set style line 1 lc rgb 'blue' lt 1 lw 4 pt 7 ps 1.5

	set style line 2 lc rgb 'red' lt 1 lw 4 pt 11 ps 1.5

	set style line 3 lc rgb 'green' lt 1 lw 4 pt 9 ps 1.5

	plot "temp/valeurs.csv" using 1 with lines ls 1 title 'Min', \

     	"" using 2 with lines ls 3 title 'Moyenne', \

     	"" using 3 with lines ls 2 title 'Max'

EOF



temps_fin=$(date +%s.%N)

temps_exec=$(echo "$temps_fin - $temps_debut" | bc)

echo "La durée a été de $temps_exec secondes."

