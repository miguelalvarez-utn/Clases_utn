#include <stdio.h>
#include <stdlib.h>
#include "Mis_Prototipos.h"
#define CANTIDAD_PERSONAS 5


int main()
{

    float resultadoIngresado;
    getFloat("ingrese un numero\n","Error, no es un numero valido\n",80,1,3,&resultadoIngresado);

    printf("%.2f",resultadoIngresado);

    return 0;
}




