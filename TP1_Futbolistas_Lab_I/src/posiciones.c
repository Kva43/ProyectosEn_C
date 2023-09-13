#include <stdio.h>
#include <stdlib.h>
#include "posiciones.h"
#include "utn.h"

void inicializarPosiciones(Posiciones* posiciones)
{
	posiciones->arquero = 0;
	posiciones->defensor = 0;
	posiciones->mediocampista = 0;
	posiciones->delantero = 0;
}

int pos_setArquero(Posiciones* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->arquero += valor;
	}
	return retorno;
}

int pos_getArquero(Posiciones* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->arquero;
	}
	return retorno;
}

int pos_setDefensor(Posiciones* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->defensor += valor;
	}
	return retorno;
}

int pos_getDefensor(Posiciones* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->defensor;
	}
	return retorno;
}


int pos_setMediocampista(Posiciones* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->mediocampista += valor;
	}
	return retorno;
}

int pos_getMediocampista(Posiciones* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->mediocampista;
	}
	return retorno;
}

int pos_setDelantero(Posiciones* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->delantero += valor;
	}
	return retorno;
}

int pos_getDelantero(Posiciones* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->delantero;
	}
	return retorno;
}
