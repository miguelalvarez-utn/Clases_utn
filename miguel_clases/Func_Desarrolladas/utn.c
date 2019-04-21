#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"
#include <ctype.h>
#define MAX_DIGIT_OPTION 2
#define MIN_DIGIT_OPTION 1
#define EDAD_MAX_DIGIT 3
#define EDAD_MIN_DIGIT 1


/**
  *\brief Toma una cadena de caracteres ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, minimo de caracteres, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char resultado[])
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) < maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char resultado[])
{
    int retorno = -1;
    char bufferStr[4096];

    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        reintentos>=0 &&
        resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int getNumber ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        reintentos>=0 &&
        resultado != NULL)
    {
        if(!getString(msg,msgError,MIN_DIGIT_OPTION,MAX_DIGIT_OPTION,reintentos,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                bufferInt = atoi(bufferStr);
                if(isValidRange(bufferInt,minimo,maximo))
                {
                    strncpy(resultado,bufferStr,MAX_DIGIT_OPTION);
                    retorno = 0;
                }
                else
                {
                    printf("%s",msgError);
                }

            }
        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int getEdad(    char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        reintentos>=0 &&
        resultado != NULL)
    {
        if(!getString(msg,msgError,EDAD_MIN_DIGIT,EDAD_MAX_DIGIT,reintentos,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                bufferInt = atoi(bufferStr);
                if(isValidRange(bufferInt,minimo,maximo))
                {
                    strncpy(resultado,bufferStr,MAX_DIGIT_OPTION);
                    retorno = 0;
                }
                else
                {
                    printf("%s",msgError);
                }

            }
        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int getOption(  char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)

{
    int retorno = -1;
    int auxiliar;

    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        reintentos>=0 &&
        resultado != NULL)
    {
        printf("%s",msg);
        scanf("%d",&auxiliar);
        if(!isdigit(auxiliar))
        {
            if(isValidRange(auxiliar,minimo,maximo))
            {
                *resultado = auxiliar;
                retorno = 0;
            }

        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
int getLegajo(  char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        reintentos>=0 &&
        resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                bufferInt = atoi(bufferStr);
                if(isValidRange(bufferInt,minimo,maximo))
                {
                    strncpy(resultado,bufferStr,MAX_DIGIT_OPTION);
                    retorno = 0;
                }
                else
                {
                    printf("%s",msgError);
                }

            }
        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidNumber(char str[])
{

    int retorno = TRUE;
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return FALSE;
        }
        i++;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidRange(int numero, int minimo, int maximo)
{
    int retorno = TRUE;
    if(!(numero >= minimo && numero <= maximo))
    {
        return FALSE;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializarArrayInt(int str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        str[i] = valor;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarPrimerOcurrencia(int str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i] == valor)
        {
            return i;
        }
    }
    return -1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////



