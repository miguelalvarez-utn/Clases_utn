#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "input.h"
#include "Libros.h"
////////////////////////////////////////////
int aut_initArray(t_autores lista[],int len)
{
    int retorno=1;
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].isEmpty =1;
    }
    return retorno;
}
///////////////////////////////////////////
int aut_buscarLibre(t_autores lista[], int len)
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
///////////////////////////////////////////
int aut_alta(t_autores lista[],int len,int pos)
{
    int retorno = -1;
    int flag = 1;
    char auxDato[51];
    do
    {
        if(getName("Ingrese el nombre del autor\n","ERROR\n",2,51,3,auxDato))
        {
            printf("Error, nombre no valido\n");
            break;
        }
        strncpy(lista[pos].nombre,auxDato,51);
        if(getName("Ingrese el apellido del autor\n","ERROR\n",2,51,3,auxDato))
        {
            printf("Error, apellido no valido\n");
            break;
        }
        strncpy(lista[pos].apellido,auxDato,51);
        lista[pos].isEmpty = 0;
        lista[pos].idAutor = pos;
        flag = 0;
        retorno = 0;
        printf("Alta Exitosa!!\n");
    }while(flag);

    return retorno;
}
///////////////////////////////////////////
int aut_baja(t_autores lista[],int len, int id)
{
    int retorno = -1;
    int i;
    for(i = 0;i < len; i++)
    {
        if(lista[i].isEmpty != 1)
        {
            if(lista[i].idAutor == id)
            {
                printf("Baja Exitosa!!\n");
                lista[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
        printf("Esa id no existe\n");
        break;
    }

    return retorno;
}
///////////////////////////////////////////
int aut_modificar(t_autores lista[],int len, int id)
{
    int retorno = -1;
    int i;
    for(i = 0;i < len; i++)
    {
        if(lista[i].isEmpty != 1)
        {
            if(lista[i].idAutor == id)
            {
                modidificaciones(lista,i);
                retorno = 0;
                break;
            }
        }
        printf("Esa id no existe\n");
        break;
    }

    return retorno;
}
////////////////////////////////////////////
int modidificaciones(t_autores lista[], int pos)
{
    int retorno = -1;
    int opcion;
    char auxDato[51];
    do
    {
        menuMod();
        getInter("Ingrese un opcion","Error",1,3,&opcion);
        switch(opcion)
        {
            case 1:
                if(getName("Ingrese el nombre del autor\n","ERROR\n",2,51,3,auxDato))
                {
                    printf("Error, nombre no valido\n");
                    break;
                }
                strncpy(lista[pos].nombre,auxDato,51);
                break;
            case 2:
                if(getName("Ingrese el apellido del autor\n","ERROR\n",2,51,3,auxDato))
                {
                    printf("Error, apellido no valido\n");
                    break;
                }
                strncpy(lista[pos].apellido,auxDato,51);
        }

    }while(opcion != 3);
}
///////////////////////////////////////////
int aut_imprimirLista(t_autores lista[],int len)
{
    int retorno = -1;
    int i;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0)
        {
            printf("%6d %5s %5s\n",lista[i].idAutor,lista[i].nombre,lista[i].apellido);
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////
void MenuPrincipal()
{
    printf("MENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - Autores\n");
    printf("2 - LED\n");
    printf("Elija opcion: ");
}
////////////////////////////////////////////
void menuMod()
{
    printf("MENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - Nombre\n");
    printf("2 - Apellido\n");
    printf("3 - SALIR\n");
    printf("Elija opcion: ");
}
///////////////////////////////////////////

void MenuAutores()
{
    printf("MENU AUTOR\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Listar\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}

