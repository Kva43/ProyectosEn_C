#include <stdio.h>
#include <stdlib.h>
#include "promedios.h"

int prom_setPromAFC(Promedio* this, float valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->promAFC = valor;
	}
	return retorno;
}

int prom_getPromAFC(Promedio* this,float* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->promAFC;
	}
	return retorno;
}

int prom_setPromCAF(Promedio* this, float valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->promCAF = valor;
	}
	return retorno;
}

int prom_getPromCAF(Promedio* this,float* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->promCAF;
	}
	return retorno;
}

int prom_setPromCONMEBOL(Promedio* this, float valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->promCONMEBOL = valor;
	}
	return retorno;
}

int prom_getPromCONMEBOL(Promedio* this,float* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->promCONMEBOL;
	}
	return retorno;
}

int prom_setPromUEFA(Promedio* this, float valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->promUEFA = valor;
	}
	return retorno;
}

int prom_getPromUEFA(Promedio* this,float* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->promUEFA;
	}
	return retorno;
}

int prom_setPromOFC(Promedio* this, float valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->promOFC = valor;
	}
	return retorno;
}

int prom_getPromOFC(Promedio* this,float* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->promOFC;
	}
	return retorno;
}

int prom_setPromCONCACAF(Promedio* this, float valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->promCONCACAF = valor;
	}
	return retorno;
}

int prom_getPromCONCACAF(Promedio* this,float* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->promCONCACAF;
	}
	return retorno;
}
