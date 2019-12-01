#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"



// Lecture d'un des types d'entrée, entré par l'utilisateur :



int lire_fin_ligne() {  
    int cpt=0;
    char c;
    
    c=getchar();
    while ((c!=EOF) && (c!='\n')) {
        
        if (!isspace(c)) {
            cpt+=1;
        }
        c=getchar();
    }
    
    return cpt;
}



int lire_entier(int *entier) {
    lit_format("%d", entier);
    return 0;
}



int lire_decimal(float *decimal) {
    lit_format("%f", decimal);
    return 0;
}



int lire_long_decimal(double *long_decimal) {
    lit_format("%lf", long_decimal);
    return 0;
}



int lire_chaine(char *chaine) {
    lit_format("%s", chaine);
    return 0;
}



void lit_format(char * format , void * a) {
    int nbLus;
    int nbJetes;
    
    do {
        nbLus=scanf(format, a);
        nbJetes=lire_fin_ligne();
    } while ((nbLus!=1) || (nbJetes!=0)) ;
    
}



int lire_entier_positif(int *entier_positif) {
    do {
        lire_entier(entier_positif);
    } while ((*entier_positif) < 0) ;
    return 0;
}



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
    printf("2 - Attracteur de Van der Pol\n");
    printf("3 - Attracteur de Rossler\n");
    printf("\nNB: - pour sélectionner votre choix, entrez le numéro correspondant\n");
    printf("    - si le numéro entré ne fait pas parti des choix proposés, alors le choix par défaut sera utilisé\n");
    printf("    - si il y a une erreur dans votre entrée, le programme vous demandera une autre entrée correcte\n");
    printf("\n");

    do {
        lire_entier_positif(choix);
    } while ((*choix==0) || (*choix>3));
    return 0;
}