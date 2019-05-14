#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"
#define QTY_ARRAY_TIPO 10
//--------------------------
int main()
{
    int opcion;
    int opcion1;
    int contadorIdfantasma=0;
    Fantasma arrayFantasma[QTY_ARRAY_TIPO];
    fantasma_Inicializar(arrayFantasma,QTY_ARRAY_TIPO);
    fantasma_mock(arrayFantasma, QTY_ARRAY_TIPO, &contadorIdfantasma) ;

    do
    {
        MenuFantasmaPrincipal();
           utn_getUnsignedInt("","\nError",1,sizeof(int),1,6,1,&opcion);
        switch(opcion)
        {
            //------------------------------------------------------------------------
            case 1:
                do
                {
                    MenuFantasma();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion1);
                    switch(opcion1)
                    {
                        case 1:
                            fantasma_alta(arrayFantasma,QTY_ARRAY_TIPO,&contadorIdfantasma);
                            break;
                        case 2:
                            fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);
                            fantasma_baja(arrayFantasma,QTY_ARRAY_TIPO);
                            break;
                        case 3:
                            fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);
                            fantasma_modificar(arrayFantasma,QTY_ARRAY_TIPO);
                            break;
                        case 4:
                            fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);
                            break;
                        case 5:

                            fantasma_ordenar(arrayFantasma,QTY_ARRAY_TIPO);
                            fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);
                            break;
                    }
                }while(opcion1 != 6);
                break;
            //----------------------------------------------------------------------------
            //----------------------------------------------------------------------------
            //----------------------------------------------------------------------------
        }
    }while(opcion != 6);
    return 0;
}
