#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//structure de la Position
struct Coordonnees {                
    double x;
    double y;
    double z;
    double t;  // variable du temps
};


//Nom de la structure
typedef struct Coordonnees Position;
typedef struct Coordonnees* Coordonnees;


//nouvelle coordonnees
Coordonnees Nouvellepose(float x, float y ,float z, float t);


//Recuperer la valeur de x
float valeur_x(Coordonnees new_pose);


//Recuperer la valeur de y
float valeur_y(Coordonnees new_pose);


//Recuperer la valeur de z
float valeur_z(Coordonnees new_pose);


//Recuperer la valeur de t
float valeur_t(Coordonnees new_pose);