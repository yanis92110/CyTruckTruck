#!/bin/bash
temps_debut=$(date +%s.%N)
data="data/data.csv"
temp="temp"
colonne="$temp/colonnel.txt"
l="$temp/l.csv"
touch "$l"
touch "$colonne"
tail -n +2 "$data" > "$colonne"

awk -F';' '{ somme[$1] += $5 } END { for (id in somme) print id, somme[id] }' "$colonne" | sort -t' ' -k2,2nr | head -n 10 | sort -t' ' -k1,1n >> $l 

gnuplot <<- EOF
        reset

    set terminal pngcairo size 1000,900
    set output 'temp/l.png'
    set style data histograms
    set boxwidth 0.7
    set style fill solid
    set xtics rotate out
    set y2tics rotate out 
    set y2range [ 0 : * ]
    set ytics nomirror
    unset ytics # désactivation de l'axe y1 pour utiliser l'axe y2.
    set xtics font ",9"
    set y2tics font ",9"
    set y2label "distance (km)" font ",10"
    set ylabel "Traitement -l : Les 10 trajets les plus longs" font ",10"
    set xlabel "identifiant des trajets" rotate by 180 font ",10"
    set term png size 900,800
    

   plot 'temp/l.csv' using 2:xticlabels(1) notitle with boxes axes x1y2
EOF

temps_fin=$(date +%s.%N)
temps_exec=$(echo "$temps_fin - $temps_debut" | bc)
echo "La durée a été de $temps_exec secondes."
