#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

#include "utn.h"

int menuOpcion()
{
	printf("  			///// MENU ////\n");
	int opcion;
	utn_getNumero(&opcion,"1. Cargar archivo\n"
			"2. Imprimir lista\n"
			"3. Asignar tiempos\n"
			"4. Guardar posiciones\n"
			"5. Salir\n","\nERROR",1,7,2);
	return opcion;
}

void menu_escribirCabezal(void)
{
	printf("                     		     ***Lista de Compras  ***\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
	printf(" ID | APELLIDO       | TIPO |  PROMEDIO  |  TIEMPO |\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
}
