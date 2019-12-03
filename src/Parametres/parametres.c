#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/parametres.h"


//Fonctions assignant les paramètres du choix de l'utilisateur dans l'union
Param setLorenz(Param_Lorenz L, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->lorenz = (Param_Lorenz)L;
	return P;
}


Param setRossler(Param_Rossler R, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->rossler = (Param_Rossler)R;	
	return P;
}


//Récupère les paramètres stockés - Lorenz
void get_Param_Lorenz(Param param, double *S, double *P, double *B){
	(*S) = param->lorenz->S;
	(*P) = param->lorenz->P;
	(*B) = param->lorenz->B;
}


//Récupère les paramètres stockés - Rossler
void get_Param_Rossler(Param param, double *A, double *B, double *C){
	(*A) = param->rossler->A;
	(*B) = param->rossler->B;
	(*C) = param->rossler->C;
}


//Remplissage des paramètres des différents systèmes dynamiques
Param setParamLorenz(Param param, double B, double P, double S){
	Param_Lorenz parametersL;
	parametersL = (Param_Lorenz)malloc(sizeof(Param_Lorenz_s));
	
	parametersL->B = B;
	parametersL->P = P;
	parametersL->S = S;

	return setLorenz(parametersL,param);
}


Param setParamRossler(Param param, double A, double B, double C){
	Param_Rossler parametersR; 
	parametersR = (Param_Rossler)malloc(sizeof(Param_Rossler_s));

	parametersR->A = A;
	parametersR->B = B;
	parametersR->C = C;

	return setRossler(parametersR,param);

}