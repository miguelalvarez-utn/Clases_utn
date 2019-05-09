typedef struct
{
    int idAutor;
    int isEmpty;
    char nombre[51];
    char apellido[51];
}t_autores;
//--------------------
int aut_initArray(t_autores Lista[],int len);
int aut_buscarLibre(t_autores lista[], int len);
int aut_alta(t_autores lista[],int len,int pos);
int aut_imprimirLista(t_autores lista[],int len);
void MenuPrincipal();
void MenuAutores();
int aut_baja(t_autores lista[],int len, int id);
int aut_modificar(t_autores lista[],int len, int id);
void menuMod();
int modidificaciones(t_autores lista[], int pos);
