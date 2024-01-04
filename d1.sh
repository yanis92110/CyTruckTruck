#!/bin/bash
temps_debut=$(date +%s.%N)
data="data.csv"
temp="temp"
colonne="$temp/colonned1.txt"
touch "$colonne"
cut -d ';' -f 6 data.csv < $colonne | sort | uniq -c | sort -nr | head -n 10
cat $colonne
temps_fin=$(date +%s.%N)
temps_exec=$(echo "$temps_fin - $temps_debut" | bc)
echo "La durée a été de $temps_exec secondes."

