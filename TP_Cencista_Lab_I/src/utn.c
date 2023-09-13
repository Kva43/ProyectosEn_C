/*
 * funciones.c
 *
 *  Created on: 23 abr. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int myGets(char*cadena, int longitud);
static int esFlotante(char* cadena, int limite);
static int getFloat(float* pResultado);
static int esNombre(char* cadena, int longitud);
static int getNombre(char* pResultado,int longitud);
static int getTelefono(char* pResultado,int longitud);
static int esTelefono(char* cadena, int limite);
static int getCalle(char* pResultado,int longitud);
static int esCalle(char* cadena, int longitud);

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos)
{
	int ret=-1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(getInt(&bufferInt)==0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			ret=0;
			*pResultado=bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	} while(reintentos>=0);
	return ret;
}
static int getInt(int* pResultado)
{
	int ret=-1;
	char bufferString[6400];
	if(pResultado != NULL &&
	   myGets(bufferString, sizeof(bufferString))==0 &&
	   esNumerica(bufferString, sizeof(bufferString)))
	{
		ret=0;
		*pResultado = atoi(bufferString);
	}
	return ret;
}
static int esNumerica(char* cadena, int limite)
{
	int ret=1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		ret=1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				ret=0;
				break;
			}
		}
	}
	return ret;
}

static int myGets(char*cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; //MAL

	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!= NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]== '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]= '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos)
{
	int ret=-1;
	float bufferString;
	do
	{
		printf("%s",mensaje);
		if(getFloat(&bufferString)==0 && bufferString >= minimo && bufferString <= maximo)
		{
			ret=0;
			*pResultado=bufferString;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	} while(reintentos>=0);
	return ret;
}

static int getFloat(float* pResultado)
{
	int ret=-1;
	char bufferString[64];
	if(pResultado != NULL &&
	   myGets(bufferString, sizeof(bufferString))==0 &&
	   esFlotante(bufferString, sizeof(bufferString)))
	{
		ret=0;
		*pResultado = atof(bufferString);
	}
	return ret;
}

static int esFlotante(char* cadena, int limite)
{
	int ret=1;
	int i;
	int contPuntos=0;

	if(cadena != NULL && limite > 0)
	{
		ret=1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i]>'9' || cadena[i]<'1')
			{
				if(cadena[i] == '.' && contPuntos == 0)
				{
					contPuntos++;
				}
				else
				{
					ret=0;
					break;
				}
			}
		}
	}
	return ret;
}


static int esNombre(char* cadena, int longitud)
{
	int ret=1;
	int i;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0;i<longitud && cadena[i] != '\0';i++)
		{
			if((cadena[i]>'Z' || cadena[i]<'A') && (cadena[i]>'z' || cadena[i]<'a'))
			{
				ret=0;
				break;
			}
		}
	}
	return ret;
}

static int getNombre(char* pResultado,int longitud)
{
	int ret=-1;
	char buffer[4096];
	if(pResultado != NULL && myGets(buffer, sizeof(buffer))==0 &&
	   esNombre(buffer, sizeof(buffer)) &&
	   strnlen(buffer,sizeof(buffer))<longitud)
	{
		strncpy(pResultado,buffer,longitud);
		ret=0;
	}
	return ret;
}

int utn_getNombre(char* pResultado,char* mensaje,char* mensajeError, int longitud, int reintentos)
{
	int ret=-1;
	char bufferString[4096];
	do
	{
		printf("%s",mensaje);
		if((getNombre(bufferString, sizeof(bufferString)))==0 &&
		   strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			ret=0;
			break;
		}
		reintentos--;
		printf("%s",mensajeError);
	} while(reintentos>=0);
	return ret;
}

int utn_getTelefono(char* pResultado,char* mensaje,char* mensajeError, int longitud, int reintentos)
{
	int ret=-1;
	char bufferString[4096];
	do
	{
		printf("%s",mensaje);
		if((getTelefono(bufferString, sizeof(bufferString)))==0 &&
		   strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			ret=0;
			break;
		}
		reintentos--;
		printf("%s",mensajeError);
	} while(reintentos>=0);
	return ret;
}
static int getTelefono(char* pResultado,int longitud)
{
	int ret=-1;
	char buffer[4096];
	if(pResultado != NULL && myGets(buffer, sizeof(buffer))==0 &&
	   esTelefono(buffer, sizeof(buffer)) &&
	   strnlen(buffer,sizeof(buffer))<longitud)
	{
		strncpy(pResultado,buffer,longitud);
		ret=0;
	}
	return ret;
}

static int esTelefono(char* cadena, int limite)
{
	int ret=1;
	int i;
	if(cadena != NULL && limite > 0 && limite <=10)
	{
		ret=1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(i==5 && cadena[i] == '-')
			{
				continue;
			}
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				ret=0;
				break;
			}
		}
	}
	return ret;
}

int validarFlag(int aux,int ok,int error,char*mensaje)
{
	int ret=-1;
	if(aux==ok)
	{
		ret=0;
	}
	else if(aux==error)
	{
		printf("%s",mensaje);
	}
	return ret;
}

int utn_getCalle(char* pResultado,char* mensaje,char* mensajeError, int longitud, int reintentos)
{
	int ret=-1;
	char bufferString[4096];
	do
	{
		printf("%s",mensaje);
		if((getCalle(bufferString, sizeof(bufferString)))==0 &&
		   strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			ret=0;
			break;
		}
		reintentos--;
		printf("%s",mensajeError);
	} while(reintentos>=0);
	return ret;
}

static int getCalle(char* pResultado,int longitud)
{
	int ret=-1;
	char buffer[4096];
	if(pResultado != NULL && myGets(buffer, sizeof(buffer))==0 &&
	   esCalle(buffer, sizeof(buffer)) &&
	   strnlen(buffer,sizeof(buffer))<longitud)
	{
		strncpy(pResultado,buffer,longitud);
		ret=0;
	}
	return ret;
}

static int esCalle(char* cadena, int longitud)
{
	int ret=1;
	int i;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0;i<longitud && cadena[i] != '\0';i++)
		{
			if((cadena[i]>'Z' || cadena[i]<'A') && (cadena[i]>'z' || cadena[i]<'a') && cadena[i]=='.' && cadena[i]==' ')
			{
				ret=0;
				break;
			}
		}
	}
	return ret;
}
