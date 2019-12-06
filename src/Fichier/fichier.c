#include <stdio.h>
#include <stdlib.h>
#include "../../include/fichier.h"
#include "../../include/point.h"


void init_fichier(const char * FICHIER){

  FILE* f = NULL;
  f = fopen(FICHIER,"w+");
  fclose(f);
}


//Remplit le fichier avec les valeurs du point
int remplir_fichier(FILE* fichier, Coordonnees point ){
    fprintf(fichier, "%f %f %f %f\n", valeur_t(point), valeur_x(point), valeur_y(point), valeur_z(point));
    return 0;
}