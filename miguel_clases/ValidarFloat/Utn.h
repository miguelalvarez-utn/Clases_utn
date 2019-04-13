#include <stdio.h>
#include <stdlib.h>

int getFloat(char *mensaje, char *mensajeError, float maximo,
        float minimo, int reintentos, float *resultado);

int isValidFloat(float numero,float maximo, float minimo);
