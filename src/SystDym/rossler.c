#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/parametres.h"
#include "../../include/rossler.h"



//Calcul position Rossler
Coordonnees nouvelle_position_Rossler(Coordonnees coo, Param parametre, double dt){
    double A;
    double B;
    double C;
    double nouveau_x;
    double nouveau_y;
    double nouveau_z;
    double nouveau_t;

    getParam(parametre, &A, &B, &C);
    nouveau_x = valeur_x(coo) +(-valeur_y(coo) -valeur_z(coo) ) * dt;
    nouveau_y = valeur_y(coo) + ( valeur_x(coo) + A * valeur_y(coo) ) * dt;
    nouveau_z = valeur_z(coo) + ( B + valeur_z(coo) * (valeur_x(coo) - C ) ) *dt;
    nouveau_t = valeur_t(coo) + dt;

    coo = Nouvellepose(nouveau_x, nouveau_y, nouveau_z, nouveau_t);
    
    return coo;
}