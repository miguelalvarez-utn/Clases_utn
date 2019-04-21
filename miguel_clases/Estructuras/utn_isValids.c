#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"
#include <ctype.h>
///////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Valida su la cadena de caracteres son numeros.
  *\param Recibe el array con la cadena de numerica.
  *\return TRUE o FALSE.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Valida si el array de DNI es completo.
  *\param Recibe el array con la cadena de numerica.
  *\return TRUE o FALSE.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidDni(char str[])
{
    int retorno = FALSE;
    if(!(str[7] == '\0' || str[7] == NULL))
    {
        retorno = TRUE;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Valida el rango numerico dado por el usuario.
  *\param Recibe un numero, el rango minimo y maximo que puede tener ese numero.
  *\return TRUE o FALSE.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidRange(int numero, int minimo, int maximo)
{
    int retorno = TRUE;
    if(!(numero >= minimo && numero <= maximo))
    {
        retorno = FALSE;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/**
  *\brief Valida si es un nombre que contenga solo letras.
  *\param Recibe el array con la cadena de caracteres.
  *\return TRUE o FALSE.
*/
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
