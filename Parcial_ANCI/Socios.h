#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "SOCIOS X EL QUE QUIERAS(todo mayuscula)"
    "Socios x el que Quieras(primer letra en mayuscula)""socioss x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    char sexo;
    char telefono[TEXT_SIZE];
    char eMail[TEXT_SIZE];
    char fecha[TEXT_SIZE];

}Socios;


#endif // SOCIOS_H_INCLUDED

int socios_Inicializar(Socios array[], int size);                                    //cambiar socios
int socios_buscarEmpty(Socios array[], int size, int* posicion);                    //cambiar socios
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarInt(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarString(Socios array[], int size, char* valorBuscado, int* indice);                    //cambiar socios
int socios_alta(Socios array[], int size, int* contadorID);                          //cambiar socios
int socios_baja(Socios array[], int sizeArray);                                      //cambiar socios
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado);
int socios_modificar(Socios array[], int sizeArray);                                //cambiar socios
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond);                                  //cambiar socios
int socios_listar(Socios array[], int size);                      //cambiar socios
void socios_mock(Socios arraySocios[], int size,int *contadorId);                      //cambiar socios
void MenuSocios();
void MenuSociosPrincipal();
void MenuSociosModificacion();
int socios_ordenar(Socios array[],int size);


