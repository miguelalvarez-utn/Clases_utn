typedef struct
{
    int idLibro;
    int isEmpty;
    char titulo[51];
    int idAutor;
}t_libros;

void MenuLibros();
int lib_initArray(t_libros lista[],int len);
int lib_buscarLibre(t_libros lista[], int len);
int lib_alta(t_libros lista[],int len,int pos);
