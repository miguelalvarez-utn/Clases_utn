#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED
#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "AUTORES X EL QUE QUIERAS(todo mayuscula)"
    "Autores x el que Quieras(primer letra en mayuscula)""autoress x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];

}Autores;


#endif // AUTORES_H_INCLUDED

int autores_Inicializar(Autores array[], int size);                                    //cambiar autores
int autores_buscarEmpty(Autores array[], int size, int* posicion);                    //cambiar autores
int autores_buscarID(Autores array[], int size, int valorBuscado, int* posicion);                    //cambiar autores
int autores_buscarInt(Autores array[], int size, int valorBuscado, int* posicion);                    //cambiar autores
int autores_buscarString(Autores array[], int size, char* valorBuscado, int* indice);                    //cambiar autores
int autores_alta(Autores array[], int size, int* contadorID);                          //cambiar autores
int autores_baja(Autores array[], int sizeArray);                                      //cambiar autores
int autores_bajaValorRepetidoInt(Autores array[], int sizeArray, int valorBuscado);
int autores_modificar(Autores array[], int sizeArray);                                //cambiar autores
int autores_ordenarPorDobleCriterio(Autores array[],int size, int orderFirst, int orderSecond);                                  //cambiar autores
int autores_listar(Autores array[], int size);                      //cambiar autores
void autores_mock(Autores arrayAutores[], int size,int *contadorId);                      //cambiar autores
void MenuAutores();
void MenuAutoresPrincipal();
void MenuAutoresModificacion();
int autores_ordenar(Autores array[],int size);

