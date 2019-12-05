#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/point.h"

int main(int argc, char *argv[]) {

    double x, y ,z ,t;
    x=5.2;
    y=4.2;
    z=1.2;
    t=2;
    Coordonnees ccc;

    ccc = Nouvellepose(x,y,z,t);
    printf("%lf %lf %lf %lf\n", valeur_x(ccc), valeur_y(ccc), valeur_z(ccc), valeur_t(ccc));

    return 0;
}