#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "jugadores.h"
#include "posiciones.h"
#include "confederaciones.h"

int jug_setCamiseta(Jugadores* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->camiseta = valor;
	}
	return retorno;
}

int jug_getCamiseta(Jugadores* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->camiseta;
	}
	return retorno;
}

int peli_setGenero(Jugadores* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->posicion = valor;
	}
	return retorno;
}

int peli_getGenero(Jugadores* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->posicion;
	}
	return retorno;
}

int jug_setConfederacion(Jugadores* this, int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->confederacion = valor;
	}
	return retorno;
}

int jug_getConfederacion(Jugadores* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->confederacion;
	}
	return retorno;
}

int ingresarJug(Jugadores* pJug, void* pPosicion, void* pConfederacion)
{
	int retorno = -1;
	int auxCamiseta, auxPosicion, auxConfederacion;
	char mensajeError[20] = "\nERROR";
	char mensajeConfederacion[200] = "\nConfederacion\n1. AFC (Asia)\n2. CAF (África)\n3. CONCACAF (Norte America)\n4. CONMEBOL (Sudamérica)\n5. UEFA (Europa)\n6. OFC (Oceanía)\n";

	if(pJug != NULL)
	{
		if( utn_getNumero(&auxCamiseta, "\nN° de camiseta: ", mensajeError, 0, 99, 2) == 0 &&
			utn_getNumero(&auxPosicion, "\nPosicion\n1. Arquero\n2. Defensor\n3. Mediocampista\n4. Delantero", mensajeError, 1, 4, 2) == 0 &&
			utn_getNumero(&auxConfederacion, mensajeConfederacion, mensajeError, 1, 6, 2) == 0)
		{
			switch(auxPosicion)
			{
			case 1:
				pos_setArquero((Posiciones*)pPosicion, 1);
				break;
			case 2:
				pos_setDefensor((Posiciones*)pPosicion, 1);
				break;
			case 3:
				pos_setMediocampista((Posiciones*)pPosicion, 1);
				break;
			case 4:
				pos_setDelantero((Posiciones*)pPosicion, 1);
				break;
			}
			switch(auxConfederacion)
			{
			case 1:
				conf_setAFC((Confederacion*)pConfederacion, 1);
				break;
			case 2:
				conf_setCAF((Confederacion*)pConfederacion, 1);
				break;
			case 3:
				conf_setCONCACAF((Confederacion*)pConfederacion, 1);
				break;
			case 4:
				conf_setCONMEBOL((Confederacion*)pConfederacion, 1);
				break;
			case 5:
				conf_setUEFA((Confederacion*)pConfederacion, 1);
				break;
			case 6:
				conf_setOFC((Confederacion*)pConfederacion, 1);
				break;
			}
		}
	}
	return retorno;
}
