#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Structure des différents paramètres des différents systèmes dynamiques
typedef struct Param_Lorentz{
	double S;
	double P;
	double B;
}Param_Lorentz_s;



typedef struct Param_Rossler{
	double A;
	double B;
	double C;
}Param_Rossler_s;



typedef union Param{
	Param_Lorentz lorentz;
	Param_Rossler rossler;
}Param_s;



//Structure des paramètres
typedef struct Param_Lorentz * Param_Lorentz;
typedef struct Param_Rossler * Param_Rossler;
typedef union Param * Param;

//Remplissage des paramètres par leur valeur
Param setLorentz(Param_Lorentz L, Param P);
Param setRossler(Param_Rossler R, Param P);

Param setParamLorentz(Param param, double S, double P, double B);
Param setParamRossler(Param param, double A, double B, double C);

//Récupère les paramètres stockés
void get_Param_Lorentz(Param param, double *S, double *P, double *B);
void get_Param_Rossler(Param param, double *A, double *B, double *C);