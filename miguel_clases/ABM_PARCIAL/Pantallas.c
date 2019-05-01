#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Pantallas.h"
#include "Publicidad.h"
#include "Validaciones.h"
//--------------------------
#define NAME_MAX_CHARACT 50
#define NAME_MIN_CHARACT 2
//--------------------------
#define DIRECT_MAX_CHARACT 20
#define DIRECT_MIN_CHARACT 2
//--------------------------
#define PRICE_MAX_CHARACT 20
#define PRICE_MIN_CHARACT 1
//--------------------------
#define OPCION_MAX_MENU 11
#define OPCION_MIN_MENU 1
//--------------------------
#define ID_MAX_CHARACT 20
#define ID_MIN_CHARACT 1
//--------------------------
#define CUIT_MAX_CHAR 14
#define CUIT_MIN_CHAR 1
//--------------------------
#define DIAS_MAX_CHAR 5
#define DIAS_MIN_CHAR 1
//--------------------------
#define ARCHIVO_MAX_CHAR 128
#define ARCHIVO_MIN_CHAR 1
//--------------------------
#define PRICE_MAX_CHARACT 20
#define PRICE_MIN_CHARACT 1
#define ID_MAX_CHARACT 20
#define ID_MIN_CHARACT 1
#define VALOR_ESPACIO_LIBRE -1
#define DIGIT_OPTION 3

#define TRUE 1
#define FALSE 0
/////////////////////////////////////////////////////////////////////////////////
void alta(pantallas str[],int espacioLibre)
{
    char auxNombre[NAME_MAX_CHARACT];
    char auxDireccion[DIRECT_MAX_CHARACT];
    char auxPrecio[PRICE_MAX_CHARACT];
    char auxTipoPantalla[TYPE_MAX_CHARCT];
    char auxOpcion[DIGIT_OPTION];
    int opcionType;
    int auxId = 0;

    getName("Ingrese nombre: ",
    "Error, supera cantidad de caracteres\n",
    "Error, el nombre no es valido\n",
    NAME_MIN_CHARACT,
    NAME_MAX_CHARACT,
    auxNombre);
    strncpy(str[espacioLibre].nombre,auxNombre,NAME_MAX_CHARACT);

    getAlfaNumerico("Ingrese direccion: ",
    "Error, supera cantidad de caracteres\n",
    "Error, el nombre no es valido\n",
    NAME_MIN_CHARACT,NAME_MAX_CHARACT,
    auxDireccion);
    strncpy(str[espacioLibre].direccion,auxDireccion,DIRECT_MAX_CHARACT);

    getPricio("ingrese precio: ",
    "Supera la cantidad de caracteres\n",
    "Error, el precio no puede contener letras\n",
    PRICE_MIN_CHARACT,
    PRICE_MAX_CHARACT,
    auxPrecio);
    strncpy(str[espacioLibre].precio,auxPrecio,PRICE_MAX_CHARACT);

    do
    {
        MenuType();
        getOption("Error, ingrese numeros\n",
        "Error, opcion fuera de rango\n",
        "Supera la cantidad de caracteres",
        OPCION_MIN_MENU,
        OPCION_MAX_MENU,
        auxOpcion);
        opcionType = atoi(auxOpcion);
        switch(opcionType)
        {
            case 1:
                strncpy(auxTipoPantalla,"LCD",TYPE_MAX_CHARCT);
                break;
            case 2:
                strncpy(auxTipoPantalla,"LED",TYPE_MAX_CHARCT);
                break;
        }
    }while(opcionType != 1 && opcionType != 2);
    strncpy(str[espacioLibre].tipoPantalla,auxTipoPantalla,TYPE_MAX_CHARCT);
    str[espacioLibre].idPantallas =++auxId;
    printf("Alta Exitosa!!");
}
/////////////////////////////////////////////////////////////////////////////////
void inicializarEspaciosA(pantallas str[],int cantidadElementos,int valorEspacio)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        str[i].isEmpty = valorEspacio;
        str[i].idPantallas = 0;

    }
}
/////////////////////////////////////////////////////////////////////////////////
void inicializarEspaciosB(publicidad str[],int cantidadElementos,int valorEspacio)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        str[i].isEmpty = valorEspacio;
        str[i].idPublicidad = 0;

    }
}
/////////////////////////////////////////////////////////////////////////////////
int buscarEspacioLibreA(pantallas str[],int cantidadElementos,int valorEspacio)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].isEmpty == valorEspacio)
        {
            return i;
        }
    }
    return -1;
}
//////////////////////////////////////////////////////////////////////////////////
int buscarEspacioLibreB(publicidad str[],int cantidadElementos,int valorEspacio)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].isEmpty == valorEspacio)
        {
            return i;
        }
    }
    return -1;
}
//////////////////////////////////////////////////////////////////////////////////
int buscarPorId(pantallas str[],int cantidadElementos,int idCompare)
{
    int i;
    int retorno = -1;
    for(i = 0;i < cantidadElementos; i++)
    {
        if(str[i].idPantallas == idCompare)
        {
            return idCompare;
        }
    }
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void MenuType()
    {
    printf("\nTipos\n");
    printf("--------------\n");
    printf("1 - LCD\n");
    printf("2 - LED\n");
    printf("Elija opcion: ");
    }
//////////////////////////////////////////////////////////////////////////////////
void MenuPantalla()
    {
    printf("\nMenu principal\n");
    printf("--------------\n");
    printf("1 - Alta->(pantalla)\n");
    printf("2 - Modificacion->(datos de pantalla)\n");
    printf("3 - Baja ->(pantalla)\n");
    printf("4 - Contratar Publicidad ->(clientes)\n");
    printf("5 - Modificar Condiciones De Publicacion->(clientes)\n");
    printf("6 - Cancelar Contratacion->(clientes)\n");
    printf("7 - Consultar Facturacion->(clientes)\n");
    printf("8 - Listar contrataciones\n");
    printf("9 - Listar Pantallas disponibles\n");
    printf("10 - SALIR\n");
    printf("Elija opcion: ");
    }
//////////////////////////////////////////////////////////////////////////////
void MenuPantallaMod()
    {
    printf("\nMenu De Modificaciones\n");
    printf("--------------\n");
    printf("1 - Modificar Nombre\n");
    printf("2 - Modificar Direccion\n");
    printf("3 - Modificar Precio\n");
    printf("4 - Modificar Tipo\n");
    printf("5 - Salir\n");
    printf("Elija opcion: ");
    }
//////////////////////////////////////////////////////////////////////////////
void listar(pantallas str[],int cantidadElementos)
{
    int i;
    for(i = 0; i < cantidadElementos; i++)
    {
        if(str[i].isEmpty!= VALOR_ESPACIO_LIBRE)
        {
            printf("Nombre: %s\n",str[i].nombre);
            printf("Direccion: %s\n",str[i].direccion);
            printf("Precio: %s\n",str[i].precio);
            printf("Tipo de pantalla: %s\n",str[i].tipoPantalla);
            printf("ID: %d\n",str[i].idPantallas);
            printf("/////////////////////////////////\n");
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
int getOption(  char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( msgError != NULL &&
        msgError2 != NULL &&
        minimo < maximo &&
        resultado != NULL)
    {
        if(!getString(1,3,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                bufferInt = atoi(bufferStr);
                if(isValidRange(bufferInt,minimo,maximo))
                {
                    strncpy(resultado,bufferStr,DIGIT_OPTION);
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
        }
        else
        {
            printf("%s",msgError3);
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int getPricio(  char* msg,
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
            if(!getString(PRICE_MIN_CHARACT,PRICE_MAX_CHARACT,bufferStr))
            {
                isValid++;
                if(isValidNumber(bufferStr))
                {
                    isValid++;
                    strncpy(resultado,bufferStr,PRICE_MAX_CHARACT);
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
////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////
int getAlfaNumerico    (char* msg,
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
                if(isAlphaNumeric(bufferStr))
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
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int getId(      char* msg,
                char* msgError,
                int minimo,
                int maximo,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];

    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        resultado != NULL)
    {
        printf("%s",msg);
        if(!getString(ID_MIN_CHARACT,ID_MAX_CHARACT,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                strncpy(resultado,bufferStr,ID_MAX_CHARACT);
                retorno = 0;
            }
            else
            {
                printf("%s",msgError);
            }

        }
    }
    return retorno;
}
