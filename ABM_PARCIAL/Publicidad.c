#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Pantallas.h"
#include "Publicidad.h"
#include "Validaciones.h"
#define TRUE 1
#define FALSE 0
#define DIAS_MAX_CHAR 5
#define DIAS_MIN_CHAR 1
#define VALOR_ESPACIO_LIBRE -1
//////////////////////////////////////////////////////////////////////
int getCuit(    char* msg,
                char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if( msg != NULL &&
        msgError != NULL &&
        msgError2 != NULL &&
        msgError3 != NULL &&
        minimo < maximo &&
        resultado != NULL)
    {
        printf("%s",msg);
        if(!getString(minimo,maximo,bufferStr))
        {
            if(isValidCuitA(bufferStr))
            {
                if(isValidCuitB(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
                }
                else
                {
                    printf("%s",msgError2);
                }
            }
            else
            {
                printf("%s",msgError);
            }
        }else
        {
            printf("%s",msgError3);
        }
    }
    return retorno;
}
////////////////////////////////////////////////
int isValidCuitA(char str[])
{

    int retorno = TRUE;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') &&  (str[i] != '-'))
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;
}
//////////////////////////////////////////////////
int isValidCuitB(char str[])
{
    int retorno = FALSE;
    if(!(str[12] == '\0' || str[12] == NULL))
    {
        if(str[2] =='-' && str[11]=='-')
        {
            retorno = TRUE;
        }
    }
    return retorno;
}
////////////////////////////////////////////////
int getDias(  char* msg,
                char* msgError,
                char* msgError2,
                int minimo,
                int maximo,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int isValid = 0;

    if( msgError != NULL &&
        msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        resultado != NULL)
    {

        do
        {
            isValid ++;
            printf("%s",msg);
            if(!getString(DIAS_MIN_CHAR,DIAS_MAX_CHAR,bufferStr))
            {
                isValid++;
                if(isValidNumber(bufferStr))
                {
                    isValid++;
                    strncpy(resultado,bufferStr,DIAS_MAX_CHAR);
                    retorno = 0;
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
        }while(isValid != 3);
        return retorno;
    }

}
//////////////////////////////////////////////////////////////
int getArchivo(char* msg,
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
                if(isArchivo(bufferStr))
                {
                    isValid ++;
                    strncpy(resultado,bufferStr,maximo);
                    retorno = 0;
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
//////////////////////////////////////////////////////////////////////
int isArchivo(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if( (str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9') &&
            (str[i] != '/')&&
            (str[i] != '.'))
        {
            return 0;
        }

        i++;
    }
    return 1;
}
///////////////////////////////////////////////////////////////////////
void listarPublicidad(publicidad str[],int cantidadElementos)
{
    int i;
    for(i = 0; i < cantidadElementos; i++)
    {
        if(str[i].isEmpty!= VALOR_ESPACIO_LIBRE)
        {
            printf("CUIT: %s\n",str[i].cuit);
            printf("Cant.Dias: %s\n",str[i].diasContratacion);
            printf("Nombre de archivo: %s\n",str[i].archivo);
            printf("ID: %d\n",str[i].idPublicidad);
            printf("/////////////////////////////////\n");
        }
    }
}
////////////////////////////////////////////////////////////////////////
void MenuPublicidadMod()
    {
    printf("\nMenu De Modificaciones\n");
    printf("--------------\n");
    printf("1 - Modificar CUIT\n");
    printf("2 - Modificar Cant.Dias\n");
    printf("3 - Modificar Nombre de archivo\n");
    printf("4 - Salir\n");
    printf("Elija opcion: ");
    }
////////////////////////////////////////////////////////////////////////
int buscarPorCuit(publicidad str[],
                  pantallas str2[],
                  int cantidadElementos,
                  char cuitCompare[],
                  char* msg,
                  char* msg2)
{
    int i;
    int retorno = -1;
    int cantCuit = 0;
    for(i = 0;i < cantidadElementos; i++)
    {
        if(!(strcmp(str[i].cuit,cuitCompare)))
        {
            printf("%s",msg2);
            printf("-------------------------------------------\n");
            printf("Tipo: %s\n",str2[str[i].idPantalla-1].tipoPantalla);
            printf("Precio: %s\n",str2[str[i].idPantalla-1].precio);
            printf("Direccion: %s\n",str2[str[i].idPantalla-1].direccion);
            printf("Dias de contratacion: %s\n",str[i].diasContratacion);
            printf("CUIT: %s\n",str[i].cuit);
            cantCuit++;
            retorno = 0;
        }
    }
    printf("%s",msg);
    printf("%d",cantCuit);
    printf("\n-------------------------------------------\n");
    return retorno;
}
///////////////////////////////////////////////////////////////////////////
void imprimirGeneral(publicidad str[],pantallas str2[],int cantidadElementos)
{
    int i;
    for(i = 0; i < cantidadElementos; i++)
    {
        if(str[i].isEmpty!= VALOR_ESPACIO_LIBRE)
        {
            if(atoi(str[i].diasContratacion) <= 10)
            {
                printf("Nombre: %s\n",str2[str[i].idPantalla-1].nombre);
                printf("Cant.Dias: %s\n",str[i].diasContratacion);
                printf("Nombre de archivo: %s\n",str[i].archivo);
                printf("ID: %d\n",str[i].idPublicidad);
                printf("Precio: %s\n",str2[str[i].idPantalla-1].precio);
                printf("Total: %.2f\n",atof(str2[str[i].idPantalla-1].precio)*atoi(str[i].diasContratacion));
                printf("/////////////////////////////////\n");

            }

        }
    }
}
///////////////////////////////////////////////////////////////////////////
int buscarPorCuitFacturacion(publicidad str[],
                  pantallas str2[],
                  int cantidadElementos,
                  char cuitCompare[],
                  char* msg,
                  char* msg2)
{
    int i;
    int retorno = -1;
    int cantCuit = 0;
    float buffer = 0;
    for(i = 0;i < cantidadElementos; i++)
    {
        if(!(strcmp(str[i].cuit,cuitCompare)))
        {
            buffer += atof(str2[str[i].idPantalla-1].precio);
            retorno = 0;
        }
    }
    printf("Facturacion: %.2f\n",buffer);

    return retorno;
}
///////////////////////////////////////////////////////////////////////////
int listarPorCuil(publicidad str[],pantallas str2[], int cantidadElementos,int idCompare[])
{
    int i;
    int retorno = -1;
    for(i = 0;i < cantidadElementos; i++)
    {
        if(str[i].idPantalla == str2[i].idPantallas)
        {
            printf("%s",str2[i].precio);
            printf("%s",str[i].cuit);
        }
    }
    return retorno;
}
