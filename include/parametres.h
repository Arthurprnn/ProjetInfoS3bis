#ifndef __PARAMETRES__
#define __PARAMETRES__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Structure des différents paramètres des différents systèmes dynamiques
typedef struct Param_s{
	double S;
	double P;
	double B;
}SParam;

//Structure des paramètres
typedef SParam * Param;


//Récupère les paramètres stockés
void getParam(Param param, double *S, double *P, double *B);


//Remplissage des paramètres par leur valeur
Param setParam(double S, double P, double B);


Param choix_parametre (int choix);

#endif