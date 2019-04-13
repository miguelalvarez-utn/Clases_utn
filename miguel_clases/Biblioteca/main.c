#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo,int reintento, int *resultado);
int isVAlidInt(int numero, int minimo, int maximo);

int main()
{
    int numeroIngresado;
    getInt("ingrese numero", "Error", 0, 80,3, &numeroIngresado);


}

int isValidInt(int numero, int minimo, int maximo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;

}

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo,int reintento, int *resultado)
{

    int buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo>=minimo && reintento >=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer,minimo,maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
            reintento--;
        }while(reintento >= 0);
    }

    return retorno;
}
