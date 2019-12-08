#!/bin/sh

#Permet de lancer un serveur X
$export DISPLAY=:0

#On lance Gnuplot
$gnuplot -persist ../data/Gnuplot/parametreLorentz.gnu