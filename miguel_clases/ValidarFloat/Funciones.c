#include <stdio.h>
#include <stdlib.h>

int getFloat(char *mensaje, char *mensajeError, float maximo,
        float minimo, int reintentos, float *resultado)
{
    float buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer,maximo,minimo))
            {
            *resultado = buffer;
            retorno = 0;
            break;
            }
            else
            {
                printf("%s",mensajeError);
            }
            reintentos --;
        }while(reintentos >= 0);
    }
    return retorno;
}

int isValidFloat(float numero,float maximo, float minimo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
}
