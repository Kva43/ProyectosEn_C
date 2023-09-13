#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "cliente.h"
#include "controller.h"
#include "alquiler.h"
#define CANT_CLIENTES 20

int main(void) {
	setbuf(stdout, NULL);
	int opcion = 0;

	Cliente arrayClientes[CANT_CLIENTES];
	Alquiler arrayAlquiler[CANT_CLIENTES];
//	Servicio arrayServicios[CANT_CLIENTES];

	//int idIncremental = 0;
	int flag = 0;
	char mensajeError[40] = "\nPrimero cargue una moto al sistema\n";

	if( initArrayClientes(arrayClientes, CANT_CLIENTES) == 0 &&
		initArrayAlquiler(arrayAlquiler, CANT_CLIENTES) == 0)
	{
		do {
			switch(opcion = menu()) {
			case 1:
				if(controller_altaCliente(arrayClientes, CANT_CLIENTES) == 0)
				{
					printf("\nSe cargó correctamente\n");
					flag = -1;
				}
				break;
			case 2:
				if(flag == -1 && controller_modificarCliente(arrayClientes, CANT_CLIENTES) == 0)
					printf("\nSe modificó correctamente");
				else
					printf(mensajeError);
				break;
			case 3:
				if(flag == -1 && controller_darBaja(arrayClientes, CANT_CLIENTES) == 0)
					printf("\nSe dió de baja");
				else
					printf(mensajeError);
				break;
			case 4:
				if(flag == -1 && controller_altaAlquiler(arrayAlquiler,arrayClientes, CANT_CLIENTES) == 0)
					printf("\n");
				else
					printf(mensajeError);
				break;
			case 5:
				if(flag == -1 &&  controller_darBajaAlquiler(arrayClientes, arrayAlquiler, CANT_CLIENTES) == 0)
					printf("\n");
				else
					printf(mensajeError);
				break;
			case 6:
				if(flag == -1 && controller_listar(arrayClientes, arrayAlquiler, CANT_CLIENTES) == 0)
					printf(" ");
				else
					printf(mensajeError);
				break;
			}
		} while(opcion != 0);
	}
	return 0;
}


