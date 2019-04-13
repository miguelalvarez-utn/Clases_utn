#include <stdio.h>
#include <stdlib.h>
#include "Mis_Prototipos.h"
#include <string.h>

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param recibe mensaje, mensaje error, numero maximo y minimo y lo guarda en resultado
 * \return verdadero o falso
 */
int getInt(char *mensaje, char *mensajeError, int maximo,int minimo, int reintentos, int *resultado)
{
    int buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer,maximo,minimo))
            {
                *resultado = buffer;
                return 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
            reintentos --;
        }while(reintentos >= 0);
    }
    return 0;
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
int isValidInt(int numero,int numeroMaximo, int numeroMinimo)
{
    if(numero >= numeroMinimo && numero <= numeroMaximo)
    {
        return 1;
    }
    return 0;
}
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param recibe mensaje, mensaje error, numero maximo y minimo y lo guarda en resultado
 * \return verdadero o falso
 */
int getFloat(char *mensaje, char *mensajeError, float maximo,float minimo, int reintentos, float *resultado)
{
    float buffer;
    int retorno = 0;

    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer,maximo,minimo))
            {
                *resultado = buffer;
                retorno = 1;
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
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
int isValidFloat(float numero,float numeroMaximo, float numeroMinimo)
{
    if(numero >= numeroMinimo && numero <= numeroMaximo)
    {
        return 1;
    }
    return 0;
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
int getArrayInt(char* mensaje, char* mensajeError, int maximo, int minimo,int reintentos, int* edadesArray, int limite)
{

    int retorno = -1;
    int i;
    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos > 0 && limite > 0)
    {

        for(i = 0; i < limite; i++)
        {
            printf("%s",mensaje);
            scanf("%d",&edadesArray[i]);
            if(isValidInt(edadesArray[i],maximo,minimo))
            {
                retorno = 0;
            }
            else
            {
                printf("%s",mensajeError);
            }
        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
int ordenArray(int* vector[], int limite)
{
    int i;
    int flagSwap;
    int aux;

    do
    {
        for(i = 0; i < limite; i++)
        {
            flagSwap = 0;
            if(vector[i] > vector[i+1])
            {
                aux = vector[i+1];
                vector[i+1] = vector[i];
                vector[i] = aux;
                flagSwap = 1;
            }
        }
    }while(flagSwap);

    return 0;
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
char getChar(char* mensaje, char* mensajeError,char* resultado)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    if(isValidChar(auxiliar))
    {
        *resultado = auxiliar;
        return 1;
    }
    else
    {
        printf("%s",mensajeError);
    }
    return 0;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
int isValidChar(char* letra)
{
    if(!(letra >= 'a' && letra <= 'z' || letra >= 'A' && letra <= 'Z' ))
    {
        return 0;
    }
    return 1;
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
