#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"
#include "controller.h"
#include "confederacion.h"
#include "validaciones.h"
#include "string.h"

int controller_Alta(eJugador* arrayJug, int cant, eConfederacion* arrayConf, int char_len)
{
	int retorno = -1;
	char mensajeError[50] = "\nHubo un error. Intentelo nuevamente: ";
	if(arrayJug != NULL && cant > 0)
	{
		for(int i = 0; i < cant; i++)
		{
			if(arrayJug[i].isEmpty == 0)
			{
				if(utn_getAlfanumerica(arrayJug[i].nombre,char_len,"\nNombre: ",mensajeError,2) == 0
				&& utn_getAlfanumerica(arrayJug[i].posicion,char_len,"\nPosicion: ",mensajeError,2) == 0
				&& utn_getNumero(&arrayJug[i].numeroCamiseta,"\nN°Camiseta: ",mensajeError, 0, 100,2) == 0
				&& utn_getNumeroFlotante(&arrayJug[i].salario,"\nSueldo: ",mensajeError, 0, 1000000,2) == 0
				//imprimir lista confederaciones(hardcodeadas)
				&& utn_getNumero(&arrayConf[i].id, "\n Confederaciones \n"
						"1 Conmebol\n"
						"2 UEFA\n"
						"3 AFC\n"
						"4 CAF\n"
						"5 CONCACAF\n"
						"6 OFC ", mensajeError, 1, 6, 2) == 0
				&& utn_getNumero(&arrayJug[i].aniosContrato,"\nAños contrato: ",mensajeError, 0, 25,2) == 0)
				{
					arrayConf[i].id += 99;
					arrayJug[i].id = i;
					arrayJug[i].isEmpty = -1;
					retorno = 0;
					break;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_listar(eJugador* arrayJug, int cant, int char_len, eConfederacion* arrayConf)
{
	int retorno = -1;
	char buffer[char_len];	//aca copia lo que me devuelve "modificarIdConf"
	if(arrayJug != NULL && cant > 0)
	{
		menu_escribirCabezal();

		for(int i = 0; i < cant; i++)
		{

			if(arrayJug[i].isEmpty == -1)
			{
				//Cambia, mediante un switch, el .idConfederacion de "eJugadores" por "conmebol", "uefa", etc
				modificarIdConf(arrayConf[i].id, buffer);
				//ID	NOMBRE	POS	N°CAM	SUELDO	CONFEDERA	AÑOSCONTRATO
				printf("| %-2d | %-16s | %-10s | %-10d | %-12.2f | %-20s | %-14d |\n",
													arrayJug[i].id,
													arrayJug[i].nombre,
													arrayJug[i].posicion,
													arrayJug[i].numeroCamiseta,
													arrayJug[i].salario,
													buffer,
													arrayJug[i].aniosContrato);
				printf("---------------------------------------------------------------------------------------------------------\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_darBaja(eJugador* arrayJug, int cant)
{
	int retorno = -1;
	int id;
	utn_getNumero(&id, "\nIngrese ID: ", "\n ERROR", 0, 3000, 2);
	for(int i = 0; i < cant; i++)
	{
		if(arrayJug[i].id == id && arrayJug[i].isEmpty == -1)
		{
			arrayJug[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}

int controller_modificarJug(eJugador* arrayJug, int cant, int char_len, eConfederacion* arrayConf)
{
	int retorno = -1;
	int opcion, valor, id, aniosContrato, numCamiseta;
	float salario;
	char nombre[30], posicion[30];
	controller_listar(arrayJug, cant,char_len, arrayConf);
	utn_getNumero(&id, "\nIngrese ID: ", "\n ERROR", 0, 3000, 2);
	for(int i = 0; i < cant; i++)
	{
		if(id == arrayJug[i].id && arrayJug[i].isEmpty == -1)
		{
			utn_getNumero(&opcion,
					"\nCampos modificables"
					"\n 1 Nombre"
					"\n 2 Posicion"
					"\n 3 N° camiseta"
					"\n 4 Confederacion"
					"\n 5 Salario"
					"\n 6 Años de contrato", "\n ERROR", 1, 6, 2);
			switch(opcion) {
			case 1:
				utn_getNombre(nombre, char_len,"\nNombre: ", "\n ERROR", 2);
				strcpy(arrayJug[i].nombre,nombre);
				break;
			case 2:
				utn_getNombre(posicion, char_len,"\nPosicion: ", "\n ERROR", 2);
				strcpy(arrayJug[i].posicion,posicion);
				break;
			case 3:
				utn_getNumero(&numCamiseta, "\nNumero camiseta: ", "\n ERROR", 0, 10, 2);
				arrayJug[i].numeroCamiseta = numCamiseta;
				break;
			case 4:
								utn_getNumero(&valor, "\n Confederaciones \n"
										"1 Conmebol\n"
										"2 UEFA\n"
										"3 AFC\n"
										"4 CAF\n"
										"5 CONCACAF\n"
										"6 OFC ", "\n ERROR", 1, 5, 2);
								switch(valor) {
								case 1:
									arrayConf[i].id = 100;
									retorno = 0;
									break;
								case 2:
									arrayConf[i].id = 101;
									retorno = 0;
									break;
								case 3:
									arrayConf[i].id = 102;
									retorno = 0;
									break;
								case 4:
									arrayConf[i].id = 103;
									retorno = 0;
									break;
								case 5:
									arrayConf[i].id = 104;
									retorno = 0;
									break;
								case 6:
									arrayConf[i].id = 105;
									retorno = 0;
									break;
								}
				break;
			case 5:
				utn_getNumeroFlotante(&salario, "\nSalario: ", "\n ERROR", 0, 1000000, 2);
				arrayJug[i].salario = salario;
				break;
			case 6:
				utn_getNumero(&aniosContrato, "\nAños contrato: ", "\n ERROR", 0, 25, 2);
				arrayJug[i].aniosContrato = aniosContrato;
				break;
			}
		}
	}
	return retorno;
}

int harcodearJugadores(eJugador* arrayJug,eConfederacion* arrayConf)
{
	int retorno = -1;
	arrayJug[0].id = 0;
	strcpy(arrayJug[0].nombre, "ariel");
	strcpy(arrayJug[0].posicion, "Delantero");
	arrayJug[0].numeroCamiseta = 7;
	arrayConf[0].id = 100;
	arrayJug[0].salario = 3241;
	arrayJug[0].aniosContrato = 12;
	arrayJug[0].isEmpty = -1;

	arrayJug[1].id = 1;
	strcpy(arrayJug[1].nombre, "bataglia");
	strcpy(arrayJug[1].posicion, "Defensor");
	arrayJug[1].numeroCamiseta = 4;
	arrayConf[1].id = 102;
	arrayJug[1].salario = 5314;
	arrayJug[1].aniosContrato = 2;
	arrayJug[1].isEmpty = -1;

	arrayJug[2].id = 2;
	strcpy(arrayJug[2].nombre, "caba");
	strcpy(arrayJug[2].posicion, "MedioCampo");
	arrayJug[2].numeroCamiseta = 5;
	arrayConf[2].id = 103;
	arrayJug[2].salario = 3241;
	arrayJug[2].aniosContrato = 1;
	arrayJug[2].isEmpty = -1;

	arrayJug[3].id = 3;
	strcpy(arrayJug[3].nombre, "danilo");
	strcpy(arrayJug[3].posicion, "Engache");
	arrayJug[3].numeroCamiseta = 23;
	arrayConf[3].id = 104;
	arrayJug[3].salario = 3241;
	arrayJug[3].aniosContrato = 4;
	arrayJug[3].isEmpty = -1;

	arrayJug[4].id = 4;
	strcpy(arrayJug[4].nombre, "faccio");
	strcpy(arrayJug[4].posicion, "Engache");
	arrayJug[4].numeroCamiseta = 43;
	arrayConf[4].id = 104;
	arrayJug[4].salario = 3241;
	arrayJug[4].aniosContrato = 4;
	arrayJug[4].isEmpty = -1;

	arrayJug[5].id = 5;
	strcpy(arrayJug[5].nombre, "garay");
	strcpy(arrayJug[5].posicion, "Engache");
	arrayJug[5].numeroCamiseta = 11;
	arrayConf[5].id = 104;
	arrayJug[5].salario = 3241;
	arrayJug[5].aniosContrato = 4;
	arrayJug[5].isEmpty = -1;

	arrayJug[6].id = 6;
	strcpy(arrayJug[6].nombre, "hugo");
	strcpy(arrayJug[6].posicion, "Engache");
	arrayJug[6].numeroCamiseta = 2;
	arrayConf[6].id = 104;
	arrayJug[6].salario = 3241;
	arrayJug[6].aniosContrato = 4;
	arrayJug[6].isEmpty = -1;

	arrayJug[7].id = 7;
	strcpy(arrayJug[7].nombre, "isla");
	strcpy(arrayJug[7].posicion, "Engache");
	arrayJug[7].numeroCamiseta = 6;
	arrayConf[7].id = 104;
	arrayJug[7].salario = 3241;
	arrayJug[7].aniosContrato = 4;
	arrayJug[7].isEmpty = -1;

	return retorno;
}

//////////////////////////////
////////INFORMES//////////////
/// //////////////////////////
int controller_informes(eJugador* arrayJugadores, int cantJug, eConfederacion* arrayConf)
{
	int retorno = -1;
	int orden, opcionInformes;

	utn_getNumero(&opcionInformes, "\n1 Listado jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador."
			"\n2 Listado confederaciones con sus jugadores."
			"\n3 Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
			"\n4 Informar la confederación con mayor cantidad de años de contratos total."
			"\n5 Informar porcentaje de jugadores por cada confederación."
			"\n6 Informar cual es la región con más jugadores y el listado de los mismos."
			, "\nERROR", 1, 6, 2);
	switch(opcionInformes)
	{
	case 1:
		utn_getNumero(&orden, "\n  Elija un orden"
								"\n 0 (DECRECIENTE)"
								"\n 1 (CRECIENTE)", "\nERROR", 0, 1, 2);
		ordenarNombres(arrayJugadores, cantJug, orden, arrayConf);
		retorno = 0;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	}
	return retorno;
}

int ordenarNombres(eJugador* arrayJug, int cant, int order, eConfederacion* arrayConf)
{
	int retorno = -1;
	eJugador buffer;
	if(arrayJug != NULL && cant > 0)
	{
		for(int i = 0; i < cant - 1; i++)
		{
			for(int j = i + 1; j < cant; j++)
			{
				if(arrayJug[i].isEmpty == -1 && arrayJug[j].isEmpty == -1)
				{
					if(order == 0)//decreciente
					{
						// )
						if( (strcmp(arrayConf[i].nombre,arrayConf[j].nombre) < 0 || strcmp(arrayConf[i].nombre,arrayConf[j].nombre) == 0) && (strcmp(arrayJug[i].nombre,arrayJug[j].nombre) < 0 || strcmp(arrayJug[i].nombre,arrayJug[j].nombre) == 0) )
						{
							buffer = arrayJug[i];
							arrayJug[i] = arrayJug[j];
							arrayJug[j] = buffer;
						}
					}
					else
					{
						if( (strcmp(arrayConf[i].nombre,arrayConf[j].nombre) > 0 || strcmp(arrayConf[i].nombre,arrayConf[j].nombre) == 0) && (strcmp(arrayJug[i].nombre, arrayJug[j].nombre) > 0 || strcmp(arrayJug[i].nombre,arrayJug[j].nombre) == 0) )
						{
							buffer = arrayJug[i];
							arrayJug[i] = arrayJug[j];
							arrayJug[j] = buffer;
						}
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
