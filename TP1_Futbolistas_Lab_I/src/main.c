#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "jugadores.h"
#include "mantenimiento.h"
#include "posiciones.h"
#include "controller.h"
#include "confederaciones.h"
#include "promedios.h"
#define CANT_JUGADORES 22

int main(void)
{
	setbuf(stdout, NULL);

	int opcion = 0;
	Mantenimiento precios;
	Posiciones posiciones;
	Jugadores jugadores;
	Confederacion confederacion;
	Promedio promedios;
	InicializarCostos(&precios);
	inicializarPosiciones(&posiciones);
	conf_initConfederacion(&confederacion);

	do
	{
		switch(opcion = ImprimirMenu(&precios,&posiciones))
		{
			case 1:
				mant_MostrarSubMenuMantenimiento(&precios);
				break;
			case 2:
				ingresarJug(&jugadores, &posiciones, &confederacion);
				break;
			case 3:
				controller_calcularPromJug(&confederacion, &promedios);
				break;
			case 4:
				controller_imprimirValores(&promedios);
				break;
			case 5:
				printf("\nCerrando sesión");
				break;
		}
	} while(opcion != 5);
	return 0;
}

