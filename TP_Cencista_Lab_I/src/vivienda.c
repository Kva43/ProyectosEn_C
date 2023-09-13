/*
 * vivienda.c
 *
 *  Created on: 20 may. 2022
 *      Author: USUARIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vivienda.h"
#include "utn.h"
#include "censista.h"

/**
 *
 * @param aux
 * @param i
 * @return
 */
static int vivienda_mostrarPosicionIndividual(eVivienda*aux, int i);


int vivienda_inicializarArray(eVivienda*aux,int limite)
{
	int ret=-1;

	if(aux!=NULL && limite>0)
	{
		for(int i=0;i<limite;i++)
		{
			(aux+i)->isEmpty=0;
			ret=0;
		}
	}
	return ret;
}

int vivienda_buscarPosicionVacia(eVivienda*aux,int limite)
{
	int posicion=-1;

	if(aux!=NULL && limite>0)
	{
		for(int i=0;i<limite;i++)
		{
			if((aux+i)->isEmpty==0)
			{
				posicion=i;
				break;
			}
		}
	}
	return posicion;
}
int vivienda_pedirCargarDatos(eVivienda*aux,int id,int posicion,int valor)
{
	int ret=-1;
	printf("\n--------VIVIENDA %d-----\n",posicion+1);
	if(utn_getCalle((aux+posicion)->calle, "Calle: ", "\nError", CALLE_LEN, 2)==0
	&& utn_getNumero(&(aux+posicion)->cantidadPersonas, "Cantidad de personas: ", "\nError", 1,3000, 2)==0
	&& utn_getNumero(&(aux+posicion)->cantidadHabitaciones, "Cantidad de habitaciones: ", "\nError", 1, 3000, 2)==0
	&& utn_getNumero(&(aux+posicion)->tipoVivienda, "Tipo de vivienda(1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ", "\nError", 1, 4, 2)==0)
	{
		(aux+posicion)->idVivienda= id;
		(aux+posicion)->isEmpty=-1;
		(aux+posicion)->legajoCensista = valor;
		ret=0;
	}
	return ret;
}



int vivienda_imprimirTodos(eVivienda*aux,int limite)
{
	int ret=-1;
	if(aux!=NULL && limite>0)
	{
		for(int i=0;i<limite;i++)
		{
			if((aux+i)->isEmpty==-1)
			{
				printf("\nId vivienda: %d",(aux+i)->idVivienda);
				printf("\nCalle: %s",(aux+i)->calle);
				printf("\nCantidad de personas: %d",(aux+i)->cantidadPersonas);
				printf("\nCantidad de habitantes: %d",(aux+i)->cantidadHabitaciones);
				printf("\nTipo de vivienda(1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): %d",(aux+i)->tipoVivienda);
				printf("\nLegajo censista: %d",(aux+i)->legajoCensista);
				printf("\n-------------------");
				ret=0;
			}
		}
	}
	return ret;
}

int vivienda_harcodearDatos(eVivienda*aux,int indice,int id,char*calle,int cantidadPersonas, int cantidadHabitaciones,int tipoVivienda,eCensista*auxDos)
{
	int ret=-1;

	(aux+indice)->idVivienda=id;
	strncpy((aux+indice)->calle,calle,CALLE_LEN);
	(aux+indice)->cantidadPersonas=cantidadPersonas;
	(aux+indice)->cantidadHabitaciones = cantidadHabitaciones;
	(aux+indice)->tipoVivienda = tipoVivienda;
	(aux+indice)->isEmpty = -1;
	(aux+indice)->legajoCensista = (auxDos+indice)->legajoCensista;
	ret=0;
	return ret;
}

int vivienda_modificarPorId(eVivienda*aux, int limite,int id)
{
	int ret=-1;
	int auxOpcion;
	if(aux!=NULL && limite>=0)
	{
		for(int i=0;i<limite;i++)
		{
			if((aux+i)->idVivienda == id && (aux+i)->isEmpty==-1)
			{
				vivienda_mostrarPosicionIndividual(aux, i);
				if(utn_getNumero(&auxOpcion,"\nQue desea modificar: \n'1' (calle)\n'2' (cantidad personas)\n'3' (cantidad habitaciones)\n'4' (Tipo de vivienda)", "Error", 1, 4, 3)==0)
				{
				switch(auxOpcion)
					{
					case 1:
						if(utn_getCalle((aux+i)->calle, "\nCalle: ", "\nError", CALLE_LEN, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					case 2:
						if(utn_getNumero(&(aux+i)->cantidadPersonas, "\nCantidad de personas: ", "\nError", 1, 3000, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					case 3:
						if(utn_getNumero(&(aux+i)->cantidadHabitaciones, "\nCantidad de habitaciones: ", "\nError", 1, 3000, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					case 4:
						if(utn_getNumero(&(aux+i)->tipoVivienda, "\nTipo de vivienda: ", "\nError", 1, 4, 3)==0)
						{
							ret=0;
							break;
						}
						break;
					}
				}
				break;
			}
		}
	}

	return ret;
}

static int vivienda_mostrarPosicionIndividual(eVivienda*aux, int i)
{
	int ret=-1;

	printf("\n----DATOS DE LA VIVIENDA----");
	printf("\nCalle: %s",(aux+i)->calle);
	printf("\nCantidad de Personas: %d",(aux+i)->cantidadPersonas);
	printf("\nCantidad de Habitaciones: %d",(aux+i)->cantidadHabitaciones);
	printf("\nTipo de vivienda: %d",(aux+i)->tipoVivienda);
	printf("\n-------------------");
	ret=0;

	return ret;
}

int vivienda_darDeBaja(eVivienda*aux, int limite, int id)
{
	int ret=-1;
	char res;
	if(aux!=NULL && limite>0 && id)
	{
		for(int i=0;i<limite;i++)
		{
			if((aux+i)->idVivienda == id && (aux+i)->isEmpty==-1)
			{
				vivienda_mostrarPosicionIndividual(aux, i);
				printf("\nEliminar vivienda? s/n");
				scanf("%c",&res);
				if(res=='s')
				{
					(aux+i)->isEmpty=0;
					ret=0;
					break;
				}
				else
				{
					break;
				}
			}
		}
	}
	return ret;
}

int vivienda_ordenar(eVivienda*aux, int limite,int longitud)
{
	int ret=-1;
	int flagSwap;
	eVivienda buffer;

	if(aux!=NULL && limite>=0)
	{
		ret=1;
		do
		{
			flagSwap=0;
			for(int i=0;i<limite-1;i++)
			{
				if((aux+i)->isEmpty==0 || (aux+i+1)->isEmpty==0)
				{
					continue;
				}
				if((strncmp((aux+i)->calle,(aux+i+1)->calle, longitud)>0)
				|| ((strncmp((aux+i)->calle,(aux+i+1)->calle, longitud)==0) && (aux+i)->cantidadPersonas > (aux+i+1)->cantidadPersonas))
				{
					flagSwap=1;
					buffer=*(aux+i);
					*(aux+i)=*(aux+i+1);
					*(aux+i+1)=buffer;
					ret=0;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return ret;
}



int vivienda_contarPosicionesLlenas(eVivienda*aux,int limite)
{
	int cont=0;
	for(int i=0;i<limite;i++)
	{
		if((aux+i)->isEmpty==-1)
		{
			cont++;
		}
	}
	return cont;
}

int vivienda_imprimirPorLegajo(eVivienda*aux,int limite,int legajo)
{
	int ret=-1;
	if(aux!=NULL && limite>0)
	{
		for(int i=0;i<limite;i++)
		{
			if((aux+i)->isEmpty==-1 && (aux+i)->legajoCensista==legajo)
			{
				printf("\nId vivienda: %d",(aux+i)->idVivienda);
				printf("\nCalle: %s",(aux+i)->calle);
				printf("\nCantidad de personas: %d",(aux+i)->cantidadPersonas);
				printf("\nCantidad de habitantes: %d",(aux+i)->cantidadHabitaciones);
				printf("\nTipo de vivienda(1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): %d",(aux+i)->tipoVivienda);
				printf("\n-------------------");
				ret=0;
			}
		}
	}
	return ret;
}
