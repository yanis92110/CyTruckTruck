#!/bin/bash
temps_debut=$(date +%s.%N)
data="data.csv"
temp="temp"
colonne="$temp/colonned2.txt"
touch "$colonne"
tail -n +2 "$data" > "$colonne"
awk -F';' '{ somme[$6] += $5 } END { for (chauffeur in somme) print chauffeur, somme[chauffeur] }' "$colonne" | sort -t' ' -k3,3nr | head -n 10
temps_fin=$(date +%s.%N)
temps_exec=$(echo "$temps_fin - $temps_debut" | bc)
echo "La durée a été de $temps_exec secondes."
