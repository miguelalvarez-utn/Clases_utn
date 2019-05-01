////////////////////////////////////////////
#define CARACTER_MAX_NAME 50
#define CARACTER_MAX_DIREC 20
#define TYPE_MAX_CHARCT 4
/////////////////////////////////////////
typedef struct
{
    int idPantallas;
    int isEmpty;
    //-------------
    char nombre[CARACTER_MAX_NAME];
    char direccion[CARACTER_MAX_DIREC];
    char precio[CARACTER_MAX_DIREC];
    char tipoPantalla[TYPE_MAX_CHARCT];
}pantallas;
/////////////////////////////////////////
void MenuPantalla();
void listar(pantallas str[],int cantidadElementos);
void MenuPantallaMod();
void inicializarEspaciosA(pantallas str[],int cantidadElementos,int valorEspacio);

//----------------------------------------
int getName (   char* msg,
                char* msgError,
                char* msgError2,
                int minimo,
                int maximo,
                char resultado[]);
//-----------------------------------------
int getPricio(  char* msg,
                char* msgError,
                char* msgError2,
                int minimo,
                int maximo,
                char* resultado);
//-----------------------------------------
int getString ( int minimo,
                int maximo,
                char resultado[]);
//-----------------------------------------
int isValidName(char str[]);
//-----------------------------------------
int getOption(  char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado);
//-----------------------------------------
int getAlfaNumerico   ( char* msg,
                        char* msgError,
                        char* msgError2,
                        int minimo,
                        int maximo,
                        char resultado[]);
//-----------------------------------------
int getId(      char* msg,
                char* msgError,
                int minimo,
                int maximo,
                char* resultado);
//-----------------------------------------
int isValidOpcion(int numeroOpcion, int valorMinimo, int valorMaximo);
//-----------------------------------------
int isValidRange(int numero, int minimo, int maximo);
int isValidNumber(char str[]);
void MenuType();
int buscarEspacioLibreA(pantallas str[],int cantidadElementos,int valorEspacio);
int buscarPorId(pantallas str[],int cantidadElementos,int idCompare);
void alta(pantallas str[],int espacioLibre);

