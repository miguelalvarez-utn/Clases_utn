#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
///*------Mod Param Menu--------\\\*
#define CANTIDAD_CARACTERES_MAX 20
#define CANTIDAD_CARACTERES_MIN 2
//---------------------------------
#define EDAD_MAXIMA 80
#define EDAD_MINIMA 1
//---------------------------------
#define CARACTERES_MAX_EDAD 4
//---------------------------------
#define CANTIDAD_CLIENTES 3
//---------------------------------
#define VALOR_ESPACIO_LIBRE -1
//---------------------------------
#define OPCION_MINIMA 1
#define OPCION_MAXIMA 6
//---------------------------------
#define CARACTERES_OPCION 2
//---------------------------------
#define REINTENTOS 2
//---------------------------------
#define CARACTER_MAX_DNI 9
#define CARACTER_MIN_DNI 1
//---------------------------------
#define CARACTERES_MIN_LEGAJO 1
//---------------------------------

void inicializarArrayClientes(ePersonas clientes[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia(ePersonas clientes[],int cantidadDeElementos,int valor);
void listar(ePersonas clientes[],int cantidadElementos);

int main()
{
    ePersonas clientes[CANTIDAD_CLIENTES];
    char auxNombre[CANTIDAD_CARACTERES_MAX];
    char auxApellido[CANTIDAD_CARACTERES_MAX];
    char auxLegajo[CANTIDAD_CARACTERES_MAX];
    char auxDni[CARACTER_MAX_DNI];
    char auxEdad[CARACTERES_MAX_EDAD];
    char auxOpcion[CARACTERES_OPCION];
    int opcion;
    int ifEmpty;

    inicializarArrayClientes(clientes,CANTIDAD_CLIENTES,VALOR_ESPACIO_LIBRE);
    do
    {
        Menu();
        getOption("","\nOpcion incorrecta",
                  OPCION_MINIMA,
                  OPCION_MAXIMA,
                  REINTENTOS,
                  auxOpcion);
        opcion = atoi(auxOpcion);
        switch(opcion)
        {
            case 1:
                system("cls");
                ifEmpty = buscarPrimerOcurrencia(clientes,CANTIDAD_CLIENTES,VALOR_ESPACIO_LIBRE);
                if(ifEmpty == VALOR_ESPACIO_LIBRE)
                {
                    printf("No hay espacion disponible\n");
                    break;
                }
                if(getName("Ingrese su nombre\n",
                           "Error, nombre invalido\n",
                           CANTIDAD_CARACTERES_MIN,
                           CANTIDAD_CARACTERES_MAX,
                           REINTENTOS,
                           auxNombre))
                {
                     printf("El nombre debe contener solo letras\n");
                        break;
                }
                if(getName("Ingrese su apellido\n",
                           "Error, apellido invalido\n",
                           CANTIDAD_CARACTERES_MIN,
                           CANTIDAD_CARACTERES_MAX,
                           REINTENTOS,
                           auxApellido))
                {
                     printf("El apellido debe contener solo letras\n");
                        break;
                }
                if(getEdad("Ingrese su edad\n",
                           "Error, edad invalida\n",
                           EDAD_MINIMA,
                           EDAD_MAXIMA,
                           REINTENTOS,
                           auxEdad))
                {
                    printf("La edad debe contener solo numeros\n");
                    break;
                }
                if(getDni("Ingrese su DNI\n",
                          "Error, DNI invalido\n",
                          CARACTER_MIN_DNI,
                          CARACTER_MAX_DNI,
                          REINTENTOS,
                          auxDni))
                {
                    printf("El DNI debe contener 8 digitos\n");
                    break;
                }
                if(getLegajo("Ingrese numero de legajo\n",
                             "Error, legajo invalido\n",
                             CARACTERES_MIN_LEGAJO,
                             CANTIDAD_CLIENTES,
                             REINTENTOS,
                             auxLegajo))
                {
                    printf("el legajo debe contener solo numeros\n");
                    break;
                }
                strncpy(clientes[ifEmpty].nombre,auxNombre,CANTIDAD_CARACTERES_MAX);
                strncpy(clientes[ifEmpty].apellido,auxApellido,CANTIDAD_CARACTERES_MAX);
                strncpy(clientes[ifEmpty].dni,auxDni,CARACTER_MAX_DNI);
                clientes[ifEmpty].edad = atoi(auxEdad);
                clientes[ifEmpty].legajo = atoi(auxLegajo);
                system("cls");
                printf("Alta exitosa!!");
                break;
            case 2:
                listar(clientes,CANTIDAD_CLIENTES);
                if(getLegajo("Ingrese numero de legajo a dar de baja\n",
                             "Error, legajo invalido\n",
                             CARACTERES_MIN_LEGAJO,
                             CANTIDAD_CLIENTES,
                             REINTENTOS,
                             auxLegajo))
                {
                    printf("el legajo debe contener solo numeros\n");
                    break;
                }
                ifEmpty = buscarPrimerOcurrencia(clientes,
                                                 CANTIDAD_CLIENTES,
                                                 atoi(auxLegajo));
                if(ifEmpty == VALOR_ESPACIO_LIBRE)
                {
                    printf("el legajo no esta en uso");
                    break;
                }
                clientes[ifEmpty].legajo = VALOR_ESPACIO_LIBRE;
                system("cls");
                printf("Baja exitosa!!");
                break;
            case 3:
                listar(clientes,CANTIDAD_CLIENTES);
                if(getLegajo("Ingrese numero de legajo a modificar\n",
                             "Error, legajo invalido\n",
                             CARACTERES_MIN_LEGAJO,
                             CANTIDAD_CLIENTES,
                             REINTENTOS,
                             auxLegajo))
                {
                    printf("el legajo debe contener solo numeros\n");
                    break;
                }
                ifEmpty = buscarPrimerOcurrencia(clientes,CANTIDAD_CLIENTES,atoi(auxLegajo));
                if(ifEmpty == VALOR_ESPACIO_LIBRE)
                {
                    printf("el legajo no esta en uso\n");
                    break;
                }
                while(opcion != 5)
                {
                    MenuModificacion();
                    getOption("",
                              "Opcion incorrecta\n",
                              OPCION_MINIMA,
                              OPCION_MAXIMA,
                              REINTENTOS,
                              auxOpcion);
                    opcion = atoi(auxOpcion);
                    switch(opcion)
                    {
                        case 1:

                            if(getName("Ingrese su nombre\n",
                                       "Error, nombre invalido\n",
                                       CANTIDAD_CARACTERES_MIN,
                                       CANTIDAD_CARACTERES_MAX,
                                       REINTENTOS,
                                       auxNombre))
                            {
                                printf("El nombre debe contener solo letras\n");
                                break;
                            }
                            strncpy(clientes[ifEmpty].nombre,auxNombre,CANTIDAD_CARACTERES_MAX);
                            system("cls");
                            printf("Modificacion exitosa!!\n");
                            break;
                        case 2:

                            if(getName("Ingrese su apellido\n",
                                       "Error, apellido invalido\n",
                                       CANTIDAD_CARACTERES_MIN,
                                       CANTIDAD_CARACTERES_MAX,
                                       REINTENTOS,
                                       auxApellido))
                            {
                                printf("El apellido debe contener solo letras\n");
                                break;
                            }
                            strncpy(clientes[ifEmpty].apellido,auxApellido,CANTIDAD_CARACTERES_MAX);
                            system("cls");
                            printf("Modificacion exitosa!!\n");
                            break;
                        case 3:

                            if(getEdad("Ingrese su edad\n",
                                       "Error, edad invalida\n",
                                       EDAD_MINIMA,
                                       EDAD_MAXIMA,
                                       REINTENTOS,
                                       auxEdad))
                            {
                                printf("La edad debe contener solo numeros\n");
                                break;
                            }
                            clientes[ifEmpty].edad = atoi(auxEdad);
                            system("cls");
                            printf("Modificacion exitosa!!\n");
                            break;
                        case 4:

                            if(getDni("Ingrese su DNI\n",
                                      "Error, DNI invalido\n",
                                      CARACTER_MIN_DNI,
                                      CARACTER_MAX_DNI,
                                      REINTENTOS,
                                      auxDni))
                            {
                                printf("El DNI debe contener 8 digitos\n");
                                break;
                            }
                            strncpy(clientes[ifEmpty].dni,auxDni,CARACTER_MAX_DNI);
                            system("cls");
                            printf("Modificacion exitosa!!\n");
                            break;
                    }

                }
            case 5:
                system("cls");
                listar(clientes,CANTIDAD_CLIENTES);

                break;


        }
    }while(opcion != OPCION_MAXIMA);


    return 0;
}

void listar(ePersonas clientes[],int cantidadElementos)
{
    int i;
    for(i = 0; i < cantidadElementos; i++)
    {
        if(clientes[i].legajo != VALOR_ESPACIO_LIBRE)
        {
            printf("Nombre: %s\n",clientes[i].nombre);
            printf("Apellido: %s\n",clientes[i].apellido);
            printf("Dni: %s\n",clientes[i].dni);
            printf("Edad: %d\n",clientes[i].edad);
            printf("Legajo: %d\n",clientes[i].legajo);
            printf("/////////////////////////////////\n");
        }
    }
}

void inicializarArrayClientes(ePersonas clientes[] ,int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        clientes[i].legajo = valor;
    }
}

int buscarPrimerOcurrencia(ePersonas clientes[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(clientes[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}
