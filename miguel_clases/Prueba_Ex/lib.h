typedef struct
{
   int id;
   int isEmpty;
   char nombre[51];
   char apellido[51];
}eTypedef;


void Alta(eTypedef str[],int cantidadElementos);
void inicializarEspaciosB(eTypedef str[],int cantidadElementos,int valorEspacio);
int buscarEspacioLibreB(eTypedef str[],int cantidadElementos,int valorEspacio);
void baja(eTypedef str[],int cantidadElementos);
void modificacion(eTypedef str[],int cantidadElementos);
void ordenamiento(eTypedef str[],int cantidadElementos);

