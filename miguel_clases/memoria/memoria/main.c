#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    char auxNombre[31];
    float auxPeso;
    int algo;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {

        ultimoElementoArrayEmpleado++;
        printf("OK\n");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("El id es %d\n",auxInt);

        }
        if(!Emp_setPeso(pArrayEmpleado[indiceActual],50.50))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual],&auxPeso);
            printf("El peso es %.2f\n",auxPeso);
        }
        if(!Emp_setNombre(pArrayEmpleado[indiceActual],"juan"))
        {
            Emp_getNombre(pArrayEmpleado[indiceActual],auxNombre);
            printf("Nombre: %s\n",auxNombre);
        }

    }
    printf("indice 2 %d",indiceActual);
    if(pArrayEmpleado[indiceActual]!= NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(Emp_setNombre(pArrayEmpleado[indiceActual],"juanG"))
        {
            Emp_getNombre(pArrayEmpleado[indiceActual],auxNombre);
            printf("%d",emp_comprarNombre(pArrayEmpleado[indiceActual-1],pArrayEmpleado[indiceActual]));


        }
    }

    return 0;
}
