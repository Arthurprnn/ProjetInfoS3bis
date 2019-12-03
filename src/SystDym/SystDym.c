#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../Point/point.c"
#include "../Parametres/parametres.c"


//Calcul position Lorentz
Coordonnees nouvelle_position_Lorentz(Coordonnees coo, Param parametre, double dt){
    double S;
    double P;
    double B;
    double nouveau_x;
    double nouveau_y;
    double nouveau_z;
    double nouveau_t;

    get_Param_Lorenz(parametre, &S, &P, &B);
    nouveau_x = valeur_x(coo) +( S * (valeur_y(coo) - valeur_x(coo)) ) * dt;
    nouveau_y = valeur_y(coo) + ( valeur_x(coo) * (P - valeur_z(coo)) - valeur_y(coo) ) * dt;
    nouveau_z = valeur_z(coo) + ( valeur_x(coo) * valeur_y(coo) - B * valeur_z(coo) ) *dt;
    nouveau_t = valeur_t(coo) + dt;

    coo = Nouvellepose(nouveau_x, nouveau_y, nouveau_z, nouveau_t);
    
    return coo;
}



//Calcul position Rossler
Coordonnees nouvelle_position_Rossler(Coordonnees coo, Param parametre, double dt){
    double A;
    double B;
    double C;
    double nouveau_x;
    double nouveau_y;
    double nouveau_z;
    double nouveau_t;

    get_Param_Rossler(parametre, &A, &B, &C);
    nouveau_x = valeur_x(coo) +(-valeur_y(coo) -valeur_z(coo) ) * dt;
    nouveau_y = valeur_y(coo) + ( valeur_x(coo) + A * valeur_y(coo) ) * dt;
    nouveau_z = valeur_z(coo) + ( B + valeur_z(coo) * (valeur_x(coo) - C ) ) *dt;
    nouveau_t = valeur_t(coo) + dt;

    coo = Nouvellepose(nouveau_x, nouveau_y, nouveau_z, nouveau_t);
    
    return coo;
}

