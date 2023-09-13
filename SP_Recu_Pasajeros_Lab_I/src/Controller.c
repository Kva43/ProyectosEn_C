#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "menus.h"
#define LEN_CHAR 50

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
	int retorno = -1;
	FILE* pFile = NULL;
	if(path != NULL && pArrayList != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL && parser_PassengerFromText(pFile, pArrayList) == 0)
		{
			printf("Se cargó correctamente\n");
			retorno = 0;
		}
		else
		{
			printf("No se pudo abrir\n");
		}
	}
	fclose(pFile);
	return retorno;
}

int controller_List(LinkedList* pArrayList)
{
	int retorno = -1;
	eCorredor* pAux = NULL;
	int tam;

	if(pArrayList != NULL)
	{
		tam =  ll_len(pArrayList);
		menu_escribirCabezal();
		for(int i = 0; i < tam; i++)
		{
			pAux = ll_get(pArrayList, i);
			controller_imprimir(pAux);
		}
		retorno = 0;
	}
	else
	{
		printf("Esta vacia\n");
	}
	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int retorno = -1;
	FILE* pFile;
	eCorredor* aux;
	char apellido[50],tipo[50];
	int promedio,id;
	float tiempo;

	if (path != NULL && pArrayList != NULL )
	{
		pFile = fopen(path, "w");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}

		fprintf(pFile, "id_corredor,apellido,tipo,promedio,tiempo\n");

		for (int i = 0; i < ll_len(pArrayList); i++)
		{
			aux = ll_get(pArrayList, i);

			 if(Corredor_getId(aux,&id) == 0
				&&
				Corredor_getApellido(aux, apellido) == 0
				&&
				Corredor_getTiempo(aux, &tiempo) == 0
				&&
				Corredor_getPromedio(aux, &promedio) == 0
				&&
				Corredor_getTipo(aux, tipo) == 0)
			{
				fprintf(pFile, "%d,%s,%s,%d,%.2f\n",id,apellido,tipo,promedio,tiempo);
				retorno = 0;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

int controller_imprimir(eCorredor* pStruct)
{
	int retorno = -1;
    int promedio,id;
    float tiempo;
    char apellido[50],tipo[50];

    if(pStruct != NULL &&
		Corredor_getId(pStruct,&id)== 0 &&
		Corredor_getApellido(pStruct, apellido)== 0 &&
		Corredor_getTiempo(pStruct, &tiempo)== 0 &&
		Corredor_getPromedio(pStruct, &promedio)== 0 &&
		Corredor_getTipo(pStruct, tipo)== 0)
    {
        printf(" %d  %-15s    %-10s      %d  	 %.2f\n",id,apellido,tipo,promedio,tiempo);
        retorno = 0;
    }
    return retorno;
}

LinkedList* controller_map(LinkedList* pArrayList)
{
	LinkedList* mapList;
	mapList = ll_map(pArrayList,asignarTotal);
	return mapList;
}


