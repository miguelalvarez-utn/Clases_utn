#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
//--------------------------------
#define CANTIDAD_CLIENTES 5
//--------------------------------
#define CANTIDAD_MAX_CARACTERES 20
#define CANTIDAD_MIN_CARACTERES 2
//--------------------------------
#define ESPACIO_LIBRE -1
#define REINTENTOS 2
//--------------------------------



int main()
{
    char aNombre[CANTIDAD_CLIENTES][CANTIDAD_MAX_CARACTERES];
    char aApellido[CANTIDAD_CLIENTES][CANTIDAD_MAX_CARACTERES];
    int aLegajo[CANTIDAD_CLIENTES];

    char auxiliarNombreStr[50];
    char auxiliarApellidoStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i;
    int j;



    inicializarArrayInt(aLegajo,CANTIDAD_CLIENTES,ESPACIO_LIBRE);
    getOption("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - LISTAR\n5 - ORDENAR\n6 - SALIR\n\n\n","Error\n",1,6,2,&opcion);
    switch(opcion)
    {
        case 1:
            if(indiceLugarLibre = buscarPrimerOcurrencia(aLegajo,CANTIDAD_CLIENTES,ESPACIO_LIBRE))
            {
                printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                break;
            }
            if(!getName("Ingrese su nombre\n","Error\n",CANTIDAD_MIN_CARACTERES,CANTIDAD_MAX_CARACTERES,REINTENTOS,auxiliarNombreStr))
            {
                printf ("El nombre debe estar compuesto solo por letras\n");
                break;
            }

    }
 return 0;
}

