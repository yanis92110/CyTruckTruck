#!/bin/bash
temps_debut=$(date +%s.%N)
data="data/data.csv"
temp="temp"
colonne="$temp/colonned2.txt"
d2="$temp/d2.csv"
touch "$d2"
touch "$colonne"
tail -n +2 "$data" > "$colonne"
awk -F';' '{ somme[$6] += $5 } END { for (chauffeur in somme) print chauffeur, somme[chauffeur] }' "$colonne" | sort -t' ' -k3,3nr | head -n 10 >> $d2 


gnuplot <<- EOF
    reset
    set terminal pngcairo size 1000,900
    set output 'temp/d2.png'
    set style data histogram
    set boxwidth 0.7
    set style fill solid
    set link y2
    set xtics rotate out
    set y2tics rotate out
    set y2range [ 0 : * ]
    set ytics nomirror
    unset ytics # desactivation de l'axe y1 pour utiliser l'axe y2.
    set xtics  font ",9"
    set y2tics font ",9"
    set y2label "distance totale parcourue" font ",10"
    set ylabel "Option -d2 conducteurs et la plus grande distance" font ",10"
    set xlabel "noms des conducteurs" rotate by 180 font ",10"
    set term png  size 900,800
    plot 'temp/d2.csv' using 0:xticlabels(strcol(1)." ".strcol(2)) notitle with boxes axes x2y1
EOF

convert temp/d2.png -rotate 90 images/d2.png

temps_fin=$(date +%s.%N)
temps_exec=$(echo "$temps_fin - $temps_debut" | bc)
echo "La durée a été de $temps_exec secondes."
