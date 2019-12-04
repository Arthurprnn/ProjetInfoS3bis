#include <stdio.h>
#include <stdlib.h>
#include "Entrees/entrees.c"
#include "Fichier/fichier.c"
#include "Parametres/parametres.c"
#include "Point/point.c"
#include "SystDym/systDym.c"
//include gnuplot.h


int main(int argc, char * argv []){

    const char DATA[128] = "../data/position.dat";
    int choix;
    Param parametres;
    double Tmax;
    double dt;                                    
    initialisation_fichier(DATA);
    choix_systeme(&choix);
    Coordonnees point = choix_position(choix);
    choix_dt(&dt);
    choix_Tmax(&Tmax);
    //parametres = choix_parametre(choix);
    FILE * fichier = NULL;
    fichier = fopen(DATA,"a");

    if (fichier != NULL){
        remplir_fichier(fichier, point);
        while (valeur_t(point) < Tmax){
            if (choix == 1){
                point = nouvelle_position_Lorentz(point, parametres, dt);
            }
            else {
                point = nouvelle_position_Rossler(point, parametres, dt);
            }
            remplir_fichier(fichier, point);
        }
        fclose(fichier);
    }
    else {
        printf("Erreur 404 : Impossible d'ouvrir le fichier Verolabest.dat");
    }
    //trace_courbe(choix);
    return 0; 

}