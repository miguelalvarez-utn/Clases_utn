#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_ALUMNOS 10


int getArrayInt(char* mensaje,
                char* mensajeError,
                int maximo,
                int minimo,
                int reintentos,
                int* arrayResultado,
                int limite);

int main()
{

/*
    int *pEdades;
    int bufferEdad;
    int aEdades[CANTIDAD_ALUMNOS];
    aEdades[100] = 22;// a la posicion 100 le asigno el 22
    bufferEdad = aEdades[100];//se le asigna a buffer edad lo que hay en la possicion 100
    pEdades = &aEdades[1];// como en este caso si no quiero el saber el primer elemento, esta es la opcion

    pEdades = aEdades;// pEdades recibe el primer elemento de aEdades.
    pEdades[88] = 11;
    *(pEdades+88) = 11;// me corro 88 lugares desde la posicion donde estoy y le asigno el valor 11
    *pEdades+88;// cuidado con los (), esto es el elemento que hay en la posicion 0 de array + 88.
  */

    int aEdades[CANTIDAD_ALUMNOS];

    getArrayInt("Ingrese las edades","Error", 80, 1, 3, aEdades,10);
}

int getArrayInt(char* mensaje, char* mensajeError, int maximo, int minimo, int reintentos, int* arrayResultad
o, int limite)
{
    int retorno = -1;
    int buffer;
    int i;

    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos >= 0 && limite > 0)
    {
        for(i = 0; i < CANTIDAD_ALUMNOS; i++)
        {
            printf("%s",mensaje);
            scanf("%d",&limite[i]);
            maximoMinimo(limite[i],maximo,minimo);
            buffer = limite;
        }
    }
    return retorno;
}

int maximoMinimo(int numero, int edadMaxima, int edadMinima)
{
    int retorno = -1;
    int buffer;
    if(numero >= edadMinima && numero >= edadMaxima)
    {
        buffer = numero;
        return 0;
    }
    return retorno;
}

//


