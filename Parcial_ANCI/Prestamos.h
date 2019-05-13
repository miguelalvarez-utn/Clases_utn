#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "PRESTAMOS X EL QUE QUIERAS(todo mayuscula)"
    "Prestamos x el que Quieras(primer letra en mayuscula)""prestamoss x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int idLibro;
    int idAutor;
    char fecha[9];
}Prestamos;


#endif // PRESTAMOS_H_INCLUDED

int prestamos_Inicializar(Prestamos array[], int size);                                    //cambiar prestamos
int prestamos_buscarEmpty(Prestamos array[], int size, int* posicion);                    //cambiar prestamos
int prestamos_buscarID(Prestamos array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamos
int prestamos_buscarInt(Prestamos array[], int size, int valorBuscado, int* posicion);                    //cambiar prestamos
int prestamos_buscarString(Prestamos array[], int size, char* valorBuscado, int* indice);                    //cambiar prestamos
int prestamos_baja(Prestamos array[], int sizeArray);                                      //cambiar prestamos
int prestamos_bajaValorRepetidoInt(Prestamos array[], int sizeArray, int valorBuscado);
int prestamos_modificar(Prestamos array[], int sizeArray);                                //cambiar prestamos
int prestamos_ordenarPorDobleCriterio(Prestamos array[],int size, int orderFirst, int orderSecond);                                  //cambiar prestamos
int prestamos_listar(Prestamos array[], int size);                      //cambiar prestamos
void prestamos_mock(Prestamos arrayPrestamos[], int size,int *contadorId);                      //cambiar prestamos
void MenuPrestamos();
void MenuPrestamosPrincipal();
void MenuPrestamosModificacion();
int prestamos_ordenar(Prestamos array[],int size);


