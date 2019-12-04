#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/parametres.h"


//Fonctions assignant les paramètres du choix de l'utilisateur dans l'union
Param setLorentz(Param_Lorentz L, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->lorentz = (Param_Lorentz)L;
	return P;
}


Param setRossler(Param_Rossler R, Param P){
	P = (Param)malloc(sizeof(Param_s));
	P->rossler = (Param_Rossler)R;	
	return P;
}


//Récupère les paramètres stockés - Lorentz
void get_Param_Lorentz(Param param, double *S, double *P, double *B){
	(*S) = param->lorentz->S;
	(*P) = param->lorentz->P;
	(*B) = param->lorentz->B;
}


//Récupère les paramètres stockés - Rossler
void get_Param_Rossler(Param param, double *A, double *B, double *C){
	(*A) = param->rossler->A;
	(*B) = param->rossler->B;
	(*C) = param->rossler->C;
}


//Remplissage des paramètres des différents systèmes dynamiques
Param setParamLorentz(Param param, double S, double P, double B){
	Param_Lorentz parametersL;
	parametersL = (Param_Lorentz)malloc(sizeof(Param_Lorentz_s));
	
	parametersL->S = S;
	parametersL->P = P;
	parametersL->B = B;

	return setLorentz(parametersL,param);
}


Param setParamRossler(Param param, double A, double B, double C){
	Param_Rossler parametersR; 
	parametersR = (Param_Rossler)malloc(sizeof(Param_Rossler_s));

	parametersR->A = A;
	parametersR->B = B;
	parametersR->C = C;

	return setRossler(parametersR,param);

}