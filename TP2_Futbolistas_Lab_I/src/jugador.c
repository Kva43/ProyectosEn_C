#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"
#include "confederacion.h"

#include "validaciones.h"
#include "string.h"
#define CHAR_LEN 50

void menu_escribirCabezal(void)
{
	printf("=========================================================================================================\n");
	printf("| ID |   NOMBRE         | POSICION   | N° CAMISETA | SUELDO     |  CONFEDERACION   |  AÑOS de CONTRATO  |\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
}

int initArrayJug(eJugador* pStruct, int cant)
{
	int retorno = -1;
	if(pStruct != NULL && cant > 0)
	{
		for(int i = 0; i < cant; i++)
		{
			pStruct[i].isEmpty = 0;
		}
		retorno = 0;
	}
	return retorno;
}


