#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "string.h"

eCorredor* Compras_new()
{
	eCorredor* newCompra = (eCorredor*)malloc(sizeof(eCorredor));
	if(newCompra != NULL)
	{
		newCompra->id = 0;
		strcpy(newCompra->apellido," ");
		strcpy(newCompra->tipo," ");
		newCompra->promedio = 0;
		newCompra->tiempo = 0;
	}
	return newCompra;
}

eCorredor* Compras_newParametros(char* idStr,char* apellidoStr,char* tipoStr,char* promedioStr,char* tiempoStr)
{
	eCorredor* pCorredor = Compras_new();
	if(pCorredor != NULL && idStr != NULL && apellidoStr != NULL && tipoStr != NULL && promedioStr != NULL && tiempoStr!= NULL)
	{
		if( Corredor_setId(pCorredor, atoi(idStr))== -1
		   || Corredor_setApellido(pCorredor, apellidoStr)== -1
		   || Corredor_setTipo(pCorredor,tipoStr)== -1
		   || Corredor_setPromedio(pCorredor, atoi(promedioStr))== -1
		   || Corredor_setTiempo(pCorredor, atof(tiempoStr))== -1)
		{
			free(pCorredor);
			pCorredor = NULL;
		}
	}
	return pCorredor;
}

int Corredor_setId(eCorredor* this,int id)
{

	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Corredor_setApellido(eCorredor* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && strlen(apellido) > 1 && strlen(apellido) < 50)
	{
		strcpy(this->apellido,apellido);
		retorno = 0;
	}
	return retorno;
}

int Corredor_setTipo(eCorredor* this,char* tipo)
{
	int retorno = -1;
	if(this != NULL && strlen(tipo) > 1 && strlen(tipo) < 50)
	{
		strcpy(this->tipo,tipo);
		retorno = 0;
	}
	return retorno;
}

int Corredor_setPromedio(eCorredor* this,int promedio)
{
	int retorno = -1;
	if(this != NULL && promedio >= 0)
	{
		this->promedio = promedio;
		retorno = 0;
	}
	return retorno;
}

int Corredor_setTiempo(eCorredor* this,float tiempo)
{
	int retorno = -1;
	if(this != NULL && tiempo >= 0)
	{
		this->tiempo = tiempo;
		retorno = 0;
	}
	return retorno;
}

///////////////////////////////////////////////////////////////////////
int Corredor_getId(eCorredor* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Corredor_getApellido(eCorredor* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Corredor_getTipo(eCorredor* this,char* tipo)
{
	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		strcpy(tipo,this->tipo);
		retorno = 0;
	}
	return retorno;
}

int Corredor_getPromedio(eCorredor* this,int* promedio)
{
	int retorno = -1;
	if(this != NULL && promedio != NULL)
	{
		*promedio = this->promedio;
		retorno = 0;
	}
	return retorno;
}

int Corredor_getTiempo(eCorredor* this,float* tiempo)
{
	int retorno = -1;
	if(this != NULL && tiempo != NULL)
	{
		*tiempo = this->tiempo;
		retorno = 0;
	}
	return retorno;
}

int asignarTotal(void* puntero)
{
	int retorno = -1;
	if(puntero != NULL)
	{
		int promedio = ((eCorredor*)puntero)->promedio;
		float res = 1.2 * promedio;
		((eCorredor*)puntero)->tiempo = res;
		retorno = 0;
	}
	return retorno;
}
