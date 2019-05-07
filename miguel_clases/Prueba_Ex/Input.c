#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include "input.h"
#include "lib.h"
#define TRUE 1
#define FALSE 0

int getString ( int minimo,
                int maximo,
                char resultado[])
{
    int retorno = -1;
    char bufferStr[4096];
    if(minimo < maximo && resultado != NULL)
    {
        fgets(bufferStr,sizeof(bufferStr),stdin);
        bufferStr[strlen(bufferStr)-1] = '\0';
        if(strlen(bufferStr)>= minimo && strlen(bufferStr) < maximo)
        {
            strncpy(resultado,bufferStr,maximo);
            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Toma un nombre ingresado por el usuario.
  *\param Recibe un mensaje, mensaje para error, minimo de caracteres, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
int getName (   char* msg,
                char* msgError,
                char* msgError2,
                int minimo,
                int maximo,
                char resultado[])
{
    int retorno = -1;
    char bufferStr[4096];
    int isValid = 0;
    do
    {
        if( msg != NULL &&
            msgError != NULL &&
            minimo < maximo &&
            resultado != NULL)
        {
            isValid ++;
            printf("%s",msg);
            if(!getString(minimo,maximo,bufferStr))
            {
                isValid ++;
                if(isValidName(bufferStr))
                {
                    isValid ++;
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("%s",msgError2);
                    isValid = 0;
                }
            }
            else
            {
                printf("%s",msgError);
                isValid = 0;
            }
        }
    }while(isValid != 3);
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int isValidNumber(char str[])
{

    int retorno = TRUE;
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int isValidRange(int numero, int minimo, int maximo)
{
    int retorno = TRUE;
    if(numero < minimo || numero > maximo)
    {
        retorno = FALSE;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidName(char str[])
{
    int retorno = TRUE;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return FALSE;
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
int isAlphaNumeric(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}
