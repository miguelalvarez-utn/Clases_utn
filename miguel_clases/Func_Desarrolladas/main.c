#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#define CANTIDAD_CLIENTES 5
#define CANTIDAD_CARACTERES 20
#define CARACTERES_OPCION 2

int main()
{
    char aNombres[CANTIDAD_CLIENTES][CANTIDAD_CARACTERES];
    char aApellido[CANTIDAD_CLIENTES][CANTIDAD_CARACTERES];
    char aEdad[CANTIDAD_CLIENTES];
    char aLegajo[CANTIDAD_CLIENTES];
    int bufferOpcion[CARACTERES_OPCION];
    int estado[CANTIDAD_CLIENTES];

    char auxNombre[CANTIDAD_CARACTERES];
    char auxApellido[CANTIDAD_CARACTERES];
    char auxEdad[CANTIDAD_CARACTERES];
    char auxLegajo[CANTIDAD_CARACTERES];

    int i,j;
    int empty;
    int opcion;
    char respuesta;

    for(i = 0;i < CANTIDAD_CLIENTES; i++)
    {
        estado[i] = -1;
    }

    do
    {
        if(!getOption("Ingrese opcion\n1:Alta\n2:Baja\n3:Modificar\n4:Ordenar\n5:Listar\n6:SALIR\n","Error\n",1,6,3,bufferOpcion))
        {
            opcion = atoi(bufferOpcion);
            switch(opcion)
            {
                case 1:
                    system("cls");
                    if(!buscarEspacioVacio(estado,CANTIDAD_CLIENTES,empty))
                    {
                        printf("No hay espacion libre");
                        break;
                    }
                    if(getName("Ingrese nombre\n","Error, nombre invalido\n",2,CANTIDAD_CARACTERES,3,auxNombre))
                    {
                        printf("nombre incorrecto\n");
                        break;
                    }
                    if(getName("Ingrese apellido\n","Error, apellido invalido\n",2,CANTIDAD_CARACTERES,3,auxApellido))
                    {
                        printf("Apellido incorrecto\n");
                        break;
                    }
                    if(getEdad("Ingrese edad\n","Error, edad invalida\n",1,120,3,auxEdad))
                    {
                        printf("Edad incorrecta\n");
                        break;
                    }
                    if(getLegajo("Ingrese legajo\n","Error, dato invalido\n",1,CANTIDAD_CLIENTES,3,auxLegajo))
                    {
                        if(isValidLegajo(auxLegajo,aLegajo,CANTIDAD_CLIENTES))
                        {
                        printf("Legajo en uso");
                        break;
                        }
                    }
                    strncpy(aNombres[empty],auxNombre,CANTIDAD_CARACTERES);
                    strncpy(aApellido[empty],auxNombre,CANTIDAD_CARACTERES);
                    aEdad[empty] = atoi(auxEdad);
                    aLegajo[empty] = atoi(auxLegajo);


            }
        }
    }while(opcion != 6);
}
