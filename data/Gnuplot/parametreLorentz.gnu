#set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 600, 400 
set terminal wxt size 350,262 enhanced font 'Verdana,10' 
#set output 'Lorenz.1.png'

set parametric
splot "../position.dat" using 2:3:4 

#pause jusqu'à ce que ENTER soit tapé dans le terminal
pause -1