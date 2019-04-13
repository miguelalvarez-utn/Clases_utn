#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 4

int main()
{
    int orden[4];
    int i;
    int respuesta;
    int auxiliar;
    int flagSwap;
    for(i = 0; i < CANTIDAD_NUMEROS; i++)
    {
        printf("dame 4 numeros");
        scanf("%d",&orden[i]);
    }
    printf("tu numeros son %d %d %d %d",orden[0],orden[1],orden[2],orden[3]);

    printf("quiere ordenarlos?");
    scanf("%d",&respuesta);
    if(respuesta == 1)
    {
        do
        {
            for(i = 0; i < CANTIDAD_NUMEROS; i++)
            {
                flagSwap = 0;
                if(orden[i] > orden[i+1])
                {
                    auxiliar = orden[i];
                    orden[i] = orden[i+1];
                    orden[i+1] = auxiliar;
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    printf("tu numeros son %d %d %d %d",orden[0],orden[1],orden[2],orden[3]);
}

