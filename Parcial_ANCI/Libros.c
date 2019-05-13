#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Prestamos.h"
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libros Array of libros
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libros_Inicializar(Libros array[], int size)                                    //cambiar libros
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
* \param array libros Array de libros
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libros_buscarEmpty(Libros array[], int size, int* posicion)                    //cambiar libros
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
* \param array libros Array de libros
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarID(Libros array[], int size, int valorBuscado, int* posicion)                    //cambiar libros
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
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array libros Array de libros
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libros_buscarInt(Libros array[], int size, int valorBuscado, int* posicion)                    //cambiar libros
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idAutor==valorBuscado)                                                   //cambiar campo idAutor
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array libros Array de libros
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libros_alta(Libros array[], Autores arrayB[], int size, int sizeB,int* contadorID)                          //cambiar libros
{
    int retorno=-1;
    int posicion;
    int auxId;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(libros_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libros
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            utn_getUnsignedInt("\nID del autor: ","\nError",1,sizeof(int),1,10,1,&auxId);
            if(autores_buscarID(arrayB,sizeB,auxId,&posicion))
            {
                printf("ID no existenete\n");
            }
            else
            {
                (*contadorID)++;
                array[posicion].idAutor = auxId;
                array[posicion].idUnico=*contadorID;                                                       //campo ID
                array[posicion].isEmpty=0;
                utn_getTexto("\nTitulo: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);                 //mensaje + cambiar campo titulo
                printf("ID: %d\nID AUTOR: %d\nTITULO: %s",
                array[posicion].idUnico,
                array[posicion].idAutor,
                array[posicion].titulo);
                retorno=0;
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array libros Array de libros
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libros_baja(Libros array[], int sizeArray)                                      //cambiar libros
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].idAutor=0;                                                               //cambiar campo idAutor                                                            //cambiar campo varFloat                                                  //cambiar campo varString
            strcpy(array[posicion].titulo,"");                                               //cambiar campo titulo
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array libros Array de libros
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libros_bajaValorRepetidoInt(Libros array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].idAutor=0;                                                               //cambiar campo idAutor                                                 //cambiar campo varString
                strcpy(array[i].titulo,"");                                               //cambiar campo titulo
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array libros Array de libros
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libros_modificar(Libros array[], Autores arrayB[] ,int sizeArray,int sizeArrayB)                                //cambiar libros
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(libros_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       MenuLibrosModificacion();

                utn_getUnsignedInt("","\nError",1,sizeof(int),1,3,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getUnsignedInt("\nID del autor: ","\nError",1,sizeof(int),1,10,1,&id);
                        if(autores_buscarID(arrayB,sizeArrayB,id,&posicion))
                        {
                            printf("ID no existenete\n");
                            break;
                        }
                        else
                        {
                            array[posicion].idAutor = id;
                        }
                        break;
                    case 2:
                        utn_getTexto("Titulo del libro: ","\nError\n",1,TEXT_SIZE,1,array[posicion].titulo);
                        break;
                    default:
                        printf("\nOpcion no valida\n");
                }
            }while(opcion!=3);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array libros Array de libros
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libros_listar(Libros array[], int size)                      //cambiar libros
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
                printf("\n---------------------------------------\n");
                printf("\n ID Lbro: %d\n ID Autor: %d\ntitulo: %s\n",
                       array[i].idUnico,
                       array[i].idAutor,
                       array[i].titulo);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array libros Array de libros
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libros_ordenar(Libros array[],int size)
{
   int i,j;
   int retorno;
   Libros buffer;

   for(i = 0;i < size-1;i++)
   {
       for(j =i+1;j < size-1;j++)
       {
           if(strcmp(array[i].titulo,array[j].titulo)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
               if(array[i].idAutor > array[j].idAutor)
               {
                    buffer = array[i];
                    array[i] = array[j];
                    array[j] = buffer;
                    retorno = 0;
               }
           }


       }
   }
   return retorno;
}

void libros_mock(Libros arrayLibros[], int size,int *contadorId)                      //cambiar libros
{
    //*******************************************************************
    int aux = 0;
    arrayLibros[0].idUnico=0;
    arrayLibros[0].isEmpty=0;
    arrayLibros[0].idAutor=1;
    strcpy(arrayLibros[0].titulo,"CCCCC");
    *contadorId =++ aux;

    arrayLibros[1].idUnico=1;
    arrayLibros[1].isEmpty=0;
    arrayLibros[1].idAutor=2;
    strcpy(arrayLibros[1].titulo,"AAAAA");
    *contadorId =++ aux;

    arrayLibros[2].idUnico=2;
    arrayLibros[2].isEmpty=0;
    arrayLibros[2].idAutor=1;
    strcpy(arrayLibros[2].titulo,"BBBBB");
    *contadorId =++ aux;

    arrayLibros[3].idUnico=3;
    arrayLibros[3].isEmpty=0;
    arrayLibros[3].idAutor=3;
    strcpy(arrayLibros[3].titulo,"BBBBB");

}
//////////////////////////////////
void MenuLibros()
{
    printf("\n\nMENU SUBMENU LIBROS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Listar\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuLibrosPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - struct1\n");
    printf("2 - struct2\n");
    printf("3 - struct3\n");
    printf("4 - struct4\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
////////////////////////////////////
void MenuLibrosModificacion()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - Nuevo id autor\n");
    printf("2 - Nuevo titulo\n");
    printf("3 - salir\n");
    printf("Elija opcion: ");
}

