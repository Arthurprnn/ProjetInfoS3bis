#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/parametres.h"

int main(int argc, char *argv[]) {
    double S, P ,B;
    S=2;
    P=8;
    B=4.5;
    Param dd;
    dd = setParam(S, P, B);

    double a, b, c;
    getParam(dd, &a, &b, &c);
    printf("%lf %lf %lf\n", a, b ,c);
    return 0;
}