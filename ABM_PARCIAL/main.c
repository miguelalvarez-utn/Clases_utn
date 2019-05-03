#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantallas.h"
#include "Publicidad.h"
//--------------------------
#define CANTIDAD_CLIENTES 10
//--------------------------
#define CANTIDAD_MONITORES 10
//--------------------------
#define NAME_MAX_CHARACT 50
#define NAME_MIN_CHARACT 2
//--------------------------
#define DIRECT_MAX_CHARACT 20
#define DIRECT_MIN_CHARACT 2
//--------------------------
#define PRICE_MAX_CHARACT 20
#define PRICE_MIN_CHARACT 1
//--------------------------
#define TYPE_MAX_CHARCT 4
//--------------------------
#define VALOR_ESPACIO_LIBRE -1
#define VALOR_ESPACIO_OCUPADO 1
//--------------------------
#define OPCION_MAX_MENU 11
#define OPCION_MIN_MENU 1
//--------------------------
#define ID_MAX_CHARACT 20
#define ID_MIN_CHARACT 1
//--------------------------
#define CUIT_MAX_CHAR 14
#define CUIT_MIN_CHAR 1
//--------------------------
#define DIAS_MAX_CHAR 5
#define DIAS_MIN_CHAR 1
//--------------------------
#define ARCHIVO_MAX_CHAR 128
#define ARCHIVO_MIN_CHAR 1
//--------------------------
#define DIGIT_OPTION 3

int main()
{
    //-------------------------------------
    Publicidad_Pantalla auxliresId[CANTIDAD_CLIENTES];
    //-------------------------------------
    publicidad clientes[CANTIDAD_CLIENTES];
    //-------------------------------------
    char auxCuit[CUIT_MAX_CHAR];
    char auxDias[DIAS_MAX_CHAR];
    char auxArchivo[ARCHIVO_MAX_CHAR];
    char auxMonitores[CANTIDAD_MONITORES];
    //-------------------------------------
    pantallas monitores[CANTIDAD_MONITORES];
    //-------------------------------------
    char auxNombre[NAME_MAX_CHARACT];
    char auxDireccion[DIRECT_MAX_CHARACT];
    char auxPrecio[PRICE_MAX_CHARACT];
    char auxTipoPantalla[TYPE_MAX_CHARCT];
    //-------------------------------------
    char idBaja[ID_MAX_CHARACT];
    char idContratacion[ID_MAX_CHARACT];
    char auxOpcion[DIGIT_OPTION];
    char idModificacion[ID_MAX_CHARACT];
    //-------------------------------------
    int idValida;
    int opcionMenu;
    int opcionMod;
    int opcionType;
    int opcionType2;
    int opcionModPublic;
    int espacioLibre;
    int auxId = 0;
    int auxIdClientes = 0;
    int i,j;
    inicializarEspaciosA(monitores,CANTIDAD_MONITORES,VALOR_ESPACIO_LIBRE);
    inicializarEspaciosB(clientes,CANTIDAD_CLIENTES,VALOR_ESPACIO_LIBRE);
    do
    {
        MenuPantalla();
        if(getOption("Error, ingrese numeros\n",

        "Error, opcion fuera de rango\n",
        "Supera la cantidad de caracteres\n",
        OPCION_MIN_MENU,
        OPCION_MAX_MENU,
        auxOpcion))
        {
            printf("Opcion invalida!!\n");
            break;
        }
        opcionMenu = atoi(auxOpcion);
        switch(opcionMenu)
        {
            case 1:
                system("cls");
                espacioLibre = buscarEspacioLibreA(monitores,CANTIDAD_MONITORES,VALOR_ESPACIO_LIBRE);
                if(espacioLibre == VALOR_ESPACIO_LIBRE)
                {
                    printf("No hay lugar para dar de alta");
                    break;
                }
                monitores[espacioLibre].isEmpty = VALOR_ESPACIO_OCUPADO;
                alta(monitores,espacioLibre);
                monitores[espacioLibre].idPantallas =++auxId;
                break;
            case 2:
                system("cls");
                listar(monitores,CANTIDAD_MONITORES);
                getId("Ingrese ID a modificar: ",
                      "Error, ingrese numeros\n",
                      ID_MIN_CHARACT,
                      ID_MAX_CHARACT,
                      idModificacion);
                espacioLibre = buscarEspacioLibreA(monitores,CANTIDAD_MONITORES,atoi(idModificacion));
                if(espacioLibre == VALOR_ESPACIO_LIBRE)
                {
                    printf("ID Inexistente");
                    break;
                }

                do
                {
                    MenuPantallaMod();
                    getOption("Error, ingrese numeros\n",
                              "Error, opcion fuera de rango\n",
                              "Supera la cantidad de caracteres",
                              OPCION_MIN_MENU,
                              OPCION_MAX_MENU,
                              auxOpcion);
                    opcionMod = atoi(auxOpcion);
                    switch(opcionMod)
                    {
                        case 1:
                            getName("Ingrese nombre: ",
                            "Error, supera cantidad de caracteres\n",
                            "Error, el nombre no es valido\n",
                            NAME_MIN_CHARACT,
                            NAME_MAX_CHARACT,
                            auxNombre);
                            strncpy(monitores[espacioLibre].nombre,auxNombre,NAME_MAX_CHARACT);
                            break;
                        case 2:
                            getAlfaNumerico("Ingrese direccion: ",
                            "Error, supera cantidad de caracteres\n",
                            "Error, el nombre no es valido\n",
                            NAME_MIN_CHARACT,NAME_MAX_CHARACT,
                            auxDireccion);
                            strncpy(monitores[espacioLibre].direccion,auxDireccion,DIRECT_MAX_CHARACT);
                            break;
                        case 3:
                            getPricio(  "ingrese precio: ",
                            "Supera la cantidad de caracteres\n",
                            "Error, el precio no puede contener letras\n",
                            PRICE_MIN_CHARACT,
                            PRICE_MAX_CHARACT,
                            auxPrecio);
                            strncpy(monitores[espacioLibre].precio,auxPrecio,DIRECT_MAX_CHARACT);
                            break;
                        case 4:
                            do
                            {
                                MenuType();
                                getOption("Error, ingrese numeros\n",
                                "Error, opcion fuera de rango\n",
                                "Supera la cantidad de caracteres",
                                OPCION_MIN_MENU,
                                OPCION_MAX_MENU,
                                auxOpcion);
                                opcionType2 = atoi(auxOpcion);
                                switch(opcionType2)
                                    {
                                        case 1:
                                            strncpy(auxTipoPantalla,"LCD",TYPE_MAX_CHARCT);
                                            break;
                                        case 2:
                                            strncpy(auxTipoPantalla,"LED",TYPE_MAX_CHARCT);
                                            break;
                                    }
                            }while(opcionType2 != 3);
                            strncpy(monitores[espacioLibre].tipoPantalla,auxTipoPantalla,TYPE_MAX_CHARCT);
                            break;
                    }
                }while(opcionMod != 5);
                break;
            case 3:
                system("cls");
                listar(monitores,CANTIDAD_MONITORES);
                getId("Ingrese ID a dar de baja: ","Error, ingrese numeros\n",ID_MIN_CHARACT,ID_MAX_CHARACT,idBaja);
                espacioLibre = buscarEspacioLibreA(monitores,CANTIDAD_MONITORES,atoi(idBaja));
                if(espacioLibre == VALOR_ESPACIO_LIBRE)
                {
                    printf("No existe esa ID en la base de datos");
                    break;
                }
                monitores[espacioLibre].isEmpty = VALOR_ESPACIO_LIBRE;
                printf("Baja exitosa\n");
                break;
            case 4:
                system("cls");
                espacioLibre = buscarEspacioLibreB(clientes,CANTIDAD_CLIENTES,VALOR_ESPACIO_LIBRE);
                if(espacioLibre == VALOR_ESPACIO_LIBRE)
                {
                    printf("No hay lugar para dar de alta");
                    break;
                }
                clientes[espacioLibre].isEmpty = VALOR_ESPACIO_OCUPADO;
                printf("DEBUG: is empty = %d//pos %d\n",monitores[espacioLibre].isEmpty,espacioLibre);

                listar(monitores,CANTIDAD_MONITORES);
                getId("Ingrese ID de la pantalla a contratar: ",
                      "Error, ingrese numeros\n",
                      ID_MIN_CHARACT,
                      ID_MAX_CHARACT,
                      idContratacion);
                idValida = buscarPorId(monitores,CANTIDAD_MONITORES,atoi(idContratacion));
                if(idValida == VALOR_ESPACIO_LIBRE)
                {
                    printf("No hay ID en la base de datos");
                    break;
                }
                clientes[espacioLibre].idPantalla = idValida;
                getCuit("\nEj: nn-nnnnnnnn-n\nIngrese nro de CUIT: ",
                        "Error, ingrese numeros",
                        "Error, el cuit incompleto",
                        "Error, cuit invalido",
                        CUIT_MIN_CHAR,
                        CUIT_MAX_CHAR,
                        auxCuit);
                        strncpy(clientes[espacioLibre].cuit,auxCuit,CUIT_MAX_CHAR);
                getDias(  "ingrese cant.Dias a contratar: ",
                          "Supera la cantidad de caracteres\n",
                          "Error, los dias no puede contener letras\n",
                          DIAS_MIN_CHAR,
                          DIAS_MAX_CHAR,
                          auxDias);
                          strncpy(clientes[espacioLibre].diasContratacion,auxDias,DIAS_MAX_CHAR);
                getArchivo("Ingrese nombre de archivo: ",
                            "Error, supera cantidad de caracteres\n",
                            "Error, el nombre no es valido\n",
                            ARCHIVO_MIN_CHAR,
                            ARCHIVO_MAX_CHAR,
                            auxArchivo);
                            strncpy(clientes[espacioLibre].archivo,auxArchivo,ARCHIVO_MAX_CHAR);
                            clientes[espacioLibre].idPublicidad =++auxIdClientes;
                            break;
            case 5:
                system("cls");
                listarPublicidad(clientes,CANTIDAD_CLIENTES);
                getId("Ingrese ID a modificar: ",
                      "Error, ingrese numeros\n",
                      ID_MIN_CHARACT,
                      ID_MAX_CHARACT,
                      idContratacion);
                      espacioLibre = buscarEspacioLibreB(clientes,CANTIDAD_CLIENTES,atoi(idContratacion));
                if(espacioLibre == VALOR_ESPACIO_LIBRE)
                {
                    printf("ID Inexistente");
                    break;
                }

                do
                {
                    MenuPublicidadMod();
                    getOption("Error, ingrese numeros\n",
                              "Error, opcion fuera de rango\n",
                              "Supera la cantidad de caracteres",
                              OPCION_MIN_MENU,
                              OPCION_MAX_MENU,
                              auxOpcion);
                    opcionModPublic = atoi(auxOpcion);
                    switch(opcionModPublic)
                    {
                        case 1:
                            getCuit("\nEj: nn-nnnnnnnn-n\nIngrese nro de CUIT: ",
                            "Error, ingrese numeros",
                            "Error, el cuit incompleto",
                            "Error, cuit invalido",
                            CUIT_MIN_CHAR,
                            CUIT_MAX_CHAR,
                            auxCuit);
                            strncpy(clientes[espacioLibre].cuit,auxCuit,CUIT_MAX_CHAR);
                            break;
                        case 2:
                            getDias(  "ingrese cant.Dias a contratar: ",
                            "Supera la cantidad de caracteres\n",
                            "Error, los dias no puede contener letras\n",
                            DIAS_MIN_CHAR,
                            DIAS_MAX_CHAR,
                            auxDias);
                            strncpy(clientes[espacioLibre].diasContratacion,auxDias,DIAS_MAX_CHAR);
                            break;
                        case 3:
                            getArchivo("Ingrese nombre de archivo: ",
                            "Error, supera cantidad de caracteres\n",
                            "Error, el nombre no es valido\n",
                            ARCHIVO_MIN_CHAR,
                            ARCHIVO_MAX_CHAR,
                            auxArchivo);
                            strncpy(clientes[espacioLibre].archivo,auxArchivo,ARCHIVO_MAX_CHAR);
                            break;
                    }
                }while(opcionModPublic != 4);
                break;
            case 6:
                system("cls");
                listarPublicidad(clientes,CANTIDAD_CLIENTES);
                if(clientes[0].idPublicidad == 0)
                {
                    printf("No hay clientes disponibles");
                    break;
                }
                espacioLibre = buscarEspacioLibreB(clientes,CANTIDAD_CLIENTES,atoi(idBaja));
                if(espacioLibre == VALOR_ESPACIO_LIBRE)
                {
                    printf("No existe esa ID en la base de datos");
                    break;
                }
                getId("Ingrese ID a dar de baja: ","Error, ingrese numeros\n",ID_MIN_CHARACT,ID_MAX_CHARACT,idBaja);
                clientes[espacioLibre].isEmpty = VALOR_ESPACIO_LIBRE;
                printf("Baja exitosa\n");
                break;
            case 7:
                system("cls");
                if(getCuit("\nEj: nn-nnnnnnnn-n\nIngrese nro de CUIT: ",
                "Error, ingrese numeros",
                "Error, el cuit incompleto",
                "Error, cuit invalido",
                CUIT_MIN_CHAR,
                CUIT_MAX_CHAR,
                auxCuit))
                {
                    break;
                }
                if(buscarPorCuitFacturacion(clientes,
                monitores,
                CANTIDAD_CLIENTES,
                auxCuit,
                "Facturacion total por los servicios contratados: ",
                "Descripcion de servicios:\n"))
                {
                    printf("El cuit no esta registrado");
                    break;
                }
                break;
            case 8:
                system("cls");
                if(getCuit("\nEj: nn-nnnnnnnn-n\nIngrese nro de CUIT: ",
                        "Error, ingrese numeros",
                        "Error, el cuit incompleto",
                        "Error, cuit invalido",
                        CUIT_MIN_CHAR,
                        CUIT_MAX_CHAR,
                        auxCuit))
                {
                    break;
                }
                if(buscarPorCuit(clientes,
                                 monitores,
                                 CANTIDAD_CLIENTES,
                                 auxCuit,
                                 "Cantidad de publicaciones contratadas: ",
                                 "Descripcion de servicios:\n"))
                {
                    printf("El cuit no esta registrado");
                    break;
                }
                break;
            case 9:
                system("cls");


                if(monitores[0].idPantallas == 0)
                {
                    printf("No hay pantallas disponibles");
                    break;
                }
                listar(monitores,CANTIDAD_MONITORES);

                break;
            case 10:
                system("cls");
                if(clientes[0].idPublicidad == 0)
                {
                    printf("No hay clientes para listar");
                    break;
                }
                imprimirGeneral(clientes,monitores,CANTIDAD_CLIENTES);
                break;

        }
    }while(opcionMenu != 11);
    return 0;
}
