#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/parametres.h"
#include "../../include/entrees.h"

//Remplissage des paramètres des différents systèmes dynamiques
Param setParam(double S, double P, double B){
	Param parametre;
	parametre = (Param)malloc(sizeof(SParam));
	
	parametre->S = S;
	parametre->P = P;
	parametre->B = B;

	return parametre;
}


//Récupère les paramètres stockés
void getParam(Param param, double *S, double *P, double *B){
	(*S) = param->S;
	(*P) = param->P;
	(*B) = param->B;
}


Param choix_parametre (int choix) {
    double S;
    double P;
    double B;
    int g;
    
    printf("D'après votre choix, on peut vous proposer les paramètres par défaut.\n");
    printf("Veuillez entrer le numéro correspondant à votre choix :\n");
    printf("\n");
    printf("    0 - Paramètres par défaut\n");
    printf("    1 - Paramètres de votre choix\n");
    printf("\n");

    if (choix==1) {        // Choix de l'attracteur de Lorentz
        
        Param pLorentz;

        do {
            lire_entier_positif(&g);
        } while ((g<0) || (g>1));

        if (g==0) {
            S=10;
            P=28;
            B=2.666666667;
            printf("Les paramètres par défaut sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }
        else {
            printf("Entrez les paramètres de votre choix : \n");

            printf("S = ");
            lire_long_decimal(&S);
            printf("P = ");
            lire_long_decimal(&P);
            printf("B = ");
            lire_long_decimal(&B);
            printf("Les paramètres choisis sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }
        pLorentz = setParam(S,P,B);
        return pLorentz;
    }
    else {        // Choix de l'attracteur de Rossler
        
        Param pRossler;

        do {
            lire_entier_positif(&g);
        } while ((g<0) || (g>1));

        if (g==0) {
            S=0.1;
            P=0.1;
            B=14;
            printf("Les paramètres par défaut sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }
        else {
            printf("Entrez les paramètres de votre choix : \n");
            printf("A = ");
            lire_long_decimal(&S);
            printf("B = ");
            lire_long_decimal(&P);
            printf("C = ");
            lire_long_decimal(&B);

            printf("Les paramètres choisis sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }

        pRossler = setParam(S,P,B);
        return pRossler;
    }
}