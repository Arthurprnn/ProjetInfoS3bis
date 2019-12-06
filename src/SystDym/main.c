#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"
#include "../../include/point.h"
#include "../../include/parametres.h"
#include "../../include/fichier.h"
#include "../../include/lorentz.h"
#include "../../include/rossler.h"


//include gnuplot.h
#define DT_MIN 0.0005
#define DT_MAX 0.01
#define TMIN 10
#define TMAX 5000




// Lecture du choix du système dynamique :
int choix_systeme(int * choix) {
    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("                                           SYSTEMES                                             \n");
    printf("                                          DYNAMIQUES                                            \n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\tBienvenue dans ce projet !\n");
    printf("\n\tAvant de commencer, veuillez choisir le système dynamique (attracteur) \n");
    printf("que vous souhaitez modéliser parmi nos 3 possibilités : \n");
    printf("\n");
    printf("1 - Attracteur de Lorentz (défaut)\n");
    printf("2 - Attracteur de Rossler\n");
    printf("\nNB: - pour sélectionner votre choix, entrez le numéro correspondant\n");
    printf("    - si il y a une erreur dans votre entrée, le programme vous demandera une autre entrée correcte\n");
    printf("\n");

    do {
        lire_entier_positif(choix);
    } while ((*choix==0) || (*choix>2));
    return 0;
}


Coordonnees choix_position(int choix) {
    double x;
    double y;
    double z;
    double t=0;
    int g;
    
    printf("D'après votre choix, on peut vous proposer les positions par défaut.\n");
    printf("Veuillez entrer le numéro correspondant à votre choix :\n");
    printf("\n");
    printf("    0 - Positions initiales par défaut\n");
    printf("    1 - Positions initiales de votre choix\n");
    printf("\n");

    if (choix==1) {        // Choix de l'attracteur de Lorentz
        
        do {
            lire_entier_positif(&g);
        } while ((g<0) || (g>1));

        if (g==0) {
            x=1;
            y=2;
            z=3;
            printf("Les positions initiales par défaut sont à t=0 : x=%lf y=%lf z=%lf\n", x, y, z);
        }
        else {
            printf("Entrez les positions initiales de votre choix : \n");
            printf("x = ");
            lire_long_decimal(&x);
            printf("y = ");
            lire_long_decimal(&y);
            printf("z = ");
            lire_long_decimal(&z);
            printf("Les positions initiales choisies sont à t=0 : x=%lf y=%lf z=%lf\n", x, y, z);
        }
    }
    else {        // Choix de l'attracteur de Rossler
        
        do {
            lire_entier_positif(&g);
        } while ((g<0) || (g>1));

        if (g==0) {
            x=0.1;
            y=0.1;
            z=14;
            printf("Les positions initiales par défaut sont à t=0 : x=%lf y=%lf z=%lf\n", x, y, z);
        }
        else {
            printf("Entrez les positions initiales de votre choix : \n");
            
            printf("x = ");
            lire_long_decimal(&x);
            printf("y = ");
            lire_long_decimal(&y);
            printf("z = ");
            lire_long_decimal(&z);

            printf("Les positions initiales choisies sont à t=0 : x=%lf y=%lf z=%lf\n", x, y, z);
        }
    }
    return Nouvellepose(t,x,y,z);
}



double choix_dt() {
    double dt=0.01;
    int g;

    printf("Rentrez le numéro correspondant à un choix de dt :\n");
    printf("    0 - dt=0.01 par défaut\n");
    printf("    1 - dt que vous souhaitez appartenant à [0.0005 ; 0.01]\n");
    printf("\n");

    do {
        lire_entier_positif(&g);
    } while ((g<0) || (g>1));

    if (g==1) {
        printf("Entrez le dt que vous souhaitez : \n");
        lire_long_decimal_positif(&dt);
        if ((dt<DT_MIN) || (dt>DT_MAX)) {
            printf("Vous avez choisi une valeur de dt en dehors des bornes. dt prend alors la valeur par défaut.\n");
            dt=0.01;
        }
    }
    return dt;
}


double choix_Tmax() {
    double Tmax=2000;
    int g;

    printf("Rentrez le numéro correspondant à un choix de Tmax :\n");
    printf("    0 - Tmax=2000 par défaut\n");
    printf("    1 - Tmax que vous souhaitez appartenant à [10 ; 5000]\n");
    printf("\n");

    do {
        lire_entier_positif(&g);
    } while ((g<0) || (g>1));

    if (g==1) {
        printf("Entrez le Tmax que vous souhaitez : \n");
        lire_long_decimal_positif(&Tmax);
        if ((Tmax<TMIN) || (Tmax>TMAX)) {
            printf("Vous avez choisi une valeur de Tmax en dehors des bornes. Tmax prend alors la valeur par défaut.\n");
            Tmax=2000;
        }
    }
    return Tmax;
}






int main(int argc, char * argv []){

    const char DATA[128] = "../data/position.dat";
    int choix;
    Param parametres;
    double Tmax;
    double dt;                                    
    choix_systeme(&choix);
    Coordonnees point = choix_position(choix);
    dt = choix_dt();
    Tmax = choix_Tmax();
    parametres = choix_parametre(choix);
    FILE * fichier = NULL;
    fichier = fopen(DATA,"a");

    if (fichier == NULL){
        //remplir_fichier(fichier, point);
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
        printf("Erreur 404 : Impossible d'ouvrir le fichier Verolabest.dat\n");
    }
    //trace_courbe(choix);
    if (choix==1) {
        system("./lorenz.sh");
    }
    else {
        system("./rossler.sh");
    }
    return 0; 

}