#!/bin/bash
temps_debut=$(date +%s.%N)
data="data/data.csv"
temp="temp"
colonne="$temp/colonned1.txt"
d1="$temp/d1.csv"
touch "$d1"
touch "$colonne"
cut -d ';' -f 6 $data < $colonne | sort | uniq -c | sort -nr | head -n 10 >> $d1 
#cat $colonne >> $d1
gnuplot <<- EOF
    reset
    set terminal pngcairo size 1000,900
    set output 'temp/d1.png'
    set style data histogram
    set boxwidth 0.7
    set style fill solid
    set xtics rotate out
    set y2tics rotate out 
    set y2range [ 0 : * ]
    set ytics nomirror
    unset ytics # desactivation de l'axe y1 pour utiliser l'axe y2.
    set xtics  font ",9"
    set y2tics font ",9"
    set y2label "NB ROUTES" font ",10"
    set ylabel "Option -d1 : Nombre de trajets par conducteurs" font ",10"
    set xlabel "noms des conducteurs" rotate by 180 font ",10"
    set term png  size 900,800
    plot 'temp/d1.csv' using 0:1:xticlabels(strcol(2)." ".strcol(3)) notitle with boxes axes x1y2
EOF

convert temp/d1.png -rotate 90 images/d1.png

temps_fin=$(date +%s.%N)
temps_exec=$(echo "$temps_fin - $temps_debut" | bc)
echo "La durée a été de $temps_exec secondes."


