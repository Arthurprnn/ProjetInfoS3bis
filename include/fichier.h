#ifndef __FICHIER__
#define __FICHIER__

#include <stdio.h>
#include <stdlib.h>
#include "point.h"


void initialisation_fichier(FILE * fichier);    

int remplir_fichier(FILE* fichier, Coordonnees point );

#endif