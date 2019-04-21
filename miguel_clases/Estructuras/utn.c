#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"
#include <ctype.h>
///**Mod Param Menu-----///
#define MAX_DIGIT_OPTION 2
#define MIN_DIGIT_OPTION 1
//------------------------
#define EDAD_MAX_DIGIT 3
#define EDAD_MIN_DIGIT 1
//------------------------
#define CARACTERES_MIN_EDAD 1
#define CARACTERES_MAX_EDAD 4
//------------------------
#define CARACTERES_MAX_LEGAJO 5
#define CARACTERES_MIN_LEGAJO 1




////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Toma una cadena de caracteres ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, minimo de caracteres, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
////////////////////////////////////////////////////////////////////////////////////////////////
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
/**
  *\brief Toma un nombre ingresado por el usuario.
  *\param Recibe un mensaje, mensaje para error, minimo de caracteres, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
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
/**
  *\brief Toma una cadena de caracteres numericos ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, valor minimo, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
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
/**
  *\brief Toma una edad en caracteres numericos ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, valor minimo de edad, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
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
        if(!getString(msg,msgError,CARACTERES_MIN_EDAD,CARACTERES_MAX_EDAD,reintentos,bufferStr))
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
/**
  *\brief Toma una DNI como caracteres numericos ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, minimo cantidad de caracteres, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int getDni(    char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
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
            if(isValidNumber(bufferStr))
            {
                if(isValidDni(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
                }

            }
        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Toma una opcion en forma numerica ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, valor minimo, y un maximo de opcion.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int getOption(  char* msg,
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
/**
  *\brief Toma un numero de legajo ingresado por el usuario.
  *\param Recibe un mensaje, mensaje para error, valor minimo, y un maximo de legajo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
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
        if(!getString(msg,msgError,CARACTERES_MIN_LEGAJO,CARACTERES_MAX_LEGAJO,reintentos,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                bufferInt = atoi(bufferStr);
                if(isValidRange(bufferInt,minimo,maximo))
                {
                    strncpy(resultado,bufferStr,CARACTERES_MAX_LEGAJO);
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
/**
  *\brief Menu de opciones para ABM.
  *\param No recibe nada.
  *\return Nada.
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu()
    {
    printf("\nMenu principal\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Ordena por apellido\n");
    printf("5 - Listar\n");
    printf("6 - Salir\n");
    printf("Elija opcion: ");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Sub menu de opciones para ABM.
  *\param No recibe nada.
  *\return Nada.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
void MenuModificacion()
    {
    printf("\nMenu Modificaciones\n");
    printf("--------------\n");
    printf("1 - MOD nombre\n");
    printf("2 - MOD apellido\n");
    printf("3 - MOD edad\n");
    printf("4 - MOD DNI\n");
    printf("5 - Salir\n");
    printf("Elija opcion: ");
    }


