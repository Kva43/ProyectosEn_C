#include <stdio.h>
#include <stdlib.h>
//#include "utn.h"
#include "confederaciones.h"
//#include "posiciones.h"

int conf_initConfederacion(Confederacion* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		this->afc = 0;
		this->caf = 0;
		this->concacaf = 0;
		this->conmebol = 0;
		this->uefa = 0;
		this->ofc = 0;
	}
	return retorno;
}

int conf_setAFC(Confederacion* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->afc += valor;
	}
	return retorno;
}

int conf_getAFC(Confederacion* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->afc;
	}
	return retorno;
}

int conf_setCAF(Confederacion* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->caf += valor;
	}
	return retorno;
}

int conf_getCAF(Confederacion* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->caf;
	}
	return retorno;
}

int conf_setCONCACAF(Confederacion* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->concacaf += valor;
	}
	return retorno;
}

int conf_getCONCACAF(Confederacion* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->concacaf;
	}
	return retorno;
}

int conf_setCONMEBOL(Confederacion* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->conmebol += valor;
	}
	return retorno;
}

int conf_getCONMEBOL(Confederacion* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->conmebol;
	}
	return retorno;
}

int conf_setUEFA(Confederacion* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->uefa = +valor;
	}
	return retorno;
}

int conf_getUEFA(Confederacion* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->uefa;
	}
	return retorno;
}

int conf_setOFC(Confederacion* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->ofc = +valor;
	}
	return retorno;
}

int conf_getOFC(Confederacion* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->ofc;
	}
	return retorno;
}
