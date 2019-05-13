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
* \param array socios Array of socios
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socios_Inicializar(Socios array[], int size)                                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socios_buscarEmpty(Socios array[], int size, int* posicion)                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
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

//String
/** \brief Busca un string en un array
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarString(Socios array[], int size, char* valorBuscado, int* indice)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array socios Array de socios
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socios_alta(Socios array[], int size, int* contadorID)                          //cambiar socios
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(socios_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socios
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("\nIngrese apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);
            utn_getSex("\nIngrese sexo f o m: ",&array[posicion].sexo);
            utn_getEmail("\nIngrese eMail: ","Error",1,TEXT_SIZE,1,array[posicion].eMail);
            utn_getTelefono("\ntelefono: ","Error",1,TEXT_SIZE,1,sizeof(int),2,array[posicion].telefono);
            utn_getFecha("\nIngrese fecha:\nEjemplo:nn/nn/nn: ","\nError",1,TEXT_SIZE,1,array[posicion].fecha);



                            //mensaje + cambiar campo apellido
            printf("ID: %d\nNombre: %s\nApellido: %s\nSexo: %c\neMail: %s\nTelefono: %s\nFecha: %s",
                    array[posicion].idUnico,
                    array[posicion].nombre,
                    array[posicion].apellido,
                    array[posicion].sexo,
                    array[posicion].eMail,
                    array[posicion].telefono,
                    array[posicion].fecha);

            retorno=0;
        }
    }
    return retorno;
}
////////////////////////////////////////

////////////////////////////////////////

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_baja(Socios array[], int sizeArray)                                      //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id                                                             //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socios Array de socios
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                array[i].idUnico=0;                                                                   //cambiar campo id                                                             //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int socios_modificar(Socios array[], int sizeArray)                                //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       MenuSociosModificacion();

                utn_getUnsignedInt("","\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("Nombre: ","\nError\n",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 2:
                        utn_getTexto("Apellido: ","\nError\n",1,TEXT_SIZE,1,array[posicion].apellido);
                        break;
                    case 3:
                        utn_getSex("\nIngrese sexo f o m: ",&array[posicion].sexo);
                        break;
                    case 4:
                        utn_getTelefono("\ntelefono: ","Error",1,TEXT_SIZE,1,sizeof(int),2,array[posicion].telefono);//mensaje + cambiar campo apellido
                        break;
                    case 5:
                        utn_getEmail("\nIngrese eMail: ","Error",1,TEXT_SIZE,1,array[posicion].eMail);
                        break;
                    default:
                        printf("\nOpcion no valida\n");
                }
            }while(opcion!=6);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array socios Array de socios
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond)                              //cambiar socios
{
    int retorno=-1;
    int i;
    Socios buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }

            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socios_listar(Socios array[], int size)                      //cambiar socios
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
            printf("ID: %d\nNombre: %s\nApellido: %s\nSexo: %c\neMail: %s\nTelefono: %s\nFecha: %s",
                    array[i].idUnico,
                    array[i].nombre,
                    array[i].apellido,
                    array[i].sexo,
                    array[i].eMail,
                    array[i].telefono,
                    array[i].fecha);     //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array socios Array de socios
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socios_ordenar(Socios array[],int size)
{
   int i,j;
   int retorno;
   Socios buffer;

   for(i = 0;i < size-1;i++)
   {
       for(j =i+1;j < size-1;j++)
       {
           if(strcmp(array[i].apellido,array[j].apellido)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
           else if(strcmp(array[i].nombre,array[j].nombre)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
       }
   }
   return retorno;
}

void socios_mock(Socios arraySocios[], int size,int *contadorId)                      //cambiar socios
{
    //*******************************************************************
    int aux = 0;
    arraySocios[0].idUnico=0;
    arraySocios[0].isEmpty=0;
    strcpy(arraySocios[0].apellido,"CCCCC");
    strcpy(arraySocios[0].nombre,"CCCCC");
    arraySocios[0].sexo = 'm';
    strcpy(arraySocios[0].eMail,"CCCCC.com");
    strcpy(arraySocios[0].telefono,"12345678");
    strcpy(arraySocios[0].fecha,"10/12/18");

    *contadorId =++ aux;

    arraySocios[1].idUnico=1;
    arraySocios[1].isEmpty=0;
    strcpy(arraySocios[1].apellido,"AAAAA");
    strcpy(arraySocios[1].nombre,"AAAAA");
    arraySocios[1].sexo = 'f';
    strcpy(arraySocios[1].eMail,"CCCCC.com");
    strcpy(arraySocios[1].telefono,"12345678");
    strcpy(arraySocios[1].fecha,"10/10/19");

    *contadorId =++ aux;

    arraySocios[2].idUnico=2;
    arraySocios[2].isEmpty=0;
    strcpy(arraySocios[2].apellido,"BBBBB");
    strcpy(arraySocios[2].nombre,"CCCCCC");
    arraySocios[2].sexo = 'm';
    strcpy(arraySocios[2].eMail,"CCCCC.com");
    strcpy(arraySocios[2].telefono,"12345678");
    strcpy(arraySocios[2].fecha,"10/07/15");

    *contadorId =++ aux;

    arraySocios[3].idUnico=3;
    arraySocios[3].isEmpty=0;
    strcpy(arraySocios[3].apellido,"BBBBB");
    strcpy(arraySocios[3].nombre,"BBBBBB");
    arraySocios[3].sexo = 'f';
    strcpy(arraySocios[3].eMail,"CCCCC.com");
    strcpy(arraySocios[3].telefono,"15626984");
    strcpy(arraySocios[3].fecha,"10/05/16");


}
//////////////////////////////////
void MenuSocios()
{
    printf("\n\nMENU SUBMENU SOCIO\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Listar\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
//////////////////////////////////
void MenuSociosModificacion()
{
    printf("\n\nMENU MODIFICACION SOCIOS\n");
    printf("--------------\n");
    printf("1 - Nuevo Nombre\n");
    printf("2 - Nuevo Apellido\n");
    printf("3 - Nuevo Sexo\n");
    printf("4 - Nuevo Telefono\n");
    printf("5 - Nuevo eMail\n");
    printf("6 - SALIR\n");
    printf("Elija opcion: ");
}

