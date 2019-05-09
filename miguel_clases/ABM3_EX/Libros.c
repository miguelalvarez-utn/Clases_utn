#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "input.h"
#include "Libros.h"
int lib_initArray(t_libros lista[],int len)
{
    int retorno=1;
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].isEmpty =1;
    }
    return retorno;
}
///////////////////////////////////////
int lib_buscarLibre(t_libros lista[], int len)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
///////////////////////////////////////
int lib_alta(t_libros lista[],int len,int pos)
{
    int retorno = -1;
    int flag = 1;
    char auxDato[51];
    do
    {
        if(getName("Ingrese titulo del libro\n","ERROR\n",2,51,3,auxDato))
        {
            printf("Error, titulo no valido\n");
            break;
        }
        strncpy(lista[pos].titulo,auxDato,51);
        lista[pos].isEmpty = 0;
        lista[pos].idLibro = pos;
        flag = 0;
        retorno = 0;
        printf("Alta Exitosa!!\n");
    }while(flag);

    return retorno;
}
//////////////////////////////////////
///////////////////////////////////////
void MenuLibros()
{
    printf("MENU LIBROS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Listar\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
