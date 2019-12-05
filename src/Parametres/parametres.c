#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/parametres.h"

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