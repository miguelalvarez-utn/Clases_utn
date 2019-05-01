//////////////////////////////////////
#define CUIT_MAX_CHAR 14
#define ARCHIVO_MAX_CHAR 128
#define DIAS_MAX_CHAR 5

typedef struct
{
    int idPublicidad;
    int isEmpty;
    //-------------
    char cuit[CUIT_MAX_CHAR];
    char archivo[ARCHIVO_MAX_CHAR];
    char diasContratacion[DIAS_MAX_CHAR];
    int idPantalla;
}publicidad;
////////////////////////////////////////
typedef struct
{
    int idPublicidad;
    int idPantallas;
}Publicidad_Pantalla;
/////////////////////////////////////////
int isValidCuitB(char str[]);
//---------------------------------------
int isValidCuitA(char str[]);
//---------------------------------------
int getCuit(    char* msg,
                char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado);
//---------------------------------------
int getDias(  char* msg,
                char* msgError,
                char* msgError2,
                int minimo,
                int maximo,
                char* resultado);
//--------------------------------------
int getArchivo(char* msg,
                char* msgError,
                char* msgError2,
                int minimo,
                int maximo,
                char resultado[]);
//--------------------------------------
int isArchivo(char str[]);
//--------------------------------------
void listarPublicidad(publicidad str[],int cantidadElementos);
//--------------------------------------
void MenuPublicidadMod();
int listarPorCuil(publicidad str[],
                  pantallas str2[],
                  int cantidadElementos,
                  int idCompare[]);
//---------------------------------------
int buscarPorCuit(publicidad str[],
                  pantallas str2[],
                  int cantidadElementos,
                  char cuitCompare[],
                  char* msg,
                  char* msg2);
//---------------------------------------
int buscarPorCuitFacturacion(publicidad str[],
                                pantallas str2[],
                                int cantidadElementos,
                                char cuitCompare[],
                                char* msg,
                                char* msg2);
/////////////////////////////////////////
void imprimirGeneral(publicidad str[],pantallas str2[],int cantidadElementos);
void inicializarEspaciosB(publicidad str[],int cantidadElementos,int valorEspacio);
int buscarEspacioLibreB(publicidad str[],int cantidadElementos,int valorEspacio);
