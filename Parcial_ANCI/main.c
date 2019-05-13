#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Prestamos.h"
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "informes.h"
#define CANTIDAD_AUTORES 5
#define CANTIDAD_LIBROS 5
#define CANTIDAD_SOCIOS 5
#define CANTIDAD_PRESTAMOS 10
void init_contadorAux(aux_prestamos array[],int size);
int prestamos_alta(Prestamos array[],Libros arrayB[],Autores arrayC[],int size,int sizeB,int sizeC,int* contadorID);
//--------------------------
int main()
{
    int opcion1;
    int opcion;
    int contadorIdautores=0;
    Autores arrayAutores[CANTIDAD_AUTORES];
    autores_Inicializar(arrayAutores,CANTIDAD_AUTORES);
    autores_mock(arrayAutores, CANTIDAD_AUTORES, &contadorIdautores) ;
    //---------------------------------------------------------------
    int opcion2;
    int contadorIdlibros=0;
    Libros arrayLibros[CANTIDAD_LIBROS];
    libros_Inicializar(arrayLibros,CANTIDAD_LIBROS);
    libros_mock(arrayLibros, CANTIDAD_LIBROS, &contadorIdlibros);
    //--------------------------------------------------------------
    int opcion3;
    int contadorIdsocios = 0;
    Socios arraySocios[CANTIDAD_SOCIOS];
    socios_Inicializar(arraySocios,CANTIDAD_SOCIOS);
    socios_mock(arraySocios, CANTIDAD_SOCIOS, &contadorIdsocios);
    //--------------------------------------------------------------
    int opcion4;
    int contadorIdAux = 0;
    int contadorIdprestamos=0;
    Prestamos arrayPrestamos[CANTIDAD_PRESTAMOS];
    prestamos_Inicializar(arrayPrestamos,CANTIDAD_PRESTAMOS);
    prestamos_mock(arrayPrestamos, CANTIDAD_PRESTAMOS, &contadorIdprestamos) ;

    //--------------------------------------------------------------
    int opcion5;

    aux_prestamos arrayInformes[CANTIDAD_PRESTAMOS];


    do
    {
        MenuAutoresPrincipal();
           utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion);
        switch(opcion)
        {
            //------------------------------------------------------------------------
            case 1:
                do
                {
                    MenuAutores();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion1);
                    switch(opcion1)
                    {
                        case 1:
                            autores_alta(arrayAutores,CANTIDAD_AUTORES,&contadorIdautores);
                            break;
                        case 2:
                            autores_listar(arrayAutores,CANTIDAD_AUTORES);
                            autores_baja(arrayAutores,CANTIDAD_AUTORES);
                            break;
                        case 3:
                            autores_listar(arrayAutores,CANTIDAD_AUTORES);
                            autores_modificar(arrayAutores,CANTIDAD_AUTORES);
                            break;
                        case 4:
                            autores_ordenar(arrayAutores,CANTIDAD_AUTORES);
                            autores_listar(arrayAutores,CANTIDAD_AUTORES);
                            break;
                    }
                }while(opcion1 != 5);
                break;
            //----------------------------------------------------------------------------
            case 2:
                do
                {
                    MenuLibros();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion2);
                    switch(opcion2)
                    {
                        case 1:
                            libros_alta(arrayLibros,arrayAutores,CANTIDAD_LIBROS,CANTIDAD_AUTORES,&contadorIdlibros);
                            break;
                        case 2:
                            libros_listar(arrayLibros,CANTIDAD_LIBROS);
                            libros_baja(arrayLibros,CANTIDAD_LIBROS);
                            break;
                        case 3:
                            libros_listar(arrayLibros,CANTIDAD_LIBROS);
                            libros_modificar(arrayLibros,arrayAutores,CANTIDAD_LIBROS,CANTIDAD_AUTORES);
                            break;
                        case 4:
                            libros_ordenar(arrayLibros,CANTIDAD_LIBROS);
                            libros_listar(arrayLibros,CANTIDAD_LIBROS);

                            break;
                    }
                }while(opcion2 != 5);
                break;
            //----------------------------------------------------------------------------
            case 3:
                do
                {
                    MenuSocios();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion3);
                    switch(opcion3)
                    {
                        case 1:
                            socios_alta(arraySocios,CANTIDAD_SOCIOS,&contadorIdsocios);
                            break;
                        case 2:
                            socios_listar(arraySocios,CANTIDAD_SOCIOS);
                            socios_baja(arraySocios,CANTIDAD_SOCIOS);
                            break;
                        case 3:
                            socios_listar(arraySocios,CANTIDAD_SOCIOS);
                            socios_modificar(arraySocios,CANTIDAD_SOCIOS);
                            break;
                        case 4:
                            socios_ordenar(arraySocios,CANTIDAD_SOCIOS);
                            socios_listar(arraySocios,CANTIDAD_SOCIOS);
                            break;
                    }
                }while(opcion3 != 5);
                break;
            //----------------------------------------------------------------------------
            case 4:
                do
                {
                    MenuPrestamos();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,3,1,&opcion4);
                    switch(opcion4)
                    {
                        case 1:
                            prestamos_alta(arrayPrestamos,
                                           arrayLibros,
                                           arrayAutores,
                                           CANTIDAD_PRESTAMOS,
                                           CANTIDAD_LIBROS,
                                           CANTIDAD_AUTORES,
                                           &contadorIdprestamos);
                            break;
                        case 2:
                            prestamos_listar(arrayPrestamos,CANTIDAD_PRESTAMOS);
                            break;
                    }
                }while(opcion1 != 3);
                break;
            //----------------------------------------------------------------------------
            case 5:
                do
                {
                    MenuInformes();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,11,1,&opcion5);
                    switch(opcion5)
                    {
                        case 1:
                            break;
                    }
                }while(opcion5 != 11);

                break;

        }
    }while(opcion != 6);
    return 0;
}
