#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_CARACTERES 10

int main()
{
/*
    char nombre[7] = {'H','O','L','A','\0'};
    char nombre2[7] = {"HOLA"};
    // Este ejeplo no es valida, nombre = "Juan";
    strncpy(nombre,nombre2,sizeof(nombre));//destino origen tamaño, nunca me tengo que pasar del tamaño del destino.
    sizeof(nombre);//me dice que tamaño tiene reservado el array.
    printf("\n%s",nombre);
    fgets(nombre,sizeof(nombre),stdin);//lee un string desde un archivo.
    strlen();//verifica la cantidad de caracteres.
    strcmp();//me dice si que string es mas grande
    printf("\n%s",nombre);
    return 0;
    */
    char nombre[CANTIDAD_CARACTERES];
    char buffer[CANTIDAD_CARACTERES];
    int i;
    int flag;

    printf("Ingrese un nombre\n");
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1];

    for(i = 0; i < CANTIDAD_CARACTERES ; i++)
    {

        if(!(buffer[i] >= 'a' && buffer[i] <= 'z'))
        {
            printf("Error\n");
            break;
        }
        printf("%d\n",i);
    }
    /*
    strncpy(buffer,nombre,sizeof(buffer));
    printf("\n%s",nombre);
     */
    return 0;
}

int isValidName(char* validoNombre, int limite)
{

}















