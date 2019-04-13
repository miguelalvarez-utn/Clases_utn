#include <stdio.h>
#include <stdlib.h>

int isValidNumber(char* str);
////////////////////////////////
int getNumber(	char* msg,
				char* mssgError,
				int minimo,
				int maximo,
				int reintentos,
				int* resultado);
//////////////////////////////////////////////////////////////////////////////////////////////////
int getString(char* msg, char* mssgError, int minimo, int maximo, int reintentos,char* resultado);


int main()
{

    return 0;
}

int isValidNumber(char* str)
{
	return 1;
}

int getNumber(char* msg, char* msgError, int minimo, int maximo, int reintentos,int* resultado)
{
    int retorno = -1;
    char buffer[18];
    int bufferInt;
    if(msg != NULL)
    {
		if(getString(msg,msgError,1,16,reintentos,buffer)== 0);
		{
		    if(isValidNumber(buffer))
		    {
				*resultado = buffer;
				return 0;
		    }
			bufferInt = atoi(buffer);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{

			}
		}

    }

    return retorno;
}

int getString(char* msg, char* mssgError, int minimo, int maximo, int reintentos,char* resultado)
{
	strncpy(resultado,"1234",5);
	return 0;
}
