#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "validaciones.h"
#include "cliente.h"
#include <string.h>

void menu_escribirCabezal(void);
//void menu_escribirCabezalTrabajos(void);
//void menu_escribirCabezalServicios(void);

int controller_altaCliente(Cliente* array, int cant)
{
	int retorno = -1;
	if(array != NULL && cant > 0)
	{
		for(int i = 0; i < cant; i++)
		{
			if(array[i].isEmpty == 0)
			{
				if( cliente_pedirNombre(array, i) == 0 &&
					cliente_pedirApellido(array, i) == 0 &&
					cliente_pedirDNI(array, i) == 0)
				{
					array[i].id = i;
					array[i].isEmpty = -1;
					break;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

void menu_escribirCabezal(void)
{
	printf("\n	  LISTA DE CLIENTES \n");
	printf("------------------------------------------------------------------------------------\n");
	printf("| ID |      DNI        |      NOMBRE       |      APELLIDO       |\n");
	printf("------------------------------------------------------------------------------------\n");
}

int controller_listarClientes(Cliente* array, int cant)
{
	int retorno = -1;
	if(array != NULL && cant > 0)
	{
		menu_escribirCabezal();
		for(int i = 0; i < cant; i++)
		{
			if(array[i].isEmpty == -1)
			{
				printf("  %-3d   %-20d %-20s %-20s\n",array[i].id, array[i].dni,array[i].nombre,array[i].apellido);
				printf("------------------------------------------------------------------------------------\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_listarClienteAlquileres(Cliente* array, Alquiler* arrayAlq, int cant)
{
	int retorno = -1;
	if(array != NULL && cant > 0)
	{
		menu_escribirCabezal();
		for(int i = 0; i < cant; i++)
		{
			if(array[i].isEmpty == -1)
			{
				if(arrayAlq[i].isEmpty == -1)
				{
					printf("  %-3d   %-20d %-20s %-20s %-20s\n",array[i].id, array[i].dni,array[i].nombre,array[i].apellido, arrayAlq[i].equipo);
					printf("------------------------------------------------------------------------------------\n");
				}
				else
				{
					printf("  %-3d   %-20d %-20s %-20s\n",array[i].id, array[i].dni,array[i].nombre,array[i].apellido);
					printf("------------------------------------------------------------------------------------\n");
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_modificarCliente(Cliente* array, int cant)
{
	int retorno = -1;
	int opcion, id;
	char nombre[50], apellido[50];
	char mensajeError[40] = "\nError. Ingrese un nombre valido";

	controller_listarClientes(array, cant);
	utn_getNumero(&id, "\nIngrese ID: ", "\n ERROR", 0, 19, 2);

	for(int i = 0; i < cant; i++)
	{
		if(id == array[i].id && array[i].isEmpty == -1)
		{
			utn_getNumero(&opcion, "\n1 Nombre\n2 Apellido", "\n ERROR", 1, 2, 2);
			switch(opcion) {
			case 1:
				utn_getAlfanumerica(nombre, 50, "\nIngrese nuevo nombre: ", mensajeError, 2);
				strcpy(array[i].nombre, nombre);
				retorno = 0;
				break;
			case 2:
				utn_getAlfanumerica(apellido, 50, "Ingrese nuevo apellido: ", mensajeError, 2);
				strcpy(array[i].apellido, apellido);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int controller_darBaja(Cliente* array, int cant)
{
	int retorno = -1;
	int id;
	controller_listarClientes(array, cant);
	utn_getNumero(&id, "\nIngrese ID: ", "\n ERROR", 1, cant, 2);
	for(int i = 0; i < cant; i++)
	{
		if(array[i].id == id && array[i].isEmpty == -1)
		{
			array[i].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

int controller_altaAlquiler(Alquiler* array, Cliente* arrayClientes, int cant)
{
	int retorno = -1;
	if(array != NULL && cant > 0)
	{
		controller_listarClientes(arrayClientes, cant);
		for(int i = 0; i < cant; i++)
		{
			if(array[i].isEmpty == 0)
			{
				if( alquiler_pedirCliente(array, i, cant) == 0 &&
					alquiler_pedirEquipo(array, i) == 0 &&
					alquiler_pedirTiempo(array, i) == 0 &&
					alquiler_pedirOperador(array, i) == 0)
				{
					array[i].isEmpty = -1;
					printf("\nEstado de %s: ALQUILADO", array[i].equipo);
					break;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_darBajaAlquiler(Cliente* array, Alquiler* arrayAlq, int cant)
{
	int retorno = -1;
	int id;
	controller_listarClienteAlquileres(array, arrayAlq, cant);

	utn_getNumero(&id, "\nIngrese ID: ", "\n ERROR", 0, cant, 2);
	for(int i = 0; i < cant; i++)
	{
		if(array[i].id == id && arrayAlq[i].isEmpty == -1 && array[i].isEmpty == -1)
		{
			arrayAlq[i].isEmpty = 0;
			printf("\nEstado de %s: FINALIZADO", arrayAlq[i].equipo);
			printf("\nTiempo real de uso: %d", rand() % 10 + 5);
			retorno = 0;
		}
	}
	return retorno;
}

/*
int controller_altaTrabajo(Moto* arrayMotos, int cantMotos, Trabajo* arrayTrabajo, Servicio* arrayServicio, int idIncremental)
{
	int retorno = -1;
	int id, num;
	controller_listarMotos(arrayMotos, cantMotos);
	utn_getNumero(&id, "\nIngrese ID: ", "\nERROR", 0, 19, 2);
	for(int i = 0; i < cantMotos; i++)
	{
		if(id == arrayMotos[i].id && arrayTrabajo[i].isEmpty == 0)
		{
			printf("\n1.Limpieza	2.Ajuste	3.Balanceo	4.Cadena");
			utn_getNumero(&num, "\nIngrese un servicio: ", "\nERROR", 1, 4, 2);
			switch(num)
			{
			case 1:
				arrayTrabajo[i].idIncremental = idIncremental;
				arrayTrabajo[i].idMoto = id;
				arrayTrabajo[i].idServicio = 20000;
				arrayServicio[i].idS = 20000;
				arrayServicio[i].precio = 450;
				arrayTrabajo[i].isEmpty = -1;
				arrayTrabajo[i].fecha.dia = (rand() % 30) + 1;
				arrayTrabajo[i].fecha.mes = (rand() % 11) + 1;
				arrayTrabajo[i].fecha.anio = (rand() % 7) + 2015;
				retorno = 0;
				break;
			case 2:
				arrayTrabajo[i].idIncremental = idIncremental;
				arrayTrabajo[i].idMoto = id;
				arrayTrabajo[i].idServicio = 20001;
				arrayServicio[i].idS = 20001;
				arrayServicio[i].precio = 300;
				arrayTrabajo[i].isEmpty = -1;
				arrayTrabajo[i].fecha.dia = (rand() % 30) + 1;
				arrayTrabajo[i].fecha.mes = (rand() % 11) + 1;
				arrayTrabajo[i].fecha.anio = (rand() % 7) + 2015;
				retorno = 0;
				break;
			case 3:
				arrayTrabajo[i].idIncremental = idIncremental;
				arrayTrabajo[i].idMoto = id;
				arrayTrabajo[i].idServicio = 20002;
				arrayServicio[i].idS = 20002;
				arrayServicio[i].precio = 150;
				arrayTrabajo[i].isEmpty = -1;
				arrayTrabajo[i].fecha.dia = (rand() % 30) + 1;
				arrayTrabajo[i].fecha.mes = (rand() % 11) + 1;
				arrayTrabajo[i].fecha.anio = (rand() % 7) + 2015;
				retorno = 0;
				break;
			case 4:
				arrayTrabajo[i].idIncremental = idIncremental;
				arrayTrabajo[i].idMoto = id;
				arrayTrabajo[i].idServicio = 20003;
				arrayServicio[i].idS = 20003;
				arrayServicio[i].precio = 390;
				arrayTrabajo[i].isEmpty = -1;
				arrayTrabajo[i].fecha.dia = (rand() % 30) + 1;
				arrayTrabajo[i].fecha.mes = (rand() % 11) + 1;
				arrayTrabajo[i].fecha.anio = (rand() % 7) + 2015;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int controller_imprimirTrabajos(Trabajo* arrayTrabajo, int cant, Moto* arrayMotos, Servicio* arrayServicio)
{
	int retorno = -1;
	char bufferServicio[CHAR_LEN];
	char bufferMoto[CHAR_LEN];
	if(arrayTrabajo != NULL && cant > 0)
	{
		menu_escribirCabezalTrabajos();
		for(int i = 0; i < cant; i++)
		{
			if(arrayTrabajo[i].isEmpty != 0)
			{
				modificarIdServicio(arrayTrabajo[i].idServicio, bufferServicio);
				modificarIdMoto(arrayTrabajo[i].idMoto, bufferMoto, arrayMotos, cant);
				printf(" %-3d %-17s%-12s   %-8.1f   %-2d/%-2d/%-4d\n",arrayTrabajo[i].idIncremental, bufferMoto,bufferServicio,arrayServicio[i].precio,arrayTrabajo[i].fecha.dia,arrayTrabajo[i].fecha.mes,arrayTrabajo[i].fecha.anio);
				printf("------------------------------------------------------------------------------------\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}
*/


//int controller_listarTiposDeMotos(Moto* arrayMotos, int cantMotos)
//{
//	int retorno = -1;
//	char bufferColor[MAX_CHAR];
//	char bufferTipo[MAX_CHAR];
//	int tipo;
//	if(arrayMotos != NULL && cantMotos > 0)
//	{
//		utn_getNumero(&tipo, "\nIngrese tipo de moto: 1.Enduro 2.Chopera 3.Scooter 4.Vintage", "\nERROR", 1, 4, 2);
//		menu_escribirCabezal();
//		for(int i = 0; i < cantMotos; i++)
//		{
//			if(arrayMotos[i].isEmpty == -1 && (arrayMotos[i].idTipo - 999) == tipo)
//			{
//				modificarIdColor(arrayMotos[i].idColor, bufferColor);
//				modificarIdTipo(arrayMotos[i].idTipo, bufferTipo);
//				printf(" %-3d  %-20s  %-9s  %-11s  %-11d  %-8d\n",arrayMotos[i].id, arrayMotos[i].marca,bufferTipo,bufferColor,arrayMotos[i].cilindrada,arrayMotos[i].puntaje);
//				printf("------------------------------------------------------------------------------------\n");
//			}
//		}
//		retorno = 0;
//	}
//	return retorno;
//}

//int controller_listarColoresDeMotos(Moto* arrayMotos, int cantMotos)
//{
//	int retorno = -1;
//	char bufferColor[MAX_CHAR];
//	char bufferTipo[MAX_CHAR];
//	int color;
//	if(arrayMotos != NULL && cantMotos > 0)
//	{
//		utn_getNumero(&color, "\nIngrese color de moto: 1.Gris 2.Negro 3.Azul 4.Blanco 5.Rojo", "\nERROR", 1, 5, 2);
//		menu_escribirCabezal();
//		for(int i = 0; i < cantMotos; i++)
//		{
//			if(arrayMotos[i].isEmpty == -1 && (arrayMotos[i].idColor - 9999) == color)
//			{
//				modificarIdColor(arrayMotos[i].idColor, bufferColor);
//				modificarIdTipo(arrayMotos[i].idTipo, bufferTipo);
//				printf(" %-3d  %-20s  %-9s  %-11s  %-11d  %-8d\n",arrayMotos[i].id, arrayMotos[i].marca,bufferTipo,bufferColor,arrayMotos[i].cilindrada,arrayMotos[i].puntaje);
//				printf("------------------------------------------------------------------------------------\n");
//			}
//		}
//		retorno = 0;
//	}
//	return retorno;
//}

//void menu_escribirCabezalTrabajos(void)
//{
//	printf("\n		***  LISTA DE TRABAJOS  ***\n");
//	printf("------------------------------------------------------------------------------------\n");
//	printf(" ID |     MOTO      |  SERVICIO  |  PRECIO  |   FECHA   |\n");
//	printf("------------------------------------------------------------------------------------\n");
//}



//int controller_promPuntajeDeTipo(Moto* arrayMotos, int cantMotos)
//{
//	int retorno = -1;
//	int tipo;
//	int sumaPuntajes = 0;
//	int cantDeEseTipo = 0;
//	float promedio;
//	if(arrayMotos != NULL && cantMotos > 0)
//	{
//		utn_getNumero(&tipo, "\nIngrese tipo de moto: 1.Enduro 2.Chopera 3.Scooter 4.Vintage", "\nERROR", 1, 4, 2);
//		menu_escribirCabezal();
//		for(int i = 0; i < cantMotos; i++)
//		{
//			if(arrayMotos[i].isEmpty == -1 && (arrayMotos[i].idTipo - 999) == tipo)
//			{
//				sumaPuntajes += arrayMotos[i].puntaje;
//				cantDeEseTipo++;
//				retorno = 0;
//			}
//		}
//		promedio = sumaPuntajes / cantDeEseTipo;
//		printf("\nPromedio de puntajes: %.2f",promedio);
//		retorno = 0;
//	}
//	return retorno;
//}



//int controller_imprimirTrabajosPorID(Trabajo* arrayTrabajo, int cant, Moto* arrayMotos, Servicio* arrayServicio, int idIncremental)
//{
//	int retorno = -1;
//	int id;
//	char bufferServicio[CHAR_LEN];
//	char bufferMoto[CHAR_LEN];
//	if(arrayTrabajo != NULL && cant > 0)
//	{
//		controller_listarMotos(arrayMotos, cant);
//		utn_getNumero(&id, "\nIngrese ID: ", "\nERROR", 0, 19, 2);
//		for(int i = 0; i < cant; i++)
//		{
//			if(arrayMotos[i].isEmpty == -1 && arrayMotos[i].id == id)
//			{
//				menu_escribirCabezalServicios();
//				harcodear_trabajo(arrayMotos, cant, arrayTrabajo, arrayServicio, idIncremental,i,id);
//				modificarIdServicio(arrayTrabajo[i].idServicio, bufferServicio);
//				modificarIdMoto(arrayTrabajo[i].idMoto, bufferMoto, arrayMotos, cant);
//				printf("   %-12s %-8.1f\n",bufferServicio,arrayServicio[i].precio);
//				printf("---------------------------\n");
//			}
//		}
//		retorno = 0;
//	}
//	return retorno;
//}

int controller_listar(Cliente* array, Alquiler* arrayAlq, int cant)
{
	int retorno = -1;
	int opcion;
	utn_getNumero(&opcion, "\n1 Asociado con más alquileres\n2 Equipo/s más alquilado/s y su cantidad\n3 El tiempo promedio real de alquiler\n4 Todos los clientes con sus alquileres.", "\nError", 1, 4, 2);
	switch(opcion)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		controller_listarClienteAlquileres(array, arrayAlq, cant);
		retorno = 0;
		break;
	}
	return retorno;
}

int menu()
{
	int opcion;
	printf("\n 		*** MENU ***  ");
	utn_getNumero(&opcion,"\n1 Alta cliente\n2 Modificar datos\n3 Baja\n4 Nuevo alquiler\n5 Fin del alquiler\n6 Informar","\nError, opcion incorrecta.\n", 1, 6, 2);
	return opcion;
}

