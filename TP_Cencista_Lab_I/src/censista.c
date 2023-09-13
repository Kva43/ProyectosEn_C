/*
 * censista.c
 *
 *  Created on: 20 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censista.h"

int censista_harcodearDatos(eCensista*aux,int len,int legajo,char*nombre,int edad, char*telefono)
{
	int ret=-1;

	(aux+len)->legajoCensista=legajo;
	strncpy((aux+len)->nombre,nombre,NOMBRE_LEN);
	(aux+len)->edad=edad;
	strncpy((aux+len)->telefono,telefono,TELEFONO_LEN);
	ret=0;

	return ret;
}

int censista_imprimirDatos(eCensista* aux,int limite)
{
	int ret=-1;

	for(int i=0;i<limite;i++)
	{
		printf("\nLegajo censista: %d",(aux+i)->legajoCensista);
		printf("\nNombre: %s",(aux+i)->nombre);
		printf("\nEdad: %d",(aux+i)->edad);
		printf("\nTelefono: %s",(aux+i)->telefono);
		printf("\n-------------------");
		ret=0;
	}
	return ret;
}

int retornarLegajoAuto(eCensista*aux,int pos)
{
	int legajo;

	legajo=(aux+pos)->legajoCensista;
	return legajo;
}


int censista_mostrarPosicionIndividual(eCensista*aux, int i)
{
	int ret=-1;

	printf("\n----DATOS CENSISTA----");
	printf("\nLegajo censista: %d",(aux+i)->legajoCensista);
	printf("\nNombre: %s",(aux+i)->nombre);
	printf("\nEdad: %d",(aux+i)->edad);
	printf("\nTelefono: %s\n",(aux+i)->telefono);
	ret=0;

	return ret;
}

//int contarCensosRealizados(eCensista*aux)
//{
//
//}


