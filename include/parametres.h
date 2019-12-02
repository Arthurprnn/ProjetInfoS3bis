#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



// Structure des différents paramètres des différents systèmes dynamiques
typedef struct Param_Lorenz{
	double S;
	double P;
	double B;
}Param_Lorenz_s;



typedef struct Param_Rossler{
	double A;
	double B;
	double C;
}Param_Rossler_s;



typedef union Param{
	Param_Lorenz lorenz;
	Param_Rossler rossler;
}Param_s;



//Structure des paramètres
typedef struct Param_Lorenz * Param_Lorenz;
typedef struct Param_Rossler * Param_Rossler;
typedef union Param * Param;

//Remplissage des paramètres par leur valeur
Param setLorenz(Param_Lorenz L, Param P);
Param setRossler(Param_Rossler R, Param P);

Param setParamLorenz(Param param, double S, double P, double B);
Param setParamRossler(Param param, double A, double B, double C);

//Récupère les paramètres stockés
void get_Param_Lorenz(Param param, double *S, double *P, double *B);
void get_Param_Rossler(Param param, double *A, double *B, double *C);