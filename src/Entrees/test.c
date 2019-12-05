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

int main(int argc, char *argv[]) {

    int choix;
    double dt, Tmax;
    Param pp; 

    choix_systeme(&choix);
    choix_position(choix);
    
    dt = choix_dt();
    printf("dt = %lf\n", dt);
    
    Tmax = choix_Tmax();
    printf("Tmax = %lf\n", Tmax);
   
    pp = choix_parametre(choix);
    printf("Les paramètres sont : %lf %lf %lf\n", pp->S, pp->P, pp->B);


    return 0;
}