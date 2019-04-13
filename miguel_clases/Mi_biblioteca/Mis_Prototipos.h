#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
int getInt(char *mensaje, char *mensajeError, int maximo,int minimo, int reintentos, int *resultado);
int isValidInt(int numero,int numeroMaximo, int numeroMinimo);
////////////////////////////////////////////////////////////////////////////////////////////////////
int getFloat(char *mensaje, char *mensajeError, float maximo,float minimo, int reintentos, float *resultado);
int isValidFloat(float numero,float numeroMaximo, float numeroMinimo);
////////////////////////////////////////////////////////////////////////////////////////////////////
int getArrayInt(char* mensaje, char* mensajeError, int maximo, int minimo,int reintentos, int* edadesArray, int limite);
////////////////////////////////////////////////////////////////////////////////////////////////////
int ordenArray(int* vector[], int limite);
//////////////////////////////////////////////
char getChar(char* mensaje, char* mensajeError,char* resultado);
///////////////////////////////////////////////
int esNumerico(char str[]);
