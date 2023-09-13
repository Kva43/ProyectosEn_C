#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "validaciones.h"
#include "Seleccion.h"

int menu(void);
int sub_menu();

int main()
{
	setbuf(stdout,NULL);
    int option;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    int flagCargaCsv = -1;
    int flagAltaJug = -1;

    int respuesta; //case 5

    //case 6
    Jugador* pJugadorAux;
    int idSeleccionAux = 0;
    int idNuevoSeleccion;
    int idJugadorNoConvocado;
    int flagJugConvocados = -1;  //si esta en -1, no me deja ejecutar la funcion "controller_listarJugadoresConvocados"
    int queConvoca;
    int idJugadorConvocado;
    int idSeleccionAuxDos = -1;
    Seleccion* pSeleccionAux;
    do
    {
        switch(option = menu())
        {
		case 1:
			//verifico que se cargue solo una vez(jugadores.csv) los archivos
			if(flagCargaCsv == -1)
			{
				if(controller_cargarPelisDesdeTexto("jugadores.csv",listaJugadores) == 0 &&
				   controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones) == 0)
				{
					printf("\nSe cargó los datos de la lista.\n");
					flagCargaCsv = 0;
				}
			}
			else
				printf("\nLos datos del archivo ya fueron cargados.\n");
			break;
		case 2:
			if(controller_agregarJugador(listaJugadores) == 0)
			{
				printf("\nSe cargo el jugador.\n");
				flagAltaJug = 0;
			}
			else
				printf("\nNo se pudo cargar el jugador.");
			break;
		case 3:
			if(flagCargaCsv == 0 || flagAltaJug == 0)
			{
				controller_editarJugador(listaJugadores);
			}
			else
				printf("\nNo hay jugadores cargados en el sistema. Intente nuevamente...\n");
			break;
		case 4:
			if(flagCargaCsv == 0 || flagAltaJug == 0)
			{
				controller_removerJugador(listaJugadores);
			}
			else
				printf("\nNo hay jugadores cargados en el sistema. Intente nuevamente...\n");
			break;
		case 5:
			if(flagCargaCsv == 0 || flagAltaJug == 0)
			{
				respuesta = sub_menu();
				switch(respuesta)
				{
				case 1:
					controller_listarJugadores(listaJugadores);
					break;
				case 2:
					controller_listarSelecciones(listaSelecciones);
					break;
				case 3:
					if(flagJugConvocados == 0)
						controller_listarJugadoresConvocados(listaJugadores);
					else
						printf("\nTodavia no se hay jugadores convocados. Convoque alguno...\n");
					break;
				}
			}
			else
				printf("\nNo hay jugadores cargados en el sistema. Intente nuevamente...\n");
			break;
		case 6:
			if(flagCargaCsv == 0 || flagAltaJug == 0)
			{
				if(utn_getNumero(&queConvoca, "\n1. Convocar jugador\n2. Desconvocar", "\nError. Opcion invalida.", 1, 2, 2) == 0)
				{
					if(queConvoca == 1)
					{
						do
						{
							controller_listarJugadoresNoConvocados(listaJugadores);
							if(idSeleccionAux != 0)
							{
								printf("\nEse jugador ya fue convocado. Intentelo nuevamente: \n");
							}
							utn_getNumero(&idJugadorNoConvocado, "\nElija un jugador: ", "\nError. Intentelo de nuevamente.", 1, ll_len(listaJugadores), 2);
							pJugadorAux = searchID(listaJugadores, idJugadorNoConvocado);
							jug_getIdSeleccion(pJugadorAux, &idSeleccionAux);
						} while(idSeleccionAux != 0);

						controller_listarSelecciones(listaSelecciones);
						if(utn_getNumero(&idNuevoSeleccion, "\nElija una seleccion: ", "\nError. Intentelo de nuevamente.", 1, 32, 2) == 0)
						{
							pSeleccionAux = searchIDSeleccion(listaSelecciones, idNuevoSeleccion);
							selec_setConvocados(pSeleccionAux, 1);
							flagJugConvocados = 0;
							jug_setIdSeleccion(pJugadorAux, idNuevoSeleccion);
						}
					}
					else
					{
						do
						{
							controller_listarJugadoresConvocados(listaJugadores);
							if(idSeleccionAuxDos == 0)
							{
								printf("\nEse jugador ya esta desconvocado. Intentelo nuevamente: \n");
							}
							if(utn_getNumero(&idJugadorConvocado, "\nElija un jugador: ", "\nError. Intentelo de nuevamente.", 1, ll_len(listaJugadores), 2) == 0)
							{
								pJugadorAux = searchID(listaJugadores, idJugadorConvocado);
								jug_getIdSeleccion(pJugadorAux, &idSeleccionAuxDos);
							}
						} while(idSeleccionAuxDos == 0);
						pSeleccionAux = searchIDSeleccion(listaSelecciones, idSeleccionAuxDos);
						selec_setConvocados(pSeleccionAux, 0);
						jug_setIdSeleccion(pJugadorAux, 0);
						printf("\nEl jugador fue desconvocado correctamente.");
					}
				}
				break;
			}
			else
				printf("\nNo hay jugadores cargados en el sistema. Intente nuevamente...\n");
			break;
		case 7:
			controller_ordenarJugadores(listaJugadores, listaSelecciones);
			break;
		case 8:
			if(controller_guardarJugadoresModoBinario("data.bin" , listaJugadores) == 0)
				printf("\nSe guardó correctamente.");
			break;
		case 9:
			break;
		case 10:
			if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) == 0 &&
					controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones) == 0)
			{
				printf("\nSe guardó correctamente.");
			}
			break;
		case 11:
			printf("\nCerrando sesión...");
			break;
        }
    } while(option != 11);
    ll_deleteLinkedList(listaJugadores);
    return 0;
}

int menu(void)
{
	int opcion;
	int retorno = -1;
	if(utn_getNumero(&opcion,
			"\n=========================================\n"
			"|     Menu Principal    		|\n"
			"|  1   Carga de archivos		|\n"
			"|  2   Alta jugador			|\n"
			"|  3   Modificar jugador		|\n"
			"|  4   Dar de baja			|\n"
			"|  5   Listar				|\n"
			"|  6   Convocar jugador 		|\n"
			"|  7   Ordenar y listar			|\n"
			"|  8   Generar archivo binario		|\n"
			"|  9   Cargar archivo binario		|\n"
			"|  10  Guardar archivo .csv		|\n"
			"|  11 	Salir				|\n"
			"=========================================\n"
			,"\nERROR. Ingrese un numero del 1 al 5\n",1,11,2) == 0)
	{
		retorno = opcion;
	}
	return retorno;
}


int sub_menu()
{
	int respuesta = -1;
	utn_getNumero(&respuesta, "\nListar: \n1. Todos los jugadores\n2. Todas las selecciones\n3. Jugadores convocados\n", "\nError\n", 1, 3, 2);
	return respuesta;
}
