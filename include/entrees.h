#ifndef __ENTREES__
#define __ENTREES__

#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "parametres.h"


int lire_fin_ligne();

int lire_entier(int *entier);

int lire_decimal(float *decimal);

int lire_long_decimal(double *long_decimal);

int lire_chaine(char *decimal);

void lit_format(char * format , void * a);

int lire_entier_positif(int *entier_positif);

int lire_long_decimal_positif(int *long_decimal_positif);

int choix_systeme(int * choix);

Coordonnees choix_position(int choix);

double choix_dt();

double choix_Tmax();

Param choix_parametre (int choix);

#endif