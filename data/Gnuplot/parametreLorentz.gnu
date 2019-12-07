set parametric
set title textcolor "red" "Attracteur de Lorenz"
set grid
set xlabel "x"
set ylabel "y"
set zlabel offset +5 +4 "z"

h1 = -50/360.0
h2 = 227/360.0
set palette model HSV functions (1-gray)*(h2-h1)+h1,1,0.68

load "../position.dat"
splot "../position.dat" title "" u 2:3:4:1 w l lc palette
pause -1 "Tapez \"Entrez\" pour fermer la fenetre"