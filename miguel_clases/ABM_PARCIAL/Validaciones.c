#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
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
