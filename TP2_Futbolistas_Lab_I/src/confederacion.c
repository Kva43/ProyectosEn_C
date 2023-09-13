#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "validaciones.h"

void menu_escribirCabezalConf(void)
{
	printf("=================================================\n");
	printf("| ID |   NOMBRE       | REGION  | AÑOS CREACION |\n");
	printf("-------------------------------------------------\n");
}

int initArrayConf(eConfederacion* pStruct, int cant)
{
	int retorno = -1;
	if(pStruct != NULL && cant > 0)
	{
		for(int i = 0; i < cant; i++)
		{
			pStruct[i].isEmpty = 0;
		}
		retorno = 0;
	}
	return retorno;
}
int modificarIdConf(int num, char* pAEscribir)
{
	int retorno = -1;
	switch(num){
	case 100:
		strcpy(pAEscribir,"CONMEBOL");
		break;
	case 101:
		strcpy(pAEscribir,"UEFA");
		break;
	case 102:
		strcpy(pAEscribir,"AFC");
		break;
	case 103:
		strcpy(pAEscribir,"CAF");
		break;
	case 104:
		strcpy(pAEscribir,"CONCACAF");
		break;
	case 105:
		strcpy(pAEscribir,"OFC");
		break;
	}
	return retorno;
}

int listarConf(eConfederacion* arrayConf, int cant)
{
	int retorno = -1;
	if(arrayConf != NULL && cant > 0)
	{
		menu_escribirCabezalConf();
		for(int i = 0; i < cant; i++)
		{
			if(arrayConf[i].isEmpty == -1)
			{
				printf("| %-2d | %-16s | %-10s | %-10d |\n",arrayConf[i].id,
													arrayConf[i].nombre,
													arrayConf[i].region,
													arrayConf[i].aniosCreacion);
				printf("-------------------------------------------------\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}





/*Nota 4: La entidad eConfederaciones deberá contar con sus funciones de alta, baja y
modificación, pero para trabajar en el main solo usaremos los valores hardcodeados que se
ven en la *imagen02.*/

int altaConfederacion(eConfederacion* arrayConfe, int cant, int char_len)
{
	int retorno = -1;
	char mensajeError[50] = "\nHubo un error. Intentelo nuevamente: ";
	if(arrayConfe != NULL && cant > 0)
	{
		for(int i = 0; i < cant; i++)
		{

			if(arrayConfe[i].isEmpty == 0)
			{
				if(utn_getAlfanumerica(arrayConfe[i].nombre,char_len,"\nNombre: ",mensajeError,2) == 0
				&& utn_getAlfanumerica(arrayConfe[i].region,char_len,"\nRegion: ",mensajeError,2) == 0
				&& utn_getNumero(&arrayConfe[i].aniosCreacion,"\nAño creacion: ",mensajeError, 1800, 2022,2) == 0)
				{
					arrayConfe[i].id = i;
					arrayConfe[i].isEmpty = -1;
					break;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int darDeBajaConf(eConfederacion* arrayConf, int cant)
{
	int retorno = -1;
	int id;
	listarConf(arrayConf, cant);
	utn_getNumero(&id, "\nIngrese ID: ", "\n ERROR", 0, (cant - 1), 2);
	for(int i = 0; i < cant; i++)
	{
		if(arrayConf[i].id == id && arrayConf[i].isEmpty == -1)
		{
			arrayConf[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}

//parametros: recibe un INT , y devuelve un STRING  a la direccion de memoria
int modificarNuevaConf(eConfederacion* arrayConf, int cant, int char_len)
{
	int retorno = -1;
	char mensajeError[50] = "\nHubo un error. Intentelo nuevamente: ";
	listarConf(arrayConf, cant);
	int id;
	utn_getNumero(&id, "\nIngrese ID: ", "\n ERROR", 0, (cant - 1), 2);
	for(int i = 0; i < cant; i++)
	{
		if(arrayConf[i].id == id && arrayConf[i].isEmpty == -1)
		{
			if(utn_getNombre(arrayConf[i].nombre, char_len, "\nNombre: ", mensajeError, 2) == 0
					&& utn_getNombre(arrayConf[i].region, char_len, "\nRegion: ", mensajeError, 2) == 0
					&& utn_getNumero(&arrayConf[i].aniosCreacion, "\nAnio Creacion: ", mensajeError, 1900, 2022, 2) == 0)
			{
				arrayConf[i].isEmpty = -1;
				retorno = 0;
			}
			retorno = 0;
		}
	}
	return retorno;
}
