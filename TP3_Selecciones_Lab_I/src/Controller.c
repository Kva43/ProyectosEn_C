#include <stdio.h>
#include <stdlib.h>
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Jugador.h"
#include "string.h"
#include "validaciones.h"

#define NOMBRE_LEN 100
#define POSICION_LEN 30
#define NACIONALIDAD_LEN 30

static void switchear(int num, char* pAEscribir);
static int ordenarPorNacionalidad(void* a, void* b);static int ordenarPorEdad(void* a, void* b);
static int ordenarConfederacionPorNombre(void* a, void* b);
static int ordenarJugPorNombre(void* a, void* b);

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarPelisDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile = NULL;
	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path,"r"); //fopen retorna puntero
		if(pFile != NULL)
		{
			if(parser_PelisFromText(pFile, pArrayListJugador) == 0)
			{
				retorno = 0;
			}
		}
		else
			printf("\nNo se pudo abrir el archivo");
	}
	//fclose tiene que estar fuera de else, no sé porqué xD
	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int todoOk  = 0;
	FILE* p;

	if(path != NULL && pArrayListJugador != NULL)
	{
		p = fopen(path,"r");
		if(p == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if(parser_JugadorFromBinary(p,pArrayListJugador))
			{
				printf("Carga de archivo de texto exitosa\n");
				todoOk = 1;
			}
		}
	}
	fclose(p);
	return todoOk;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* b = NULL;
	//creo buffer
	int id = ll_len(pArrayListJugador);
	char nombre[100], posicion[30], nacionalidad[30];
	int edad;
	char mensajeError[30] = "\nError. Datos invalidos";

	if(pArrayListJugador != NULL && id >= 0)
	{
		//pido datos
		if( utn_getAlfanumerica(nombre, 100, "\nNombre: ", mensajeError, 2) == 0 &&
			utn_getNumero(&edad, "\nEdad: ", mensajeError, 16, 40, 2) == 0 &&
			utn_getAlfanumerica(posicion, 30, "\nPosicion: ", mensajeError, 2) == 0 &&
			utn_getAlfanumerica(nacionalidad, 30, "\nNacionalidad: ", mensajeError, 2) == 0)
		{
			//pido memoria dinamica
			b = jug_new();
			if(b != NULL)
			{
				if(id == 0)
					id = 371;
				else
					id++;
				//setteo en "(Jugador*) b"
				if( peli_setId(b, id) == 0 &&
					peli_setTitulo(b, nombre) == 0 &&
					peli_setDuracion(b, edad) == 0 &&
					peli_setGenero(b, posicion) == 0 &&
					jug_setNacionalidad(b, nacionalidad) == 0 &&
					jug_setIdSeleccion(b, 0) == 0)
				{
					//agrego a mi LinkedList "b"
					if(ll_add(pArrayListJugador, b) == 0)
					{
						retorno = 0;
					}

				}
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int idPasajero;
	char nombre[50], posicion[15],nacionalidad[30];
	int edad;
	char mensajeError[50] = "\nError. Intentelo nuevamente.";
	Jugador* pJugador = NULL;
	int opcion;

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		if(utn_getNumero(&idPasajero, "\nIngrese un ID: ", mensajeError, 1, ll_len(pArrayListJugador), 2) == 0)
		{
			pJugador = searchID(pArrayListJugador, idPasajero);		//recibe el ID ingresado por el usuario, y me devuelve puntero a jugador donde coincida IDs
			if(pJugador != NULL)
			{
				utn_getNumero(&opcion,"\nCampo a modificar\n"
											"1. Nombre\n"
											"2. Edad\n"
											"3. Posicion\n"
											"4. Nacionalidad\n", mensajeError, 1, 4, 2);
				switch(opcion) {
				case 1:
					if(utn_getAlfanumerica(nombre, 50, "\nNombre: ", mensajeError, 2) == 0 &&
					peli_setTitulo(pJugador, nombre) == 0)
						retorno = 0;
					break;
				case 2:
					if(utn_getNumero(&edad, "\nEdad: ", mensajeError, 16, 40, 2) == 0 &&
					peli_setDuracion(pJugador, edad) == 0)
						retorno = 0;
					break;
				case 3:
					if(utn_getAlfanumerica(posicion, 30, "\nPosicion: ", mensajeError, 2) == 0 &&
					peli_setGenero(pJugador, posicion) == 0)
						retorno = 0;
					break;
				case 4:
					if(utn_getAlfanumerica(nacionalidad, 30, "\nNacionalidad: ", mensajeError, 2) == 0 &&
					jug_setNacionalidad(pJugador, nacionalidad) == 0)
						retorno = 0;
					break;
				}
			}
			else
				printf("\nNo se encontró al jugador");
		}
	}
	return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int idPasajero;
	Jugador* pJugador = NULL;
	char mensajeError[7] = "\nERROR";

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		if(utn_getNumero(&idPasajero, "\nID a dar de baja: ", mensajeError, 0, ll_len(pArrayListJugador), 2) == 0)
		{
			pJugador = searchID(pArrayListJugador, idPasajero);
			ll_remove(pArrayListJugador,ll_indexOf(pArrayListJugador, pJugador));
		}
	}
	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int id,edad,idSeleccion = 0;
	char nombre[NOMBRE_LEN],posicion[POSICION_LEN],nacionalidad[NACIONALIDAD_LEN];
	Jugador* b;
	char dirAEscribir[30];

	if(pArrayListJugador != NULL)
	{
		menu_escribirCabezal();
		for(int i = 0; i < ll_len(pArrayListJugador) ;i++)
		{
			b = ll_get(pArrayListJugador, i);

			if(b != NULL)
			{
				if( peli_getId(b, &id) == 0 &&
					peli_getTitulo(b, nombre) == 0 &&
					peli_getDuracion(b, &edad) == 0 &&
					peli_getGenero(b, posicion) == 0 &&
					jug_getNacionalidad(b, nacionalidad) == 0 &&
					jug_getIdSeleccion(b, &idSeleccion) == 0)
				{
					switchear(idSeleccion, dirAEscribir);
					retorno = 0;
					printf(" %-5d %-25s %-5d %-22s %-18s %-15s \n",id,nombre,edad,posicion,nacionalidad, dirAEscribir);
				}
			}
		}
	}
	return retorno;
}

static void switchear(int num, char* pAEscribir)
{
	switch(num)
	{
	case 0:
		strcpy(pAEscribir, "No convocado");
		break;
	case 1:
		strcpy(pAEscribir, "Alemania");
		break;
	case 2:
		strcpy(pAEscribir, "Arabia Saudita");
		break;
	case 3:
		strcpy(pAEscribir, "Argentina");
		break;
	case 4:
		strcpy(pAEscribir, "Australia");
		break;
	case 5:
		strcpy(pAEscribir, "Belgica");
		break;
	case 6:
		strcpy(pAEscribir, "Brasil");
		break;
	case 7:
		strcpy(pAEscribir, "Camerun");
		break;
	case 8:
		strcpy(pAEscribir, "Canada");
		break;
	case 9:
		strcpy(pAEscribir, "Corea del Sur");
		break;
	case 10:
		strcpy(pAEscribir, "Costa Rica");
		break;
	case 11:
		strcpy(pAEscribir, "Croacia");
		break;
	case 12:
		strcpy(pAEscribir, "Dinamarca");
		break;
	case 13:
		strcpy(pAEscribir, "Ecuador");
		break;
	case 14:
		strcpy(pAEscribir, "Espana");
		break;
	case 15:
		strcpy(pAEscribir, "Estados Unidos");
		break;
	case 16:
		strcpy(pAEscribir, "Francia");
		break;
	case 17:
		strcpy(pAEscribir, "Gales");
		break;
	case 18:
		strcpy(pAEscribir, "Ghana");
		break;
	case 19:
		strcpy(pAEscribir, "Holanda");
		break;
	case 20:
		strcpy(pAEscribir, "Inglaterra");
		break;
	case 21:
		strcpy(pAEscribir, "Iran");
		break;
	case 22:
		strcpy(pAEscribir, "Japon");
		break;
	case 23:
		strcpy(pAEscribir, "Marruecos");
		break;
	case 24:
		strcpy(pAEscribir, "Mexico");
		break;
	case 25:
		strcpy(pAEscribir, "Polonia");
		break;
	case 26:
		strcpy(pAEscribir, "Portugal");
		break;
	case 27:
		strcpy(pAEscribir, "Qatar");
		break;
	case 28:
		strcpy(pAEscribir, "Senegal");
		break;
	case 29:
		strcpy(pAEscribir, "Serbia");
		break;
	case 30:
		strcpy(pAEscribir, "Suiza");
		break;
	case 31:
		strcpy(pAEscribir, "Tunez");
		break;
	case 32:
		strcpy(pAEscribir, "Uruguay");
		break;
	}
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListaSeleccion)
{
	int retorno = -1;
	int opcion;
	char mensajeError[100] = "Error. Elija una opcion del 1 al 4.";
	//1 es de menor a mayor, 0 es de mayor a menor en ll_sort
	if (pArrayListJugador != NULL && pArrayListaSeleccion != NULL)
	{
		if(utn_getNumero(&opcion, "\nOrdenar por:\n1. Nacionalidad\n2. Confederacion\n3. Edad\n4. Nombre", mensajeError, 1, 4, 2) == 0)
		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListJugador, ordenarPorNacionalidad, 1);
				controller_listarJugadores(pArrayListJugador);
				retorno = 0;
				break;
			case 2:
				controller_ordenarSelecciones(pArrayListaSeleccion);
				controller_listarSelecciones(pArrayListaSeleccion);
				break;
			case 3:
				ll_sort(pArrayListJugador, ordenarPorEdad, 1);
				controller_listarJugadores(pArrayListJugador);
				break;
			case 4:
				ll_sort(pArrayListJugador, ordenarJugPorNombre, 1);
				controller_listarJugadores(pArrayListJugador);
				break;
		}
	}
	return retorno;
}

static int ordenarPorNacionalidad(void* a, void* b)
{
	int retorno = 0;
	char auxA[30];
	char auxB[30];
	if(a != NULL && b != NULL)
	{
		jug_getNacionalidad(a, auxA);
		jug_getNacionalidad(b, auxB);
		retorno = strcmp(auxA, auxB);
	}
	return retorno;
}

static int ordenarConfederacionPorNombre(void* a, void* b)
{
	int retorno = 0;
	char auxA[30];
	char auxB[30];
	if(a != NULL && b != NULL)
	{
		selec_getConfederacion(a, auxA);
		selec_getConfederacion(b, auxB);
		retorno = strcmp(auxA, auxB);
	}
	return retorno;
}

static int ordenarPorEdad(void* a, void* b)
{
	int retorno = 0;
	int auxA;
	int auxB;
	if(a != NULL && b != NULL)
	{
		peli_getDuracion(a, &auxA);
		peli_getDuracion(b, &auxB);
		if(auxA > auxB)
			retorno = 1;
		else
			retorno = -1;
	}
	return retorno;
}

static int ordenarJugPorNombre(void* a, void* b)
{
	int retorno = 0;
	char auxA[100];
	char auxB[100];
	if(a != NULL && b != NULL)
	{
		peli_getTitulo(a, auxA);
		peli_getTitulo(b, auxB);
		retorno = strcmp(auxA, auxB);
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile;
	int id, edad, idSeleccion;
	char posicion[30], nacionalidad[30], nombre[100];
	//char idSeleccionChar[50];
	Jugador* jugadorAux;

	if (path != NULL && pArrayListJugador != NULL )
	{
		pFile = fopen(path, "w");
		if(pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

		for (int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugadorAux = ll_get(pArrayListJugador, i);
			if( peli_getId(jugadorAux, &id) == 0 &&
				peli_getTitulo(jugadorAux, nombre) == 0 &&
				peli_getDuracion(jugadorAux, &edad) == 0 &&
				peli_getGenero(jugadorAux, posicion) == 0 &&
				jug_getNacionalidad(jugadorAux, nacionalidad) == 0 &&
				jug_getIdSeleccion(jugadorAux, &idSeleccion) == 0)
			{
				//DECIDI NO CAMBIAR EL IdSeleccion (int) POR SU RESPECTIVA SELECCION (char)
				//para respetar el formato de solo numeros en el campo IdSeleccion
				//switchear(idSeleccion, idSeleccionChar);
				fprintf(pFile, "%d,%s,%d,%s,%s,%d\n",id,nombre,edad,posicion,nacionalidad,idSeleccion);
				retorno = 0;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile;
	Jugador* jugadorAux;
	int idSeleccion;
	int opcion;

	if (path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		if(utn_getNumero(&opcion, "\nElija una confederacion\n1. AFC\n2. CAF\n3. CONCACAF\n4. CONMEBOL\n5. UEFA", "\nError. Ingrese una opcion valida.", 1, 5, 2) == 0)
		switch(opcion)
		{
		case 1:
			for (int i = 0; i < ll_len(pArrayListJugador); i++)
			{
				jugadorAux = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugadorAux, &idSeleccion);
				if(jugadorAux != NULL && (idSeleccion == 2 || idSeleccion == 4 || idSeleccion == 9 || idSeleccion == 21 || idSeleccion == 22 || idSeleccion == 27))
				{
					fwrite(jugadorAux, sizeof(pArrayListJugador), 1, pFile);
					retorno = 0;
				}
			}
			break;
		case 2:
			for (int i = 0; i < ll_len(pArrayListJugador); i++)
			{
				jugadorAux = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugadorAux, &idSeleccion);
				if(jugadorAux != NULL && (idSeleccion == 7 || idSeleccion == 18 || idSeleccion == 23 || idSeleccion == 31))
				{
					fwrite(jugadorAux, sizeof(pArrayListJugador), 1, pFile);
					retorno = 0;
				}
			}
			break;
		case 3:
			for (int i = 0; i < ll_len(pArrayListJugador); i++)
			{
				jugadorAux = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugadorAux, &idSeleccion);
				if(jugadorAux != NULL && (idSeleccion == 8 || idSeleccion == 10 || idSeleccion == 15 || idSeleccion == 24))
				{
					fwrite(jugadorAux, sizeof(pArrayListJugador), 1, pFile);
					retorno = 0;
				}
			}
			break;
		case 4:
			for (int i = 0; i < ll_len(pArrayListJugador); i++)
			{
				jugadorAux = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugadorAux, &idSeleccion);
				if(jugadorAux != NULL && (idSeleccion == 3 || idSeleccion == 6 || idSeleccion == 13 || idSeleccion == 32))
				{
					fwrite(jugadorAux, sizeof(pArrayListJugador), 1, pFile);
					retorno = 0;
				}
			}
			break;
		case 5:
			for (int i = 0; i < ll_len(pArrayListJugador); i++)
			{
				jugadorAux = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugadorAux, &idSeleccion);
				if(jugadorAux != NULL && (idSeleccion == 1 || idSeleccion == 5 || idSeleccion == 11 || idSeleccion == 12 || idSeleccion == 14 || idSeleccion == 16 || idSeleccion == 17 || idSeleccion == 19 || idSeleccion == 20 || idSeleccion == 25 || idSeleccion == 26 || idSeleccion == 29 || idSeleccion == 30))
				{
					fwrite(jugadorAux, sizeof(pArrayListJugador), 1, pFile);
					retorno = 0;
				}
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pFile = NULL;
	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pFile = fopen(path,"r"); //este en modo read, porque sino crea un nuevo FILE y explota tod0
		if(pFile != NULL)
		{
			if(parser_SeleccionFromText(pFile, pArrayListSeleccion) == 0)
			{
				retorno = 0;
			}
		}
		else
			printf("\nNo se pudo abrir el archivo");
	}
	fclose(pFile);
	return retorno;
}

/** \brief Modificar datos de selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int id,convocados;
	char pais[NOMBRE_LEN],confederacion[POSICION_LEN];
	Seleccion* b;
	if(pArrayListSeleccion != NULL)
	{
		menu_escribirCabezalSeleccion();
		for(int i=0; i < ll_len(pArrayListSeleccion) ;i++)
		{
			b = ll_get(pArrayListSeleccion, i);
			if(b != NULL)
			{
				if( selec_getId(b, &id) == 0 &&
					selec_getPais(b, pais) == 0 &&
					selec_getConvocados(b, &convocados) == 0 &&
					selec_getConfederacion(b, confederacion) == 0)
				{
					retorno = 0;
					printf(" %-5d %-25s %-22s %-5d\n",id,pais, confederacion,convocados);

				}
			}
		}
	}
	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	if(pArrayListSeleccion != NULL)
	{
		ll_sort(pArrayListSeleccion, ordenarConfederacionPorNombre, 1);
		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	FILE* pFile;
	int id, convocados;;
	char pais[50], confederacion[50];
	Seleccion* seleccionAux;

	if (path != NULL && pArrayListSeleccion != NULL )
	{
		pFile = fopen(path, "w");
		if (pFile == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}

		fprintf(pFile, "id,pais,confederacion,convocados\n");

		for(int i = 0; i < ll_len(pArrayListSeleccion); i++)
		{
			seleccionAux = ll_get(pArrayListSeleccion, i);
			if( selec_getId(seleccionAux, &id) == 0 &&
				selec_getPais(seleccionAux, pais) == 0 &&
				selec_getConfederacion(seleccionAux, confederacion) == 0 &&
				selec_getConvocados(seleccionAux, &convocados) == 0)
			{
				fprintf(pFile, "%d,%s,%s,%d\n",id,pais,confederacion,convocados);
				retorno = 0;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int id,edad,idSeleccion = 0;
	char nombre[NOMBRE_LEN],posicion[POSICION_LEN],nacionalidad[NACIONALIDAD_LEN];
	Jugador* b;
	char dirAEscribir[30];

	if(pArrayListJugador != NULL)
	{
		menu_escribirCabezal();
		for(int i = 0; i < ll_len(pArrayListJugador) ;i++)
		{
			b = ll_get(pArrayListJugador, i);

			if(b != NULL)
			{
				if( peli_getId(b, &id) == 0 &&
					peli_getTitulo(b, nombre) == 0 &&
					peli_getDuracion(b, &edad) == 0 &&
					peli_getGenero(b, posicion) == 0 &&
					jug_getNacionalidad(b, nacionalidad) == 0 &&
					jug_getIdSeleccion(b, &idSeleccion) == 0)
				{
					if(idSeleccion != 0)
					{
						switchear(idSeleccion, dirAEscribir);
						retorno = 0;
						printf(" %-5d %-25s %-5d %-22s %-18s %-15s \n",id,nombre,edad,posicion,nacionalidad, dirAEscribir);
					}
				}
			}
		}
	}
	return retorno;
}

int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int id,edad,idSeleccion = 0;
	char nombre[NOMBRE_LEN],posicion[POSICION_LEN],nacionalidad[NACIONALIDAD_LEN];
	Jugador* b;
	char dirAEscribir[30];

	if(pArrayListJugador != NULL)
	{
		menu_escribirCabezal();
		for(int i = 0; i < ll_len(pArrayListJugador) ;i++)
		{
			b = ll_get(pArrayListJugador, i);

			if(b != NULL)
			{
				if( peli_getId(b, &id) == 0 &&
					peli_getTitulo(b, nombre) == 0 &&
					peli_getDuracion(b, &edad) == 0 &&
					peli_getGenero(b, posicion) == 0 &&
					jug_getNacionalidad(b, nacionalidad) == 0 &&
					jug_getIdSeleccion(b, &idSeleccion) == 0)
				{
					if(idSeleccion == 0)
					{
						strcpy(dirAEscribir, "No convocado");
						retorno = 0;
						printf(" %-5d %-25s %-5d %-22s %-18s %-15s \n",id,nombre,edad,posicion,nacionalidad, dirAEscribir);
					}
				}
			}
		}
	}
	return retorno;
}
