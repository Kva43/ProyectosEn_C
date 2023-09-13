#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "alquiler.h"
#include "validaciones.h"

int initArrayAlquiler(Alquiler* array, int cant)
{
	int retorno = -1;
	if(array != NULL && cant > 0)
	{
		for(int i = 0; i < cant; i++)
		{
			array[i].isEmpty = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int alquiler_pedirCliente(Alquiler* array, int pos, int cant)
{
	int retorno = -1;
	if(array != NULL && pos >= 0)
	{
		utn_getNumero(&array[pos].idCliente, "\nID: ", "\nERROR ", 0, cant, 2);
		retorno = 0;
	}
	return retorno;
}

int alquiler_pedirEquipo(Alquiler* array, int pos)
{
	int retorno = -1;
	int opcion;
	if(array != NULL && pos >= 0)
	{
		utn_getNumero(&opcion, "\n1 AMOLADORA \n2 MEZCLADORA \n3 TALADRO", "\nError", 1, 3, 2);
		switch(opcion)
		{
		case 1:
			strcpy(array[pos].equipo, "Amoladora");
			retorno = 0;
			break;
		case 2:
			strcpy(array[pos].equipo, "Mezcladora");
			retorno = 0;
			break;
		case 3:
			strcpy(array[pos].equipo, "Taladro");
			retorno = 0;
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int alquiler_pedirTiempo(Alquiler* array, int pos)
{
	int retorno = -1;
	if(array != NULL && pos >= 0)
	{
		utn_getNumero(&array[pos].tiempoEstimado, "\nTiempo estimado(en horas): ", "\nERROR ", 1, 100, 2);
		retorno = 0;
	}
	return retorno;
}

int alquiler_pedirOperador(Alquiler* array, int pos)
{
	int retorno = -1;
	if(array != NULL && pos >= 0)
	{
		utn_getAlfanumerica(array[pos].operador, 100, "\nNombre operador: ", "\nERROR ", 2);
		retorno = 0;
	}
	return retorno;
}
