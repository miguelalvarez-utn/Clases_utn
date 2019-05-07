#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"
#include "lib.h"


void Alta(eTypedef str[],int cantidadElementos)
{
    int espacioLibre;
    char auxiliar[51];
    espacioLibre = buscarEspacioLibreB(str,5,-1);
    if(espacioLibre != -1)
    {
        getName("\nIngrese nombre:  ","error","error2",1,51,str[espacioLibre].nombre);
        getName("\nIngrese apellido:  ","error","error2",1,51,str[espacioLibre].apellido);
        str[espacioLibre].id = ++str[espacioLibre].id;
        str[espacioLibre].isEmpty = 1;
    }
    else
    {
        printf("No encontro lugar");
    }
}

void inicializarEspaciosB(eTypedef str[],int cantidadElementos,int valorEspacio)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        str[i].isEmpty = valorEspacio;
        str[i].id = 0;

    }
}
///////////////////////////////////////////////////////////////////////////////////
int buscarEspacioLibreB(eTypedef str[],int cantidadElementos,int valorEspacio)
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

void baja(eTypedef str[],int cantidadElementos)
{
   int espacioLibre;
   char auxDato[51];
   espacioLibre = buscarEspacioLibreB(str,5,1);
   if(espacioLibre != -1)
   {
    // mostrar datos;
    // getId(auxDato);
        espacioLibre = buscarEspacioLibreB(str,5,atoi(auxDato));

        if(espacioLibre != -1)
        {
            str[espacioLibre].isEmpty = -1;
            printf("\nBaja exitosa");
        }
        else
        {
            printf("El dato no existe");
        }
   }
   else
   {
       printf("no hay datos cargados");
   }
}

void modificacion(eTypedef str[],int cantidadElementos)
{
    int espacioLibre;
    char auxDato[51];
    espacioLibre = buscarEspacioLibreB(str,5,1);
    if(espacioLibre != -1)
    {
        // mostrar datos;
        // getId(auxDato);
        //espacioLibre = buscarEspacioLibreB(str,5,atoi(auxDato));
        espacioLibre = 0;
        if(espacioLibre != -1)
        {
            getName("nombre: ","errr","errr",1,51,str[espacioLibre].nombre);
        }
        else
        {
            printf("El dato no existe");
        }
    }
    else
    {
        printf("no hay datos cargados");
    }
}

void ordenamiento(eTypedef str[],int cantidadElementos)
{
    int i,j;
    eTypedef aux;
    for(i=0;i<cantidadElementos-1;i++)
    {
        if(str[i].isEmpty != -1)
        {
            for(j=i+1;j<cantidadElementos;j++)
            {
                if(str[j].isEmpty != -1)
                {
                    if(strcmp(str[i].nombre,str[j].nombre) > 0)
                       {
                           aux = str[j];
                           str[j] = str[i];
                           str[i] = aux;
                       }
                    if(strcmp(str[i].nombre,str[j].nombre) == 0 )
                        {
                            if(strcmp(str[i].apellido,str[j].apellido) > 0)
                            {
                                aux = str[j];
                                str[j] = str[i];
                                str[i] = aux;
                            }
                        }

                }
            }
        }
    }
}

