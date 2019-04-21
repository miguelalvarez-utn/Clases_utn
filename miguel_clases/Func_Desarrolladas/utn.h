#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char resultado[]);
//-------------------------------------
int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char resultado[]);
//--------------------------------------
int getNumber ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//--------------------------------------
int getEdad(    char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//--------------------------------------
int getOption(  char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//--------------------------------------
int getLegajo(  char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//--------------------------------------
int isValidName(char str[]);
//--------------------------------------
int isValidNumber(char str[]);
//--------------------------------------
int isValidRange(int numero, int minimo, int maximo);
//--------------------------------------
int ordenArray(char str[],int limite);
//--------------------------------------
void inicializarArrayInt(int str[],int cantidadElementos,int valor);
//--------------------------------------
int buscarPrimerOcurrencia(int str[],int cantidadElementos,int valor);
//--------------------------------------




