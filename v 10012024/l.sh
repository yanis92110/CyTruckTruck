#!/bin/bash
temps_debut=$(date +%s.%N)
data="data.csv"
temp="temp"
colonne="$temp/colonned1.txt"
touch "$colonne"
tail -n +2 "$data" > "$colonne"

awk -F';' '{ somme[$1] += $5 } END { for (id in somme) print id, somme[id] }' "$colonne" | sort -t' ' -k2,2nr | head -n 10 | sort -t' ' -k1,1n

temps_fin=$(date +%s.%N)
temps_exec=$(echo "$temps_fin - $temps_debut" | bc)
echo "La durée a été de $temps_exec secondes."
