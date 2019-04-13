#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    float numeroIngresado;
    getFloat("Ingrese un numero flotante\n","Error", 80, 0, 3,&numeroIngresado);
    printf("El numero ingresado es: %f",numeroIngresado);
}

//fflush(stdin);
//_fpurge(stdin);

