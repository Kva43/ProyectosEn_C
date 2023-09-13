#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "validaciones.h"

#define NOMBRE_LEN 100
#define POSICION_LEN 30
#define NACIONALIDAD_LEN 30

Jugador* jug_new()
{
	Jugador* auxiliarP = NULL;
	auxiliarP = (Jugador*) malloc(sizeof(Jugador));
	return auxiliarP;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr,char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* this = NULL;
	this = jug_new();
	if(this != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL)
	{
		if(esNumerica(idStr,100) && esNumerica(edadStr,100) && esNumerica(idSeleccionStr,100))
		{
			if(	peli_setId(this, atoi(idStr)) == -1 ||
				peli_setTitulo(this,nombreCompletoStr) == -1 ||
				peli_setGenero(this,posicionStr) == -1 ||
				peli_setDuracion(this, atoi(edadStr)) == -1 ||
				jug_setNacionalidad(this, nacionalidadStr) == -1 ||
				jug_setIdSeleccion(this, atoi(idSeleccionStr)) == -1)
			{
				peli_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}

void peli_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int peli_setId(Jugador* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int peli_getId(Jugador* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int peli_setTitulo(Jugador* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(esAlfanumerica(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombreCompleto,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int peli_getTitulo(Jugador* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombreCompleto,NOMBRE_LEN);
	}
	return retorno;
}

int peli_setGenero(Jugador* this,char* posicion)
{
	int retorno = -1;
	if(this != NULL && posicion != NULL)
	{
		if(esAlfanumerica(posicion,POSICION_LEN))
		{
			retorno = 0;
			strncpy(this->posicion,posicion,POSICION_LEN);
		}
	}
	return retorno;
}

int peli_getGenero(Jugador* this,char* posicion)
{
	int retorno = -1;
	if(this != NULL && posicion != NULL)
	{
		retorno = 0;
		strncpy(posicion,this->posicion,POSICION_LEN);
	}
	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL)
	{
		if(esAlfanumerica(nacionalidad, NACIONALIDAD_LEN))
		{
			retorno = 0;
			strncpy(this->nacionalidad, nacionalidad, NACIONALIDAD_LEN);
		}
	}
	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL)
	{
		retorno = 0;
		strncpy(nacionalidad,this->nacionalidad,NACIONALIDAD_LEN);
	}
	return retorno;
}

int peli_setDuracion(Jugador* this,int edad)
{
	int retorno = -1;
	if(this != NULL && edad >= 16)
	{
		retorno = 0;
		this->edad = edad;
	}
	return retorno;
}

int peli_getDuracion(Jugador* this,int* edad)
{
	int retorno = -1;
	if(this != NULL && edad != NULL)
	{
		retorno = 0;
		*edad = this->edad;
	}
	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;
	if(this != NULL && idSeleccion >= 0)
	{
		retorno = 0;
		this->idSeleccion = idSeleccion;
	}
	return retorno;
}

int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;
	if(this != NULL && idSeleccion != NULL)
	{
		retorno = 0;
		*idSeleccion = this->idSeleccion;
	}
	return retorno;
}

void menu_escribirCabezal(void)
{
	printf("================================================================================================\n");
	printf("| ID |   NOMBRE               | EDAD   |      POSICION       |   NACIONALIDAD   |  SELECCION   |\n");
	printf("------------------------------------------------------------------------------------------------\n");
}

Jugador* searchID(LinkedList* pArrayListJugador,int id)
{
	Jugador* pJugador = NULL;
	Jugador* retorno = NULL;
	int auxId;

	for(int i = 0 ; i < ll_len(pArrayListJugador); i++)
	{
		pJugador  = (Jugador*) ll_get(pArrayListJugador, i);
		peli_getId(pJugador ,&auxId);
		if(pJugador  != NULL && auxId == id)
		{
			retorno = pJugador;
			break;
		}
	}
	return retorno;
}
