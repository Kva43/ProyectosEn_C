#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "cliente.h"
#include "string.h"

int initArrayClientes(Cliente* array, int cant)
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

//int modificarIdCliente(int num, char* pAEscribir)
//{
//	int retorno = -1;
//	switch(num){
//	case 0:
//		strcpy(pAEscribir,"Carlos");
//		break;
//	case 1:
//		strcpy(pAEscribir,"Roberto");
//		break;
//	case 2:
//		strcpy(pAEscribir,"Luis");
//		break;
//	case 3:
//		strcpy(pAEscribir,"Miguel");
//		break;
//	case 4:
//		strcpy(pAEscribir,"Marcos");
//		break;
//	}
//	return retorno;
//}

int cliente_pedirNombre(Cliente* array,int pos)
{
	int retorno = -1;
	if(array != NULL && pos >= 0)
	{
		utn_getAlfanumerica(array[pos].nombre, MAX_CHAR, "\nNombre: ", "\nERROR ", 2);
		retorno = 0;
	}
	return retorno;
}

int cliente_pedirApellido(Cliente* array, int pos)
{
	int retorno = -1;
	if(array != NULL && pos >= 0)
	{
		utn_getAlfanumerica(array[pos].apellido, MAX_CHAR, "\nApellido: ", "\nERROR ", 2);
		retorno = 0;
	}
	return retorno;
}

int cliente_pedirDNI(Cliente* array, int pos)
{
	int retorno = -1;
	if(array != NULL && pos >= 0)
	{
		utn_getNumero(&array[pos].dni, "\nDNI: ", "\nERROR ", 20000000, 50000000, 2);
		retorno = 0;
	}
	return retorno;
}
