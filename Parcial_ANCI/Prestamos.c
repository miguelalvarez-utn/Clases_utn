#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prestamos.h"
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "utn.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array prestamos Array of prestamos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int prestamos_Inicializar(Prestamos array[], int size)                                    //cambiar prestamos
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int prestamos_buscarEmpty(Prestamos array[], int size, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamos_buscarID(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/


int prestamos_alta(Prestamos array[],Libros arrayB[],Autores arrayC[],int size,int sizeB,int sizeC,int* contadorID)                          //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    int auxIdA;
    int auxIdB;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(prestamos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libros
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            libros_ordenar(arrayB,sizeB);
            libros_listar(arrayB,sizeB);
            utn_getUnsignedInt("\nIngrese La ID del libro: ","\nError",1,sizeof(int),1,10,1,&auxIdA);
            if(libros_buscarID(arrayB,sizeB,auxIdA,&posicion))
            {
                printf("ID no existenete\n");
            }
            else
            {
                autores_ordenar(arrayC,sizeC);
                autores_listar(arrayC,sizeC);
                utn_getUnsignedInt("\nID del Autor: ","\nError",1,sizeof(int),1,10,1,&auxIdB);
                if(autores_buscarID(arrayC,sizeC,auxIdB,&posicion))
                {
                    printf("ID no existenete\n");
                }
                else
                {
                    if(utn_getFecha("\nIngrese fecha:\nEjemplo:nn/nn/nn: ","\nError",1,9,1,array[posicion].fecha)==1)
                    {
                       printf("fecha no valida");
                    }
                    else
                    {
                        printf("ALTA DE PRESTAMOS EXITOSA");
                        (*contadorID)++;
                        array[posicion].idLibro = auxIdA;
                        array[posicion].idAutor = auxIdB;
                        array[posicion].idUnico=*contadorID;                                                       //campo ID
                        array[posicion].isEmpty=0;
                        printf("\nID Prestamo: %d\nID Libro: %d\nID Autor: %d\nFecha: %s",
                               array[posicion].idUnico,
                               array[posicion].idLibro,
                               array[posicion].idAutor,
                               array[posicion].fecha);
                        retorno=0;
                    }

                }

            }

        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_baja(Prestamos array[], int sizeArray)                                      //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(prestamos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].idLibro=0;                                                               //cambiar campo idLibro                                           //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_bajaValorRepetidoInt(Prestamos array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].idLibro=0;                                                               //cambiar campo idLibro);                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int prestamos_listar(Prestamos array[], int size)                      //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                printf("\n---------------------------------------\n");
                printf("ID Prestamo: %d\nID Libro: %d\nID Autor: %d\nFecha %s",
                array[i].idUnico,
                array[i].idLibro,
                array[i].idAutor,
                array[i].fecha);
            }
     //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void prestamos_mock(Prestamos arrayPrestamos[], int size,int *contadorId)                      //cambiar prestamos
{
    //*******************************************************************
    int aux = 0;
    arrayPrestamos[0].idUnico=0;
    arrayPrestamos[0].isEmpty=0;
    arrayPrestamos[0].idLibro=2;
    arrayPrestamos[0].idAutor=1;
    strcpy(arrayPrestamos[0].fecha,"11/12/18");
    *contadorId =++ aux;

    arrayPrestamos[1].idUnico=1;
    arrayPrestamos[1].isEmpty=0;
    arrayPrestamos[1].idLibro=3;
    arrayPrestamos[1].idAutor=2;
    strcpy(arrayPrestamos[1].fecha,"11/12/18");
    *contadorId =++ aux;

    arrayPrestamos[2].idUnico=2;
    arrayPrestamos[2].isEmpty=0;
    arrayPrestamos[2].idLibro=0;
    arrayPrestamos[2].idAutor=3;
    strcpy(arrayPrestamos[2].fecha,"12/12/18");
    *contadorId =++ aux;

    arrayPrestamos[3].idUnico=3;
    arrayPrestamos[3].isEmpty=0;
    arrayPrestamos[3].idLibro=1;
    arrayPrestamos[3].idAutor=2;
    strcpy(arrayPrestamos[3].fecha,"12/12/18");
    *contadorId =++ aux;

    arrayPrestamos[4].idUnico=4;
    arrayPrestamos[4].isEmpty=0;
    arrayPrestamos[4].idLibro=1;
    arrayPrestamos[4].idAutor=2;
    strcpy(arrayPrestamos[4].fecha,"05/12/18");
    *contadorId =++ aux;

    arrayPrestamos[5].idUnico=5;
    arrayPrestamos[5].isEmpty=0;
    arrayPrestamos[5].idLibro=1;
    arrayPrestamos[5].idAutor=2;
    strcpy(arrayPrestamos[5].fecha,"05/12/18");

    arrayPrestamos[6].idUnico=6;
    arrayPrestamos[6].isEmpty=0;
    arrayPrestamos[6].idLibro=1;
    arrayPrestamos[6].idAutor=2;
    strcpy(arrayPrestamos[6].fecha,"05/12/18");


}
//////////////////////////////////
void MenuPrestamos()
{
    printf("\n\nMENU SUBMENU PRESTAMOS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Listar Prestamos\n");
    printf("3 - SALIR\n");
    printf("Elija opcion: ");
}
