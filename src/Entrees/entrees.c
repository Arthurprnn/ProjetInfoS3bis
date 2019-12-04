#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"
#include "../../include/point.h"
#include "../../include/parametres.h"
#define DT_MIN 0.0005
#define DT_MAX 0.01
#define TMIN 10
#define TMAX 5000



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


int lire_long_decimal_positif(int *long_decimal_positif) {
    do {
        lire_long_decimal(long_decimal_positif);
    } while ((*long_decimal_positif) < 0) ;
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
        } while ((g!=0) || (g!=1));

        if (g==0) {
            x=1;
            y=2;
            z=3;
            printf("Les positions initiales par défaut sont à t=0 : x=%lf y=%lf z=%lf\n", x, y, z);
        }
        else {
            printf("Entrez les positions initiales de votre choix : \n");
            lire_long_decimal(&x);
            lire_long_decimal(&y);
            lire_long_decimal(&z);
            printf("Les positions initiales choisies sont à t=0 : x=%lf y=%lf z=%lf\n", x, y, z);
        }
    }
    else {        // Choix de l'attracteur de Rossler
        
        do {
            lire_entier_positif(&g);
        } while ((g!=0) || (g!=1));

        if (g==0) {
            x=0.1;
            y=0.1;
            z=14;
            printf("Les positions initiales par défaut sont à t=0 : x=%lf y=%lf z=%lf\n", x, y, z);
        }
        else {
            printf("Entrez les positions initiales de votre choix : \n");
            
            lire_long_decimal(&x);
            lire_long_decimal(&y);
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
    } while ((g!=0) || (g!=1));

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
    } while ((g!=0) || (g!=1));

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
        
        Param_Lorentz pLorentz;

        do {
            lire_entier_positif(&g);
        } while ((g!=0) || (g!=1));

        if (g==0) {
            S=10;
            P=28;
            B=8/3;
            printf("Les paramètres par défaut sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }
        else {
            printf("Entrez les paramètres de votre choix : \n");
            lire_long_decimal(&S);
            lire_long_decimal(&P);
            lire_long_decimal(&B);
            printf("Les paramètres choisis sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }
        setParamLorentz(pLorentz,S,P,B);
        return pLorentz;
    }
    else {        // Choix de l'attracteur de Rossler
        
        Param_Rossler pRossler;

        do {
            lire_entier_positif(&g);
        } while ((g!=0) || (g!=1));

        if (g==0) {
            S=0.1;
            P=0.1;
            B=14;
            printf("Les paramètres par défaut sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }
        else {
            printf("Entrez les paramètres de votre choix : \n");
            
            lire_long_decimal(&S);
            lire_long_decimal(&P);
            lire_long_decimal(&B);

            printf("Les paramètres choisis sont : S=%lf P=%lf B=%lf\n", S, P, B);
        }

        setParamRossler(pRossler,S,P,B);
        return pRossler;
    }
}