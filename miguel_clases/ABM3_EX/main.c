#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autores.h"
#include "input.h"
#include "Libros.h"
#define CANTIDAD_AUTORES 5
#define CANTIDAD_LIBROS 5
int main()
{
    t_autores autor[CANTIDAD_AUTORES];
    t_libros libros[CANTIDAD_LIBROS];

    aut_initArray(autor,CANTIDAD_AUTORES);
    lib_initArray(libros,CANTIDAD_LIBROS);

    int auxId;
    int opcion;
    int opcionLib;
    int opcionAut;
    int espacioLibre;
    //------------------------------------
    do
    {
        MenuPrincipal();
        getInter("Ingrese una opcion del 1 al 5\n","ERROR. ",1,5,&opcion);
        switch(opcion)
        {
            case 1:
                do
                {

                    MenuAutores();
                    getInter("Ingrese una opcion del 1 al 5\n","ERROR. ",1,5,&opcionAut);
                    switch(opcionAut)
                    {
                        case 1:
                            espacioLibre = aut_buscarLibre(autor,CANTIDAD_AUTORES);
                            aut_alta(autor,CANTIDAD_AUTORES,espacioLibre);
                            break;
                        case 2:
                            if(aut_imprimirLista(autor,CANTIDAD_AUTORES) < 0)
                            {
                                printf("No hay autores cargados\n");
                                break;
                            }
                            getInter("Ingrese ID","Error",0,5,&auxId);
                            aut_baja(autor,CANTIDAD_AUTORES,auxId);
                            break;
                        case 3:
                            if(aut_imprimirLista(autor,CANTIDAD_AUTORES) < 0)
                            {
                                printf("No hay autores cargados\n");
                                break;
                            }
                            getInter("Ingrese ID","Error",0,5,&auxId);
                            aut_modificar(autor,CANTIDAD_AUTORES,auxId);
                        case 4:
                            if(aut_imprimirLista(autor,CANTIDAD_AUTORES) < 0)
                            {
                                printf("No hay autores cargados\n");
                                break;
                            }
                            break;
                    }
                }while(opcionAut != 5);
                break;
            case 2:
                do
                {
                    MenuLibros();
                    getInter("Ingrese una opcion del 1 al 5\n","ERROR. ",1,5,&opcionLib);
                    switch(opcionLib)
                    {
                        case 1:
                            espacioLibre = lib_buscarLibre(libros,CANTIDAD_LIBROS);
                            lib_alta(libros,CANTIDAD_LIBROS,espacioLibre);
                            break;

                    }
                }while(opcionLib != 5);
                break;
        }

    }while(opcion != 5);
    return 0;
}
