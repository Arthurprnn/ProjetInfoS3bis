#ifndef __FICHIER__
#define __FICHIER__

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

void init_fichier(const char * FICHIER);
int remplir_fichier(FILE* fichier, Coordonnees point );

#endif