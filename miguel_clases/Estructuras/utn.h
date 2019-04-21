#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
///*PROTOTIPOS O FIRMAS DE FUNCIONES\\\*
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
int getDni    ( char* msg,
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
int isValidDni(char str[]);
//--------------------------------------
void Menu();
//--------------------------------------
void MenuModificacion();
//--------------------------------------
typedef struct
{
    char nombre[20];
    char apellido[20];
    char dni[9];
    int edad;
    int legajo;
    int nacionalidad;
}ePersonas;
//---------------------------------------
typedef struct
{
    char nombre[20];
    char apellido[20];
    char dni[9];
    int edad;
    int legajo;
    int nacionalidad;
}aux;




