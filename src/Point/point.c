#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/point.h"


//nouvelle coordonnees
Coordonnees Nouvellepose(float x, float y ,float z, float t){
    Coordonnees new_pose;
    new_pose=(Coordonnees)malloc(sizeof(Position));

    new_pose->x=x;
    new_pose->y=y;
    new_pose->z=z;
    new_pose->t=t;
    
    return new_pose;
} 


//Recuperer la valeur de x
float valeur_x(Coordonnees new_pose){
    float x=new_pose->x;
    return x;
}


//Recuperer la valeur de y
float valeur_y(Coordonnees new_pose){
    float y=new_pose->y;
    return y;
}


//Recuperer la valeur de z
float valeur_z(Coordonnees new_pose){
    float z=new_pose->z;
    return z;
}


//Recuperer la valeur de t
float valeur_t(Coordonnees new_pose){
    float t=new_pose->t;
    return t;
}


//Attracteur de Lorentz
