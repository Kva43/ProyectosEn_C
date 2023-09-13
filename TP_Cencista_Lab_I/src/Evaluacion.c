/*
 ============================================================================
 Name        : Evaluacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censista.h"
#include "utn.h"
#include "vivienda.h"

int main(void) {
	setbuf(stdout,NULL);
	eCensista censista[CANT_CENSISTAS];
	eVivienda vivienda[CANT_VIVIENDAS];
	int opciones;
	char seguir='s';
	int idAModicar;
	int posicion;
	int cant;
	int flag=0;
	int id=20000;
	int i=0;
	int valor;
	int idADarBaja;
	int legajo=0;

	if(censista_harcodearDatos(censista,0,100, "Ana", 34, "1203-2345")==0
	&& censista_harcodearDatos(censista,1,101, "Juan", 24, "4301-54678")==0
	&& censista_harcodearDatos(censista,2,102, "Sol", 47, "5902-37487")==0
	&& vivienda_inicializarArray(vivienda,CANT_VIVIENDAS)==0)
	{
		printf("\nSe inicializo los isEmpty en 0 y se harcodeo los datos de los censistas\n");
	}

	do
	{
		if(utn_getNumero(&opciones,"\n1. ALTA VIVIENDA\n2. MODIFICAR VIVIENDA\n3. BAJA VIVIENDA\n4. LISTAR VIVIENDAS\n5. LISTAR CENSISTAS\n6. LISTADO DATOS CENSISTA CON DATOS VIVIENDAS CENSADAS\n7. CENSISTA CON MAS CENSOS", "\nIngrese un numero del 1 al 6\n", 1, 6, 2)==0)
		{
			switch(opciones)
			{
			case 1:
				if(i<CANT_CENSISTAS)
				{
					valor=retornarLegajoAuto(censista,i);
					i++;
				}
				if(i==CANT_CENSISTAS)
				{
					i=0;
				}
				posicion=(vivienda_buscarPosicionVacia(vivienda,CANT_VIVIENDAS));
				if(posicion>=0)
				{
					if(vivienda_pedirCargarDatos(vivienda,id,posicion,valor)==0)
					{
						id++;
						flag=-1;
						printf("\nSe cargó la vivienda\n\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				if(validarFlag(flag,-1,0,"\nERROR. Asegurese de ingresar datos")==0
				&& utn_getNumero(&idAModicar, "\nIngrese un ID: (+20000): ", "\nERROR.Intente nuevamente", 20000, 20500, 3)==0
				&& vivienda_modificarPorId(vivienda, CANT_VIVIENDAS,idAModicar)==0)
				{
					printf("\nSe modificó correctamente\n");
				}
				else
				{
					printf("\nNo se encontraron coincidencias");
				}
				break;
			case 3:
				if(validarFlag(flag,-1,0,"\nERROR. Asegurese de ingresar datos")==0
				&& utn_getNumero(&idADarBaja, "\nIngrese un ID: (+20000): ", "\nERROR.Intente nuevamente", 20000, 20500, 3)==0
				&& vivienda_darDeBaja(vivienda, CANT_VIVIENDAS,idADarBaja)==0)
				{
					printf("\nSe dió de baja correctamente\n");
				}
				else
				{
					printf("\nNo se encontraron coincidencias");
				}
				break;
			case 4:
				if(validarFlag(flag,-1,0,"\nERROR. Asegurese de ingresar datos")==0)
				{
					cant=vivienda_contarPosicionesLlenas(vivienda,CANT_VIVIENDAS);
					if(vivienda_ordenar(vivienda, cant, CALLE_LEN)!=-1
					&& vivienda_imprimirTodos(vivienda,cant)==0)
					{
							continue;
					}
				}
				break;
			case 5:
				printf("\n------DATOS CENSISTAS-------");
				if(censista_imprimirDatos(censista,3)==0)
				{
					break;
				}
				break;
			case 6:
				for(int i=0;i<CANT_CENSISTAS;i++)
				{
					if(censista_mostrarPosicionIndividual(censista,i)==0)
					{
						legajo=retornarLegajoAuto(censista, i);
					}
					if(legajo>=100)
					{
						if(vivienda_imprimirPorLegajo(vivienda,CANT_VIVIENDAS,legajo)==0)
						{
							continue;
						}
					}
					else
					{
						printf("No se obtuvo legajo");
					}
				}

				break;
			case 7:
				break;
			}
		}
		seguir='s';
	} while(seguir);

	return EXIT_SUCCESS;
}
