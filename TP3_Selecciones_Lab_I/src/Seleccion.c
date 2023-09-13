#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "validaciones.h"
#include "Seleccion.h"

Seleccion* selec_new()
{
	Seleccion* auxiliarP = NULL;
	auxiliarP = (Seleccion*) malloc(sizeof(Seleccion));
	return auxiliarP;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* this = NULL;
	this = selec_new();
	if(this != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
		if(esNumerica(idStr,100) && esNumerica(convocadosStr,100))
		{
			this->id = atoi(idStr);
			strcpy(this->pais, paisStr);
			strcpy(this->confederacion, confederacionStr);
			this->convocados = atoi(convocadosStr);
		}
		else
		{
			selec_delete(this);
			this = NULL;
		}
	}
	return this;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;
	if(this != NULL && pais != NULL)
	{
		retorno = 0;
		strncpy(pais,this->pais,30);
	}
	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;
	if(this != NULL && confederacion != NULL)
	{
		retorno = 0;
		strncpy(confederacion,this->confederacion,30);
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;
	if(this != NULL)
	{
		if(convocados == 1)
		{
			retorno = 0;
			this->convocados += 1;
		}
		else if(convocados == 0)
		{
			retorno = 0;
			this->convocados -= 1;
		}
	}
	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;
	if(this != NULL && convocados != NULL)
	{
		retorno = 0;
		*convocados = this->convocados;
	}
	return retorno;
}

void menu_escribirCabezalSeleccion()
{
	printf("===================================================================\n");
	printf("| ID |      PAIS             |   CONFEDERACION    |   CONVOCADOS  |\n");
	printf("-------------------------------------------------------------------\n");

}

Seleccion* searchIDSeleccion(LinkedList* pArrayListSeleccion,int id)
{
	Seleccion* pSeleccion = NULL;
	Seleccion* retorno = NULL;
	int auxId;

	for(int i = 0 ; i < ll_len(pArrayListSeleccion); i++)
	{
		pSeleccion  = (Seleccion*) ll_get(pArrayListSeleccion, i);
		selec_getId(pSeleccion ,&auxId);
		if(pSeleccion  != NULL && auxId == id)
		{
			retorno = pSeleccion;
			break;
		}
	}
	return retorno;
}
