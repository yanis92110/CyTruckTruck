#!/bin/bash


awk -F';' '{

    if ($2 == 1 && $3 != "") {
        VD[$3]++;
    }
    
    if ($4 != "") {
        VA[$4]++;
    }
}
END {
    for (element in VD) {
        resultat[element] += VD[element];
    }

    for (element in VA) {
        resultat[element] += VA[element];
    }

    for (element in resultat){
        if (VD[element] == "") {
            VD[element] = 0;
        }
        print element ";" resultat[element] ";" VD[element] > "resultat.csv";
    }
}' exp.csv

if [ $? -eq 0 ]; 
then
    echo "AWK a terminé avec succès."

    gcc -o t t.c

    if [ $? -eq 0 ]; then
        echo "Compilation de t.c réussie."

        ./t
    else
        echo "Erreur lors de la compilation de t.c."
    fi
else
    echo "Erreur lors de l'exécution de AWK."
fi

gnuplot <<- EOF

  reset

  set title "Les 10 villes les plus traversées"

  set output 'images/t.png'

  set datafile separator ";"

  set terminal png size 1000,1000

  set style data histogram

  set style histogram cluster

  set boxwidth 0.7

  set yrange [ 0 : * ]

  set xtics rotate

  set xlabel "Noms villes" font ",10"

  set ylabel "Nombres de routes" font ",10"

  set term png  size 900,800

  plot 't.txt' using 2:xticlabels(1) with boxes fill solid title 'Total trajets', \

  "" using 3 with boxes fill solid title 'Première ville'

EOF