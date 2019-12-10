# ProjetInfoS3bis
Projet : Systèmes Dynamiques par Arthur Peresson et Théo Saint-Maxin


GUIDE D'UTILISATION de ce programme :


Il faut tout d'abord se placer dans le répertoire suivant :    /ProjetInfoS3/src/SystDym/

Pour lancer le programme, il faut entrer les commandes : $make clear
                                                         $make           (*)
                                                         $./main.exe
(cela ayant pour but d'être sur que tous se passera bien)

Le programme vous informe de tous ce que vous devrez entrer afin de tracer le système dynamique qui vous plaira.

Une fois toutes les données entrées, vous verrez apparaitre le système dynamique que vous avez choisi dans les conditions voulues.

Note : 
(*) Si le programme affiche une erreur pendant la commande $make, il faut alors regénérer les librairies des différents répertoires de src.
Il faut alors se rendre dans les répertoires dans l'ordre suivant :
    -Point
    -Entrees
    -Parametres
    -Fichier

Et faire pour chacun d'eux, les commandes : $make -f lib<répertoire>.mk clear
                                            $make clear
                                            $make -f lib<répertoire>.mk
                                            $make

Afin de s'assurer que la librairie soit générée et que les test compilent.
Une fois tous cela fait, il suffit de rendre à nouveau dans le répertoire :    /ProjetInfoS3/src/SystDym/
Et suivre de nouveau la procédure expliquée au-dessus.

(Cette note vient en parti du fait que des fois les librairies buggait après un $git pull, on à alors fait celà, et tous s'était alors remi à fonctionner normalement. On rentrait celà à chaque fois pour éviter de perdre du temps à essayer de chercher l'erreur alors qu'elle était sous notre nez...)